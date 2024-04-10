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
const int xn = 7e5+10;
const int xk = 1e2+10;
 
struct edge{
	int V, U;
	bool mark;
};
 
int n, d[xn][2], p[xn][2];
bool a[xn], mark[xn][2];
map <pii, int> mp;
edge e[xn];
vector <pii> adj[xn][2];
vector <pair <int, bool> > ans;
 
void DFS(int v, bool f, int k){
	mark[v][f] = true;
	
	while (p[v][f] < adj[v][f].size()){
		int i = p[v][f];
		int u = adj[v][f][i].S;
		p[v][f]++;
		if (e[u].mark) continue;
		e[u].mark = true;
		
		DFS(adj[v][f][i].F, !f, u);
	}
	ans.pb({v, f});
}
 
int main(){
	fast_io;
	
	cin >> n;
	int x, y;
	for (int i=1; i<=n; i++) cin >> x >> y, adj[x][0].pb({y, i}), adj[y][1].pb({x, i}), d[x][0]++, d[y][1]++, e[i].V = x, e[i].U = y, mp[{x, y}] = i;
	
	int t = n+1;
	
	for (int i=1; i<=2e5; i++){
		x = i, y = 0;
		
		if (d[x][0]%2) adj[x][0].pb({y, t}), adj[y][1].pb({x, t}), e[t].V = x, e[t].U = y, t++, d[x][0]++, d[y][1]++;
		if (d[x][1]%2) adj[x][1].pb({y, t}), adj[y][0].pb({x, t}), e[t].V = y, e[t].U = x, t++, d[x][1]++, d[y][0]++;
	}
	if (d[0][0]%2) adj[0][0].pb({0, t}), adj[0][1].pb({0, t}), e[t].V = 0, e[t].U = 0, t++, d[0][1]++, d[0][0]++;
	
	//cout << mp[{0, 0}] << endl;
	
	for (int i=0; i<=2e5; i++){
		if (d[i][0] && !mark[i][0]){
			DFS(i, 0, 0);
			for (int k=0; k<ans.size(); k++){
				if (!ans[k].S){
					if (k > 0) a[mp[{ans[k].F, ans[k-1].F}]] = 0;
					if (k < ans.size()-1) a[mp[{ans[k].F, ans[k+1].F}]] = 1;
				}
			}
			ans.resize(0);
		}
	}
	for (int j=1; j<=n; j++){
		if (a[j]) cout << 'r';
		else cout << 'b';
	}
	cout << endl;
	return 0;
}