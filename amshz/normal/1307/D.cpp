# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 2e5+10;
const int xm = 5e1+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

int n, m, k, dist[xn][2];
vector <int> adj[xn], vec;

bool cmp(int i, int j){
	return dist[i][0] < dist[j][0];
}


int main(){
	fast_io;
	
	cin >> n >> m >> k;
	int v, u;
	for (int i = 0; i < k; i++) cin >> v, vec.pb(v);
	for (int i = 0; i < m; i++){
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = -1;
	
	dist[1][0] = 0;
	queue <int> q;
	q.push(1);
	while (q.size()){
		v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (dist[u][0] != -1) continue;
			dist[u][0] = dist[v][0] + 1;
			q.push(u);
		}
	}
	dist[n][1] = 0;
	q.push(n);
	while (q.size()){
		v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (dist[u][1] != -1) continue;
			dist[u][1] = dist[v][1] + 1;
			q.push(u);
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	
	int ans = 0;
	
	//cout << dist[n] << endl;
	
	for (int i = 1; i < vec.size(); i++){
		int d = dist[vec[i]][0] - dist[vec[i - 1]][0];
		if (d == 0){
			cout << dist[n][0] << endl;
			return 0;
		}
		int dis = dist[n][0];
		v = vec[i], u = vec[i - 1];
		dis = min(dis, dist[u][0] + dist[v][1] + 1);
		ans = max(ans, dis);
	}
	
	cout << ans << endl;
	
	
	return 0;
}