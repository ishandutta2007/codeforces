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

vector <int> s, adj[xn];
vector <vector<int> > ans;
deque <int> x;
set <int>  y;

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

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	int v, u;
	for (int i=0; i<m; i++) cin >> v >> u, adj[v].pb(u), adj[u].pb(v);
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
					cout << 1 << endl;
					cout << n << sep;
					for (int i=1; i<=n; i++) cout << i << sep;
					cout << endl;
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
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++){
		cout << ans[i].size() << sep;
		for (int j=0; j<ans[i].size(); j++) cout << ans[i][j] << sep;
		cout << endl;
	}
}