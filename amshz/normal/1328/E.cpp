# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 5e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
 
int n, m, start[xn], finish[xn], h[xn], k, S, par[xn];
vector <int> adj[xn], Q;
bool mark[xn];
 
void DFS(int v){
	mark[v] = true;
	start[v] = S ++;
	for (int u : adj[v]){
		if (mark[u]) continue;
		h[u] = h[v] + 1;
		par[u] = v;
		DFS(u);
	}
	finish[v] = S ++;
}
 
bool cmp(int i, int j){
	return h[i] < h[j];
}
 
 
void Solve(){
	cin >> k;
	Q.clear();
	for (int i = 0; i < k; i ++){
		int v;
		cin >> v;
		Q.push_back(v);
	}
	//sort(Q.begin(), Q.end(), cmp);
	set <int> st, baba;
	for (int v : Q){
		baba.insert(par[v]);
		st.insert(h[v]);
	}
	if (st.size() != baba.size()){
		cout << "NO" << endl;
		return;
	}
	vector <int> vec;
	for (int v : baba) vec.push_back(v);
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 1; i < vec.size(); i ++){
		int v = vec[i], u = vec[i - 1];
		swap(v, u);
		if (v == 0) continue;
		if (start[v] <= start[u] && finish[v] >= finish[u]) continue;
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	
	while (m --){
		Solve();
	}
	
	return 0;
}