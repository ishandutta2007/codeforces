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

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 1e5+10;
const int xk = 2e5+10;

vector <int> adj[xn], b[xn];
int dis[xn], n, m, k, a[xn], s, t;
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	
	for (int i=0; i<b[v].size(); i++){
		int u = b[v][i];
		if (mark[u]) continue;
		
		DFS(u);
	}
}

bool check(int q){
	for (int v=1; v<=n; v++){
		b[v].resize(0);
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			if (dis[v] + dis[u] + 1 <= q) b[v].pb(u);
		}
	}
	for (int i=0; i<=n; i++) mark[i] = false;
	
	DFS(s);
	
	return mark[t];
}


int main(){
	fast_io;
	
	cin >> n >> m >> k;
	for (int i=0; i<k; i++) cin >> a[i];
	
	int v, u;
	for (int i=0; i<m; i++) cin >> v >> u, adj[v].pb(u), adj[u].pb(v);
	
	cin >> s >> t;
	
	for (int i=1; i<=n; i++) dis[i] = 1e9;
	
	queue <int> q;
	for (int i=0; i<k; i++) q.push(a[i]), dis[a[i]] = 0;
	q.push(t), dis[t] = 0;
	
	
	while (q.size()){
		int v = q.front();
		q.pop();
		
		for (int i=0; i<adj[v].size(); i++) {
			int u = adj[v][i];
			if (dis[u] < 1e9) continue;
			
			dis[u] = dis[v]+1, q.push(u);
		}
	}
	
	int l = 0, r = n+1, mid;
	
	while (r-l > 1){
		mid = (l+r)/2;
		
		if (check(mid)) r = mid;
		else l = mid;
	}
	
	if (r == n+1){
		cout << -1 << endl;
		return 0;
	}
	cout << r << endl;
	
	return 0;
}