# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 1e3+10;
const int xm = 5e4+10;
const int SQ = 1000;

ll n, m, k, r[xn], c[xn], dist[xn][xn];
pll a[xn], b[xn];
vector <int> adj[xn];

void BFS(ll s){
	for (int i = 0; i <= m; i++) dist[s][i] = -1;
	dist[s][s] = 0;
	queue <ll> q;
	q.push(s);
	while (q.size()){
		ll v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			ll u = adj[v][i];
			if (dist[s][u] > -1) continue;
			dist[s][u] = dist[s][v] + 1;
			q.push(u);
		}
	}
}


int main(){
    fast_io;
    
   
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    for (int i = 0; i < m; i++) cin >> r[i] >> b[i].F >> b[i].S;
    
    for (int i = 0; i < m; i++){
    	int mn = 1e9+10, dx = m;
    	for (int j = 0; j < m; j++){
    		if (i == j) continue;
    		if (r[j] > r[i] && ld(sqrt(pow(abs(b[i].F-b[j].F), 2) + pow(abs(b[i].S-b[j].S), 2))) <= r[j]){
    			if (r[j] < mn) mn = r[j], dx = j;
			}
		}
		adj[i].pb(dx), adj[dx].pb(i);
	}
	for (int i = 0; i < n; i++){
		int mn = 1e9+10, dx = m;
		for (int j = 0; j < m; j++){
    		if (ld(sqrt(pow(abs(a[i].F-b[j].F), 2) + pow(abs(a[i].S-b[j].S), 2))) <= r[j]){
    			if (r[j] < mn) mn = r[j], dx = j;
			}
		}
		c[i] = dx;
	}
	for (int i = 0; i <= m; i++) BFS(i);
	
	for (int i = 0; i < k; i++){
		ll x, y;
		cin >> x >> y;
		x--, y--;
		//cout << c[x] << sep << c[y] << endl;
		cout << dist[c[x]][c[y]] << endl;
	}
	
    
    return 0;
}