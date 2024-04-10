#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
const int maxn = 5000;
const int mod = 998244353;
int T, n, m, a[maxn + 5], cnt[maxn + 5];
int f[maxn + 5], g[maxn + 5], lst[maxn + 5], inv[maxn + 5], ifac[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;} 
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline void upd(int &a, int b) {a = add(a, b);}
void init() {
	inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, maxn) inv[i] = mul(inv[mod % i], mod - mod / i);
	rep(i, 2, maxn) ifac[i] = mul(ifac[i - 1], inv[i]); 
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i], cnt[a[i]] ++;
		if(n == 2) {
			cout << (a[1] == a[2] ? 0 : 1) << '\n';
			rep(i, 1, n) cnt[i] = 0;
			continue;
		}
		if(a[n - 1] == a[n]) {
			cout << 0 << '\n';
			rep(i, 1, n) cnt[i] = 0;
			continue;
		}
		int p = 0; 
		rep(i, 1, n) {
			while(p < n && a[p + 1] < a[i]) p ++;
			lst[i] = p;
		}
		m = n / 2 - 1;
		rep(i, 0, n) f[i] = 1;
		rep(i, 1, m) {
			swap(f, g);
			rep(i, 0, n) f[i] = 0;
			rep(j, 1, n) {
				if(i == 1) f[j] = add(f[j - 1], mul(g[lst[j]], max(0ll, 1ll * lst[j] * (lst[j] - 1) % mod)));
				else f[j] = add(f[j - 1], mul(g[lst[j]], max(0, lst[j] - i + 1 - i)));
			}
		}
		int ans = f[n - 1];
		rep(i, 1, n) ans = mul(ans, ifac[cnt[i]]);
		cout << ans << '\n';
		rep(i, 1, n) cnt[i] = 0;
	}
	return 0;
}