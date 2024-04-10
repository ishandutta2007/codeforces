#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)

#define N 600007

struct Edge {
	// PRE: has to be bcc = -1 and bridge = 0 (constructors sets this)
	Edge* rev;
	int dest;
	int bcc; // OUT: number of biconnected Component
	bool bridge;    // OUT: is it a bridge                   // B
	Edge(int v) :
			dest(v), bcc(-1), bridge(0)                                 // B
	{
	}
};

int n; // IN: number of vertices
list<Edge> adj[N];      // IN: adjacency lists
int visit[N];
bool artp[N];  // OUT: is it an articulation point              // A
int bcc_num;   // OUT: number of biconnected Components         // C
int low[N];    // OUT: Low function                             // L

int nBcc[N];
vector<int> nAdj[N];

void add_edge(int a, int b) {
	adj[a].pb(Edge(b));
	adj[b].pb(Edge(a));
	adj[a].back().rev = &adj[b].back();
	adj[b].back().rev = &adj[a].back();
}
stack<Edge*> st; // C
int dfsTime;
int bccDFS(int v, bool root = 0) {
	int lo = visit[v] = ++dfsTime;
	FOREACH(it, adj[v])
	{
		if (it->bcc != -1)
			continue;
		st.push(&*it);                                          // C
		it->rev->bcc = -2;
		if (!visit[it->dest]) {
			int ulo = bccDFS(it->dest);
			lo = min(ulo, lo);
			it->bridge = it->rev->bridge = (ulo > visit[v]); // B
			if (ulo >= visit[v]) { // AC
				artp[v] = !root;
				root = 0; // A
				Edge* edge; // C
				do { // C
					edge = st.top();
					st.pop(); // C
					edge->bcc = edge->rev->bcc = bcc_num;       // C
					if (!edge->bridge)
						nBcc[edge->dest] = nBcc[edge->rev->dest] = bcc_num;
				} while (edge != &*it);                         // C
				++bcc_num;                                      // C
			}                                                   // AC
		} else
			lo = min(lo, visit[it->dest]);
	}
	low[v] = lo;
// L
	return lo;
}

void computeBCC() {
	fill(artp, artp + n + 1, 0);                                    // A
	fill(visit, visit + n + 1, 0);
	dfsTime = 1;
	bcc_num = 0;
// C
	FORI(i, n)
		if (!visit[i])
			bccDFS(i, 1);                            // maybe change FORI to FOR
}

int dfs(const int u, const int parent, int &ans) {
	sort(nAdj[u].begin(), nAdj[u].end());
	nAdj[u].erase(unique(nAdj[u].begin(), nAdj[u].end()), nAdj[u].end());

	vector<int> dp = { 0, 0 };
	for (const int &v : nAdj[u])
		if (v != parent && v != u) {
			const int res = dfs(v, u, ans);
			dp.push_back(res + 1);
		}
	nth_element(dp.rbegin(), dp.rend() - 2, dp.rend());
	sort(dp.begin(), dp.begin() + 2);
	ans = max(ans, dp[0] + dp[1]);
	return dp[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i <= N / 2 + 1; ++i)
		nBcc[i] = N / 2 + 2 + i;

	int m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}

	computeBCC();

	for (int i = 0; i <= n; ++i)
		for (auto &&x : adj[i])
			if (x.bridge) {
				const int u = nBcc[x.dest];
				const int v = nBcc[x.rev->dest];
				nAdj[u].push_back(v);
			}

	int ans = 0;
	for (int i = 0; i < N; ++i)
		if (!nAdj[i].empty()) {
			dfs(i, -1, ans);
			break;
		}
	cout << ans << endl;
	return 0;
}