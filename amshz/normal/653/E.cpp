# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const int xn = 5e5+10;
 
vector <int> s, adj[xn], adj2[xn];
vector <vector<int> > ans;
deque <int> x;
set <int>  y;
int n, m, k, D[xn], sz, sz2;
bool flag[xn];
 
bool fn1(int v, int u){
	int l = 0, r = adj[v].size();
	while (r-l > 1){
		int mid = (l+r)/2;
		if (adj[v][mid] > u) r = mid;
		else l = mid;
	}
	if (adj[v][l] == u) return true;
	return false;
}
void Solve(){
	int vabaste = 0;
	if (sz  > 1 || sz2 > k || n-D[1]-1 < k){
		cout << "impossible" << endl;
		return;
	}
	cout << "possible" << endl;
	return;
}
void daraje(){
	for (int i = 1; i <= n; i++){
		adj[i].resize(0);
		for (int j = 0; j < adj2[i].size(); j++){
			adj[i].pb(adj2[i][j]);
		}
		sort(adj[i].begin(), adj[i].end());
	}
	s.resize(0), ans.resize(0);
	while (y.size()) y.erase(y.begin());
	while (x.size()) x.pop_front();
	
	for (int i=2; i<=n; i++) y.insert(i);
	while (y.size()){
		int u = *y.begin();
		x.pb(u), y.erase(y.begin());
		
		while (x.size()){
			int v = x.front();
			x.pop_front();
			s.pb(v);
			std::set <int>  :: iterator it;
			it = y.begin();
			vector <int> vec;
			while (it != y.end()){
				int u = *it;
				if (adj[v].size() == 0){
					sz2 = 1;
					Solve();
					return;
				}
				if (!fn1(v, u)) x.pb(u);
				else vec.pb(u);
				it++;
			}
			y.clear();
			for (int i=0; i<vec.size(); i++) y.insert(vec[i]);
		}
		ans.pb(s);
		s.resize(0);
	}
	sz2 = ans.size();
	Solve();
}
 
int main(){
	fast_io;
	
	cin >> n >> m >> k;
	int v, u;
	for (int i = 0; i < m; i++){
		cin >> v >> u;
		adj[v].pb(u), adj[u].pb(v);
		if (v != 1 && u != 1){
			adj2[v].pb(u), adj2[u].pb(v);
		}
		D[v]++, D[u]++;
		if (v == 1) flag[u] = true;
		if (u == 1) flag[v] = true;
	}
	for (int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());
	for (int i=1; i<=n; i++) y.insert(i);
	while (y.size()){
		int u = *y.begin();
		x.pb(u), y.erase(y.begin());
		
		while (x.size()){
			int v = x.front();
			x.pop_front();
			s.pb(v);
			std::set <int>  :: iterator it;
			it = y.begin();
			vector <int> vec;
			while (it != y.end()){
				int u = *it;
				if (adj[v].size() == 0){
					sz = 1;
					daraje();
					return 0;
				}
				if (!fn1(v, u)) x.pb(u);
				else vec.pb(u);
				it++;
			}
			y.clear();
			for (int i=0; i<vec.size(); i++) y.insert(vec[i]);
		}
		ans.pb(s);
		s.resize(0);
	}
	sz = ans.size();
	daraje();
	
	return 0;
}