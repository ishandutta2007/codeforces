# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
//# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e3+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, d[xn], a[xn];
vector <int> adj[xn];
bool mark[xn];


bool cmp(int i, int j){
	if (mark[i]) return false;
	return d[i] < d[j];
}



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) a[i] = i;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		d[v] ++;
		d[u] ++;
	}
	
	while (true){
		vector <int> vec;
		for (int i = 1; i <= n; i ++){
			if (d[i] == 1 && !mark[i]) vec.push_back(i);
			if (vec.size() > 1) break;
		}
		if (vec.size() < 2) break;
		int v = vec[0], u = vec[1];
		cout << "? " << v << sep << u << endl;
		int w;
		cin >> w;
		if (w == v || w == u){
			cout << "! " << w << endl;
			return 0;
		}
		for (int i = 0; i < adj[v].size(); i ++){
			int uu = adj[v][i];
			d[uu] --;
		}
		for (int i = 0; i < adj[u].size(); i ++){
			int uu = adj[u][i];
			d[uu] --;
		}
		mark[v] = mark[u] = true;
	}
	
	for (int i = 1; i <= n; i ++){
		if (mark[i]) continue;
		cout << "! " << i << endl;
		return 0;
	}
	
	return 0;
}