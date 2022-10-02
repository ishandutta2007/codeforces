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
const int maxn = 2e5;
int n, m, s, vis[maxn + 5], lst[maxn + 5], pre[maxn + 5];
vector<int> g[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for(auto v : g[s]) {
		vector<int> node;
		auto getpath = [&] (auto self, int u, int lst) {
			if(u == s || pre[u]) return ;
			pre[u] = lst;
			for(auto v : g[u]) self(self, v, u);
		};
		auto print = [&] (int s1, int s2, int v) {
			cout << "Possible\n";
			rep(i, 1, n) pre[i] = 0;
			getpath(getpath, s1, s);
			vector<int> ans;
			int id = v;
			while(id != s1) ans.pb(id), id = pre[id];
			ans.pb(s1), ans.pb(s);
			reverse(all(ans));
			cout << sz(ans) << '\n';
			for(auto x : ans) cout << x << ' '; cout << '\n';
			rep(i, 1, n) pre[i] = 0;
			getpath(getpath, s2, s);
			ans.clear();
			id = v;
			while(id != s2) ans.pb(id), id = pre[id];
			ans.pb(s2), ans.pb(s);
			reverse(all(ans));
			cout << sz(ans) << '\n';
			for(auto x : ans) cout << x << ' '; cout << '\n';
			exit(0);
		};
		auto dfs = [&] (auto self, int u) {
			if(u == s || vis[u]) return ;
			node.pb(u);
			if(lst[u]) print(lst[u], v, u);
			else lst[u] = v;
			vis[u] = v;
			for(auto v : g[u]) self(self, v);
		};
		dfs(dfs, v);
		for(auto x : node) vis[x] = 0;
	}
	cout << "Impossible\n";
	return 0;
}