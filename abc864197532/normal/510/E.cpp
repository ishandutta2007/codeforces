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
#define pli pair<lli,int> 
#define X first
#define Y second
const int MAXV = 1000;
const long long INF = 1ll << 60;

struct Edge {
	int v, id;
	long long f;
	Edge(int _v, long long _f, int _id) : v(_v), id(_id), f(_f) {}
};

vector <Edge> adj[MAXV];
int level[MAXV];

void add_edge(int u, int v, long long f) {
	adj[u].push_back(Edge(v, f, adj[v].size()));
	adj[v].push_back(Edge(u, 0, adj[u].size() - 1));
}

bool bfs(int s, int t) {
	for (int i = 0; i < MAXV; ++i) level[i] = -1;
	queue <int> q;
	q.push(s);
	level[s] = 0;
	while (q.size()) {
		int v = q.front(); q.pop();
		for (Edge e : adj[v]) {
			if (e.f > 0 and level[e.v] == -1) {
				level[e.v] = level[v] + 1;
				q.push(e.v);
			}
		}
	}
	return level[t] != -1;
}

long long dfs(int v, long long minf, int t) {
	if (v == t) return minf;
	long long ans = 0;
	for (Edge &e : adj[v]) {
		if (e.f > 0 and level[e.v] == level[v] + 1) {
			long long nxtf = dfs(e.v, min(minf, e.f), t);
			ans += nxtf;
			minf -= nxtf;
			e.f -= nxtf;
			adj[e.v][e.id].f += nxtf;
			if (minf == 0) return ans;
		}
	}
	if (!ans) level[v] = -1;
	return ans;
}

long long runFlow(int s, int t) {
	long long ans = 0;
	while (bfs(s, t)) {
		ans += dfs(s, INF, t);
	}
	return ans;
}

int n;
vector <vector <int>> ans;
vector <bool> vis(210, false);
vector <int> input;

void dfs2(int v) {
	vis[v] = true;
	ans.back().push_back(v);
	for (Edge e : adj[v]) {
		if (input[v] & 1) {
			if (e.f == 0 and e.v < n and !vis[e.v]) dfs2(e.v);
		} else {
			Edge E = adj[e.v][e.id];
			if (E.f == 0 and e.v < n and !vis[e.v]) dfs2(e.v);
		}
	}
}

int main () {
    cin >> n;
    vector <int> prime(20200, 1);
    input.resize(n);
    fop (i,0,n) cin >> input[i];
    for (int i = 2; i * i < 20200; ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j < 20200; j += i) {
            prime[j] = 0;
        }
    }
    int s = n, t = n + 1;
    fop (i,0,n) {
        if (input[i] & 1) add_edge(s, i, 2);
        else add_edge(i, t, 2);
        fop (j,i+1,n) {
            if (prime[input[i] + input[j]]) {
                if (input[i] & 1) add_edge(i, j, 1);
                else add_edge(j, i, 1);
            }
        }
    }
    if (runFlow(s, t) != n) {
    	cout << "Impossible\n";
    	return 0;
	}
    for (int i = 0; i < n; ++i) {
    	if (!vis[i]) {
    		ans.push_back({});
    		dfs2(i);
		}
	}
	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v.size() << ' ';
		for (int i : v) {
			cout << i + 1 << ' ';
		}
		cout << endl;
	}
}