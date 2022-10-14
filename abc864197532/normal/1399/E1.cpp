#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100000, logN = 17, K = 350;

vector <pii> adj[N];
priority_queue <pair <lli, pii>> pq;
lli all = 0;

int dfs(int v, int pa, int w) {
	int cnt = 0, is = 1;
	for (pii A : adj[v]) if (A.X != pa) {
		is = 0;
		cnt += dfs(A.X, v, A.Y);
	}
	cnt += is;
	pq.push({1ll * (w - w / 2) * cnt, mp(w, cnt)});
	all += 1ll * w * cnt;
	return cnt;
}

void solve() {
	int n, u, v, w;
	lli S;
	cin >> n >> S;
	fop (i,0,n - 1) {
		cin >> u >> v >> w; u--; v--;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	dfs(0, -1, 0);
	int ans = 0, cnt;
	while (all > S) {
		lli de = pq.top().X;
		tie(w, cnt) = pq.top().Y;
		pq.pop();
		all -= de;
		w /= 2;
		pq.push({1ll * (w - w / 2) * cnt, mp(w, cnt)});
		ans++; 
	}
	cout << ans << endl;
	fop (i,0,n) adj[i].clear();
	all = 0;
	while (pq.size()) pq.pop();
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