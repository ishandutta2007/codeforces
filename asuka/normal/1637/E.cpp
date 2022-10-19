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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
const int B = 547, N = 3e5 + 5;
int t, n, m, cnt[N];
map<int, int> M;
bool invld[N];
vector<int> pos[N], S[B + 10];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		M.clear();
		vector<int> num;
		rep(i, 0, n) pos[i].clear();
		rep(i, 1, n) {
			int x;
			cin >> x;
			M[x]++;
		}
		vector<pii> vec, nvec;
		for (auto [x, y] : M) { // cnt_x, x
			num.pb(x);
			vec.emplace_back(y, SZ(num) - 1);
			cnt[SZ(num) - 1] = y;
		}
		sort(all(vec));
		rep(i, 1, m) {
			int x, y;
			cin >> x >> y;
			int px = lower_bound(all(num), x) - num.begin();
			int py = lower_bound(all(num), y) - num.begin();
			pos[py].pb(px); pos[px].pb(py);
		}
		ll ans = 0;
		cerr << "ok" << endl;
		for (auto [x, y] : vec) {
			if (x <= B) nvec.emplace_back(x, y);
			else {
				for (auto o : pos[y]) invld[o] = 1;
				rep (i, 0, SZ(num) - 1) {
					if (invld[i] || i == y) continue;
					ans = max(ans, (ll) (cnt[i] + cnt[y]) * (num[i] + num[y]));
				}
				for (auto o : pos[y]) invld[o] = 0;
			}
		}
		rep(i, 1, B) S[i].clear();
		for (auto [x, y] : nvec) {
			S[x].emplace_back(y);
		}
		rep(i, 1, B) sort(all(S[i]));
		for (auto [x, y] : nvec) {
			for (auto o : pos[y]) invld[o] = 1;
			rep(i, 1, B) {
				per(j, 0, SZ(S[i]) - 1) {
					int o = S[i][j];
					if (invld[o] || y == o) continue;
					ans = max(ans, (ll) (cnt[o] + cnt[y]) * (num[o] + num[y]));
					break;
				}
			}
			for (auto o : pos[y]) invld[o] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}