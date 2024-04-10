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

struct edge{
	int L, R;
	bool mark;
};

const int xn = 2e5+10;
const int xk = 1e2+10;

int n, d[xn], p[xn];
edge e[xn];
vector <int> vec, tour;
vector <pii> adj[xn];
map <int, int> tab;
map <pii, int> mp;
map <pii, bool> mb;
bool mark[xn], ans[xn];

void DFS(int v){
	mark[v] = true;
	
	while (p[v] < adj[v].size()){
		int i = p[v];
		p[v]++;
		int u = adj[v][i].S;
		if (e[u].mark) continue;
		e[u].mark = true;
		
		DFS(adj[v][i].F);
	}
	tour.pb(v);
}


int main(){
	fast_io;
	
	cin >> n;
	for (int i=1; i<=n; i++){
		int x, y;
		cin >> x >> y;
		y++;
		vec.pb(x), vec.pb(y);
		e[i].L = x, e[i].R = y;
		//mp[{x, y}] = i, mp[{y, x}] = i;
	}
	sort(vec.begin(), vec.end());
	//for (int i=0; i<vec.size(); i++) cout << vec[i] << endl;
	int t = 0;
	tab[vec[0]] = t, t++;
	for (int i=1; i<vec.size(); i++){
		if (vec[i] == vec[i-1]) continue;
		//cout << vec[i] << sep << t << endl;
		tab[vec[i]] = t, t++;
	}
	int m = t;
	//cout << endl;
	//cout << tab[3] << endl;
	for (int i=1; i<=n; i++) e[i].L = tab[e[i].L], e[i].R = tab[e[i].R];
	for (int i=1; i<=n; i++) adj[e[i].L].pb({e[i].R, i}), adj[e[i].R].pb({e[i].L, i}), d[e[i].L]++, d[e[i].R]++, mp[{e[i].L, e[i].R}] = i, mp[{e[i].R, e[i].L}] = i;
	
	t = n + 1;
	int dx = -1;
	for (int i=0; i<=m; i++){
		if (d[i]%2 == 0) continue;
		//cout << i << endl;
		if (dx == -1) dx = i;
		else{
			//cout << dx << sep << i << endl;
			e[t].L = dx, e[t].R = i;
			//if (1) mp[{dx, i}] = t, mp[{i, dx}] = t;
			adj[dx].pb({i, t}), adj[i].pb({dx, t});
			d[dx]++, d[i]++;
			t++, dx = -1;
		}
	}
	
	for (int i=0; i<=m; i++){
		if (mark[i]) continue;
		tour.resize(0);
		DFS(i);
		//for (int j=0; j<tour.size(); j++) cout << tour[j] << sep;
		//cout << endl;
		for (int j=1; j<tour.size(); j++){
			int x = tour[j-1], y = tour[j];
			if (x > y) ans[mp[{x, y}]] = true;
		}
	}
	for (int i=1; i<=n; i++) cout << ans[i] << sep;
	cout << endl;
	
	
	return 0;
}
/*
3
1 3
3 5
1 5
*/