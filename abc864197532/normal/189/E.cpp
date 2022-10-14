#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 100087, logN = 17;

vector <int> adj[N];
int s, t, n;
vector <bool> is;
vector <int> dis;

bool ask(int k) {
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	dis.assign(n, 864197532);
	dis[s] = 0;
	pq.push({0, s});
	int v, d;
	while (pq.size()) {
		tie(d, v) = pq.top(); pq.pop();
		if (d > dis[v]) {
			continue;
		}
		if (is[v]) {
			dis[v] = 0;
		}
		if (dis[v] == k) {
			continue;
		}
		for (int u : adj[v]) if (dis[u] > dis[v] + 1) {
			if (u == t) return true;
			dis[u] = dis[v] + 1;
			pq.push({dis[u], u});
		}
	}
	return false;
}

int main () {
	int m, u, v, k;
	scanf("%d %d %d", &n, &m, &k);
	is.resize(n, false);
	fop (i,0,k) scanf("%d", &u), is[u - 1] = true;
	fop (i,0,m) {
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	scanf("%d %d", &s, &t);
	s--; t--;
	int l = 0, r = n + 20;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (ask(mid)) r = mid;
		else l = mid;
	}
	if (r == n + 20) cout << -1 << endl;
	else cout << r << endl;
}