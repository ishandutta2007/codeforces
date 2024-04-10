#include <iostream>
#include <vector>

using namespace std;

const int MOD = (7 << 26) + 1, W = 3;

void add(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
void sub(int &a, int b) { add(a, MOD - b); }
void mul(int &a, int b) { a = 1ll * a * b % MOD; }
int qpow(int a, int p)
{
    int ans = 1;
    while (p) {
        if (p & 1) mul(ans, a);
        p >>= 1; mul(a, a);
    }
    return ans;
}
int inv(int a) { return qpow(a, MOD - 2); }
void dv(int &a, int b) { mul(a, inv(b)); }

void ntt(vector<int>& P, bool inv)
{
	int n = P.size();
    for (int i = 0, j = 0; i < n; ++i) {
        if (i < j) swap(P[i], P[j]);
        int x = n >> 1; for (; j & x; x >>= 1) j ^= x; j ^= x;
    }

    for (int k = 2; k <= n; k <<= 1) {
        for (int i = 0; i < (k >> 1); ++i) {
            int w = (inv) ? qpow(W, (MOD - 1) - (MOD - 1) / k * i) : qpow(W, (MOD - 1) / k * i);
            for (int j = i; j < n; j += k) {
                int x = P[j + (k >> 1)]; mul(x, w);
                P[j + (k >> 1)] = P[j]; sub(P[j + (k >> 1)], x);
                add(P[j], x);
            }
        }
    }

    if (inv) for (int i = 0; i < n; ++i) dv(P[i], n);
}

vector<int> A(1 << 20, 0);

int32_t main()
{
	int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) { int x; cin >> x; A[x] = 1; }
    ntt(A, 0);
    for (int i = 0; i < (int)A.size(); ++i) A[i] = qpow(A[i], k);
    ntt(A, 1);
    for (int i = 0; i < (int)A.size(); ++i) if (A[i]) cout << i << ' ';
}