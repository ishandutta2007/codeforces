# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e6+10;
const int xm = 3e5+10;
const int SQ = 500;
const int inf = 1e9+10;

int dis[xn], t[xn], n, m, res, start, ft, lv;
set <pii> st;
map <pii, bool> mp;
vector <int> adj[xn], adj2[xn];
bool f = true, mark[xn];

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		t[v]++;
		adj[v].pb(u);
		adj2[u].pb(v);
	}
	cin >> start >> ft;
	for (int i = 1; i <= n; i++) dis[i] = inf;
	dis[ft] = 0;
	for (int i = 1; i <= n; i++) st.insert({dis[i], i});
	while (st.size()){
		int v = st.begin() -> S;
		st.erase(st.begin());
		mark[v] = true;
		for (int i = 0; i < adj2[v].size(); i++){
			int u = adj2[v][i];
			if (mark[u]) continue;
			st.erase({dis[u], u});
			t[u]--;
			dis[u] = min(dis[u], dis[v] + 1);
			if (t[u] <= 0) dis[u] = min(dis[u], dis[v]);
			st.insert({dis[u], u});
		}
	}
	if (dis[start] == inf){
		cout << -1 << endl;
		return 0;
	}
	cout << dis[start] << endl;
	
}
/*
10 10
4 5
9 3
3 2
3 8
2 9
9 8
9 2
7 9
6 4
9 4
3 2
*/