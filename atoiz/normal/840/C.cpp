#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second

const int MAXN = 307, MOD = 1e9 + 7;
int fact[MAXN], invfact[MAXN];
int A[MAXN], N;
array<array<int, MAXN>, MAXN> F;

int add(int a, int b) { return ((a += b) >= MOD ? a - MOD : a); }
int sub(int a, int b) { return ((a -= b) < 0 ? a + MOD : a); }
int mul(int a, int b) { return (int) ((ll) a * b % MOD); }
int bpow(int a, int p)
{
	int ans = 1;
    for (; p > 0; p >>= 1, a = mul(a, a)) {
        if (p & 1) {
			ans = mul(ans, a);
        }
    }
    return ans;
}
#define div div_
int div(int a, int b) { return mul(a, bpow(b, MOD - 2)); }
int nCk(int a, int b) { return mul(mul(invfact[b], invfact[a - b]), fact[a]); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1;
	FOR(i, 1, MAXN - 1) fact[i] = mul(fact[i - 1], i);
	invfact[MAXN - 1] = bpow(fact[MAXN - 1], MOD - 2);
	FORB(i, MAXN - 2, 0) invfact[i] = mul(invfact[i + 1], i + 1);

	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
        for (int j = 2; j * j <= A[i]; ++j) {
			while (A[i] % (j * j) == 0) A[i] /= j * j;
        }
	}
	sort(A + 1, A + 1 + N);

	int cur_x = 0, cur_cnt = 0;
    vector<int> cnt;
    FOR(i, 1, N + 1) {
		if (A[i] != cur_x) {
            if (cur_cnt) {
				cnt.push_back(cur_cnt);
            }
			cur_x = A[i];
			cur_cnt = 0;
		}
		++cur_cnt;
    }

    F[0][0] = 1;
    for (int i = 0; i < SZ(cnt); ++i) {
    	int x = cnt[i];
        for (int j = 0; j <= N; ++j) if (F[i][j]) {
            for (int k = 0; k < x; ++k) {
                F[i + 1][j + k] = add(F[i + 1][j + k], mul(F[i][j], mul(mul(fact[x], invfact[x - k]), nCk(x - 1, k))));
            }
        }
    }

	auto G = F[SZ(cnt)];
	int ans = 0;
	FOR(i, 0, N) if (G[i]) {
//		cout << i << ": " << G[i] << endl;
		if (i & 1) {
            ans = sub(ans, mul(G[i], fact[N - i]));
		} else {
			ans = add(ans, mul(G[i], fact[N - i]));
		}
	}

//	for (int x : cnt) ans = mul(ans, fact[x]);
	cout << ans << endl;
}