#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const int MAXN = 200000;

vector <int> adj[MAXN];
vector <int> point, could(MAXN, -1);
vector <bool> aa(MAXN, false);

void bfs(int v) {
	queue <pii> q;
	q.push({v, 0});
	could[v] = 0;
	int d;
	while (q.size()) {
		tie(v, d) = q.front(); q.pop();
		for (int u : adj[v]) {
			if (could[u] == -1) {
				could[u] = d + 1;
				q.push({u, d + 1});
			} else if (could[u] == d + 1) {
				aa[u] = true;
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[v].pb(u);
	}
	int q;
	cin >> q;
	point.resize(q);
	fop (i,0,q) cin >> point[i], point[i]--;
	bfs(point.back());
	int minn = 0, maxx = 0;
	fop (i,0,q-1) {
		if (could[point[i]] < could[point[i+1]] + 1) {
			minn++;
			maxx++;
		} else if (aa[point[i]]) {
			maxx++;
		}
	}
	cout << minn << ' ' << maxx << endl;
}