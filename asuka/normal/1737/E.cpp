#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 1e9 + 7;
int f[1000015], s[1000015], pw[1000015];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		f[n] = s[n] = 1;
		s[n + 1] = 0;
		pw[0] = 1;
		rep(i, 1, n + 1) pw[i] = (ll) pw[i - 1] * 2 % mod;

		auto ask = [&](int l, int r) {
			return (s[l] - s[r + 1] + mod) % mod;
		};

		per(i, 1, n - 1) {
			f[i] = ask(i + 1, min(n, i + i - 1));
			s[i] = (s[i + 1] + f[i]) % mod;
		}

		rep(i, 1, n) {
			int l = (i + 1) / 2, r = i, ans = (ll) f[i] * (pw[i - l] + mod) % mod;
			// printf("%d %d\n", f[i], pw[i - l]);
			ans = (ll) ans * qpow(pw[n - 1], mod - 2) % mod;
			cout << ans << '\n';
		}
	}

	return 0;
}