#include <iostream>

using namespace std;

const int maxn = 2000007, mod = 1000000007;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return (long long) a * b % mod; }
int qpow(int a, int p)
{
    int ans = 1;
    while (p) {
		if (p & 1) ans = mul(ans, a);
        a = mul(a, a);
        p >>= 1;
    }
    return ans;
}

int n, m, fact[maxn], ifact[maxn], pown[maxn], powm[maxn];

int main()
{
	cin >> n >> m;

    fact[0] = 1; for (int i = 1; i < maxn; ++i) fact[i] = mul(fact[i-1], i);
    ifact[maxn-1] = qpow(fact[maxn-1], mod-2); for (int i = maxn-1; i > 0; --i) ifact[i-1] = mul(ifact[i], i);
    pown[0] = 1; for (int i = 1; i < maxn; ++i) pown[i] = mul(pown[i-1], n);
    powm[0] = 1; for (int i = 1; i < maxn; ++i) powm[i] = mul(powm[i-1], m);

    int ans = 0, cur;
    for (int p = 2; p <= n && p <= m+1; ++p) {
        cur = 1;

        cur = mul(cur, fact[n-2]);
        cur = mul(cur, ifact[n-p]);

        cur = mul(cur, fact[m-1]);
        cur = mul(cur, ifact[m-p+1]);
        cur = mul(cur, ifact[p-2]);

        cur = mul(cur, powm[n-p]);

        if (p < n) cur = mul(cur, mul(pown[n-p-1], p));
        ans = add(ans, cur);
    }

	cout << ans << endl;
}