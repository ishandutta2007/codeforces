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
const int x = 864197532, N = 200087, logN = 18;

vector <pair <int, long long>> adj[N];

struct Dijkstra {
	vector <long long> dis;
	vector <int> path;
	
	Dijkstra (int n) {
		dis.resize(n, LLONG_MAX);
		path.resize(n, -1);
	}
	
	void build_dis(int s) {
		priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair <long long, int>>> q;
		q.push({0, s});
		dis[s] = 0;
		long long d;
		int v;
		while (q.size()) {
			tie(d, v) = q.top(); q.pop();
			if (d > dis[v]) continue;
			for (auto i : adj[v]) {
				if (dis[i.first] > d + i.second) {
					dis[i.first] = d + i.second;
					path[i.first] = v;
					q.push({dis[i.first], i.first});
				}
			}
		}
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	lli w;
	fop (i,0,m) {
		cin >> u >> v >> w;
		adj[u].pb({v, w * 2});
		adj[v].pb({u, w * 2});
	}
	fop (i,1,n + 1) {
		cin >> w;
		adj[0].pb({i, w});
		adj[i].pb({0, w});
	}
	Dijkstra solver(n + 1);
	solver.build_dis(0);
	fop (i,1,n + 1) cout << solver.dis[i] << ' ';
	cout << endl;
}