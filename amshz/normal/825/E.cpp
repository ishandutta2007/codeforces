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
const int xn = 1e6+10;
const int xm = 5e5+10;
const int SQ = 320;
const int inf = 1e9+10;


int n, m, a[xn], out[xn];
vector <int> adj[xn];

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		out[v]++;
		adj[u].pb(v);
	}
	set <pii> st;
	for (int i = 1; i <= n; i++){
		st.insert({out[i], n-i});
	}
	int res = n;
	while (st.size()){
		int v = st.begin() -> S;
		v = n - v;
		st.erase(st.begin());
		a[v] = res--;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			st.erase({out[u], n-u});
			out[u]--;
			st.insert({out[u], n-u});
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << sep;
	cout << endl;
		
	return 0;
}