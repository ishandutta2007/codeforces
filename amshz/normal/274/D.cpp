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
const ll MD = md * 100;
const int xn = 5e5 + 10;
const int xm = 1e5;
const int SQ = 233;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, m, Mark[xn], b[xn];
map <int, vector <int> > mp;
map <int, bool> vis;
vector <int> adj[xn], TPS, vec;
bool flag;

void DFS(int v){
	Mark[v] = 1;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]){
			if (Mark[u] == 1) flag = true;
			continue;
		}
		DFS(u);
	}
	Mark[v] = 2;
	if (v >= m || v < 0) return;
	TPS.push_back(v + 1);
}
 
 
int main(){
	//fast_io;
	
	cin >> n >> m;
	int cnt = m, x, y;
	for (int i = 0; i < n; i ++){
		vec.resize(0);
		mp.clear();
		vis.clear();
		for (int j = 0; j < m; j ++){
			cin >> x;
			if (x == -1) continue;
			mp[x].push_back(j);
			if (vis[x]) continue;
			vis[x] = true;
			vec.push_back(x);
		}
		if (!vec.size()) continue;
		sort(vec.begin(), vec.end());
		for (int j = 0; j < vec.size() - 1; j ++){
			int x = vec[j], y = vec[j + 1];
			for (int k = 0; k < mp[x].size(); k ++) adj[mp[x][k]].push_back(cnt);
			for (int k = 0; k < mp[y].size(); k ++) adj[cnt].push_back(mp[y][k]);
			cnt ++;
		}
	}
	
	for (int i = 0; i < cnt; i ++){
		if (Mark[i]) continue;
		DFS(i);
	}
	
	if (flag){
		cout << -1 << endl;
		return 0;
	}
	
	reverse(TPS.begin(), TPS.end());
	for (int i = 0; i < TPS.size(); i ++) cout << TPS[i] << sep;
	cout << endl;
	
	
	return 0;
}