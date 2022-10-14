#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

vector <int> adj[N];
vector <bool> vis;
vector <int> cur;

void dfs(int v) {
	vis[v] = true;
	cur.pb(v);
	for (int u : adj[v]) if (!vis[u]) {
		dfs(u);
	}
}

void solve() {
	int n;
	cin >> n;
	int p[n], q[n];
	vector <int> cnt(n, 0);
	fop (i,0,n) cin >> p[i], p[i]--, cnt[p[i]]++;
	fop (i,0,n) cin >> q[i], q[i]--, cnt[q[i]]++;
	fop (i,0,n) {
		if (cnt[i] != 2) {
			cout << "-1\n";
			return;
		}
	}
	vis.assign(n, false);
	fop (i,0,n) {
		adj[p[i]].pb(q[i]);
		adj[q[i]].pb(p[i]);
	}
	int id_p[n], id_q[n];
	map <pii, int> m1;
	fop (i,0,n) id_p[p[i]] = i, id_q[q[i]] = i, m1[{p[i], q[i]}] = i;
	vector <int> ans;
	fop (i,0,n) if (!vis[i]) {
		dfs(i);
		if (cur.size() == 1) {
			cur.pop_back();
			continue;
		} 
		vector <int> a, b;
		fop (i,0,cur.size()) {
			int j = (i + 1) % cur.size();
			if (!m1.count({cur[i], cur[j]})) a.pb(m1[{cur[j], cur[i]}]);
		}
		reverse(all(cur));
		fop (i,0,cur.size()) {
			int j = (i + 1) % cur.size();
			if (!m1.count({cur[i], cur[j]})) b.pb(m1[{cur[j], cur[i]}]);
		}
		if (a.size() < b.size()) {
			for (int i : a) ans.pb(i + 1);
		} else {
			for (int i : b) ans.pb(i + 1);
		}
		cur.clear();
	}
	cout << ans.size() << endl;
	printv(ans);
	fop (i,0,n) adj[i].clear();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
	while (t--) {
		solve();
	}
}