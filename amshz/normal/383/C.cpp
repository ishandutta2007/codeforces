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
const int xn = 2e5+10;
const int xk = 320;

int a[xn], b[xn][2], start[xn], s = 1, n, m, r[xn], p[xn], h[xn], tb[xn];
vector <int> adj[xn];
bool mark[xn];

void DFS(int v, int d){
	mark[v] = true;
	tb[s] = v;
	start[v] = s++;
	r[v] = v;
	h[v] = d;
	
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		
		DFS(u, d+1);
		r[v] = r[u];
	}
}


int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> p[i];
	int v, u;
	for (int i=0; i<n-1; i++) cin >> v >> u, adj[v].pb(u), adj[u].pb(v);
	
	DFS(1, 0);
	
	for (int i=1; i<=n; i++) a[start[i]] = p[i];
	
	
	for (int i=0; i<m; i++){
		int t;
		cin >> t;
		if (t == 1){
			int v, val;
			cin >> v >> val;
			for (int i=start[v]; i<=start[r[v]];){
				if (i%xk == 0 && i+xk-1 <= start[r[v]]){
					b[i/xk][h[v]%2] += val;
					b[i/xk][!(h[v]%2)] -= val;
					i += xk-1;
					
				}
				else{
					if ((h[tb[i]] - h[v])%2 == 0) a[i] += val;
					else a[i] -= val;
				}
				i++;
			}
		}
		else{
			int v; cin >> v;
			cout << a[start[v]] + b[start[v]/xk][h[v]%2] << endl;
		}
	}
	
	return 0;
}