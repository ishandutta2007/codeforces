# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e3 + 10;
const int xm = 2e5 + 10;
const int SQ = 500;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}

int n, m, S, start[xn], d[xn][2], Root;
vector <pii> adj[xn];
vector <pair <pii, int> > vec;
bool Mark[xn];


void DFS(int v, int mx){
	Mark[v] = true;
	if (d[v][0] == 0)
		vec.push_back({{Root, v}, mx});
	for (pii u : adj[v])
		DFS(u.F, min(mx, u.S));
}

bool cmp(pair <pii, int> i, pair <pii, int> j){
	return i.F.F < j.F.F;
}

 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		start[v] = S ++;
		d[v][0] ++;
		d[u][1] ++;
	}
	
	for (int i = 1; i <= n; i ++){
		if (Mark[i] || d[i][0] != 1 || d[i][1] != 0) continue;
		Root = i;
		DFS(i, 1e9);
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i ++)
		cout << vec[i].F.F << sep << vec[i].F.S << sep << vec[i].S << endl;
	
	
	return 0;
}