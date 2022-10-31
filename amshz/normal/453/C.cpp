# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;
const int xn = 1e5+10;
const int xk = 1e2+10;

bool mark[xn], f[xn], a[xn];
vector <int> adj[xn], m[xn];
deque <int> ans;
int n, n2, g[xn], b[xn];

void DFS2(int v){
	mark[v] = true;
	ans.pb(v), b[v]++;
	
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		
		DFS2(u);
		
		ans.pb(v), b[v]++;
		if (b[u]%2 == !a[u]) ans.pb(u), ans.pb(v), b[u]++, b[v]++;
	}
	
}

void DFS(int v, int d){
	mark[v] = true;
	if (a[v]) f[d] = true;
	m[d].pb(v);
	g[v] = d;
	
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, d);
	}
}

int main(){
	
	cin >> n >> n2;
	int x, y;
	for (int i=0; i<n2; i++) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	for (int i=1; i<=n; i++) cin >> a[i];
	
	int t = 0;
	for (int i=1; i<=n; i++){
		if (mark[i]) continue;
		DFS(i, t);
		t++;
	}
	
	t = 0;
	int dx = 0;
	for (int i=0; i<n; i++){
		if (f[i]) t++, dx = i;
		if (t == 2){
			cout << -1 << endl;
			return 0;
		}
	}
	
	if (t == 0){
		cout << 0 << endl;
		return 0;
	}
	
	for (int i=0; i<=n; i++) mark[i] = false, f[i] = false;
	
	int d = m[dx][0];
	if (adj[d].size() == 0){
		cout << 1 << endl;
		cout << d << endl;
		return 0;
	}
	ans.pb(d), ans.pb(adj[d][0]);
	b[d]++, b[adj[d][0]]++;
	
	DFS2(d);
	
	for (int i=0; i<=n; i++) mark[i] = false;
	
	t = 0;
	for (int i=1; i<=n; i++) if (b[i]%2 != a[i]) t++, f[i] = true;
	
	if (t%2 == 1) f[ans.front()] = !f[ans.front()], b[ans.front()]--, ans.pop_front();
	
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i] << sep;
	cout << endl;
	
	
	return 0;
}