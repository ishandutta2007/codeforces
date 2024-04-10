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
const int N = 100000;
vector <int> adj[N];
bool isLeaf[N];
int depth[N], p[N];

void dfs(int v, int pa) {
	p[v] = pa;
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	for (int u : adj[v]) {
		if (u == pa) continue;
		dfs(u, v);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n - 1) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	int s = -1;
	fop (i,0,n) {
		isLeaf[i] = (adj[i].size() == 1);
		if (!isLeaf[i]) s = i;
	}
	dfs(s, -1);
	int ans = n - 1;
	int a = -1;
	bool is = true;
	set <int> now;
	fop (i,0,n) {
		if (isLeaf[i]) {
			if (now.count(p[i])) ans--;
			else now.insert(p[i]);
			if (~a and depth[i] % 2 != a) is = false;
			else a = depth[i] % 2;
		}
	}
	cout << (is ? 1 : 3) << ' ' << ans << endl;
}