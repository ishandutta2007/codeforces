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
 
const int xn = 2e5+10;
const int xm = 5e4+10;

vector <int> adj[xn];
bool mark[xn];
int a[xn], n, dis[xn][2];


int main(){
    fast_io;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], dis[i][0] = -1, dis[i][1] = -1;
    
    for (int i = 1; i <= n; i++){
    	if (i-a[i] >= 1) adj[i-a[i]].pb(i);
    	if (i+a[i] <= n) adj[i+a[i]].pb(i);
	}
	
	queue <int> q;
	for (int i = 1; i <= n; i++){
		if (a[i]%2) q.push(i), mark[i] = true, dis[i][1] = 0;
	}
	while (q.size()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (mark[u]) continue;
			q.push(u);
			dis[u][1] = dis[v][1] + 1;
			mark[u] = true;
		}
	}
	
	for (int i = 0; i <= n; i++) mark[i] = false;
	
	for (int i = 1; i <= n; i++){
		if (a[i]%2 == 0) q.push(i), mark[i] = true, dis[i][0] = 0;
	}
	while (q.size()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (mark[u]) continue;
			q.push(u);
			dis[u][0] = dis[v][0] + 1;
			mark[u] = true;
		}
	}
	
	for (int i = 1; i <= n; i++) cout << dis[i][1-a[i]%2] << sep;
	cout << endl;
    
    return 0;
}