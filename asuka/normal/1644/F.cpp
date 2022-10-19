#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 2000015, mod = 998244353;

int inv[N], ifac[N], S[5005][5005];

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = (ll) a * a % mod) if (b & 1) res = (ll) res * a % mod;
	return res;
}

void prework(int n) {
	S[0][0] = 1;
	rep(i, 1, min(n, 5000)) {
		rep(j, 1, i) {
			S[i][j] = (S[i - 1][j - 1] + (ll) S[i - 1][j] * j % mod) % mod;
		}
	}
	rep(i, 1, min(n, 5000)) {
		S[i][1] = S[i][0] = 0;
		rep(j, 1, i) (S[i][j] += S[i][j - 1]) %= mod;
	}
	inv[0] = inv[1] = ifac[0] = 1;
	rep(i, 2, n) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	rep(i, 1, n) ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}

int F[N], G[N], tot, pri[N], mu[N];
bool notp[N];


void getG(int m, int n) {
	G[1] = 1;
	fill(notp + 1, notp + m + 1, 0); tot = 0;
	rep(i, 2, m) {
		if (!notp[i]) {
			pri[++tot] = i;
			G[i] = qpow(i, n);
		}
		for (int j = 1; j <= tot && i * pri[j] <= m; j++) {
			notp[i * pri[j]] = 1;
			G[i * pri[j]] = (ll) G[i] * G[pri[j]] % mod;
			if (i % pri[j] == 0) break;
		}
	}
}


int Stirling(int n, int k) {
	int m = min(n, k);
	if (n <= 5000) return S[n][m];
	rep(i, 0, m) F[i] = (ll) (i & 1 ? mod - ifac[i] : ifac[i]) % mod;
	rep(i, 1, m) {
		F[i] += F[i - 1];
		if (F[i] >= mod) F[i] -= mod;
	}
	getG(m, n);
	int res = 0;
	rep(i, 0, m) { // [2 - i, m - i]
		int o = F[m - i] + (2 - i > 0 ? mod - F[1 - i] : 0);
		if (o >= mod) o -= mod;
		res += (ll) o * ifac[i] % mod * G[i] % mod;
		if (res >= mod) res -= mod;
	}
	return res;
}

void getPri(int n) {
	mu[1] = 1;
	rep(i, 2, n) {
		if (!notp[i]) {
			pri[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * pri[j] <= n; j++) {
			notp[i * pri[j]] = 1;
			if (i % pri[j] == 0) {
				mu[i * pri[j]] = 0;
				break;
			}
			mu[i * pri[j]] = - mu[i];
		}
	}
}

int n, k;

int main() {
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
	cin >> n >> k;
	int ans = (n == 1 || k == 1);
	prework(n);
	getPri(n);
	rep(i, 1, n) {
		if (!mu[i]) continue;
		int m = (n + i - 1) / i;
		int res = Stirling(m, k);
		ans += mu[i] == -1 ? mod - res : res;
		if (ans >= mod) ans -= mod;
	}
	cout << ans << endl;
	return 0;
}