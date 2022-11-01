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
const int xn = 2e5+10;
const int SQ = 450;
 
int start[xn], r[xn], s, a[xn], b[xn], n, qq, p[xn], c[xn];
vector <int> adj[xn];
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	start[v] = s++;
	r[v] = v;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
		r[v] = r[u];
	}
}

void update(int l, int r){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) c[i/SQ]++, i += SQ;
		else{
			if (a[i]) b[i/SQ]--;
			else b[i/SQ]++;
			a[i] = 1-a[i];
			i++;
		}
	}
}
void get(int l, int r){
	int ans = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (c[i/SQ]%2) ans += SQ-b[i/SQ];
			else ans += b[i/SQ];
			i += SQ;
		}
		else{
			if (c[i/SQ]%2) ans += 1-a[i];
			else ans += a[i];
			i++;
		}
	}
	cout << ans << endl;
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 2; i <= n; i++){
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	DFS(1);
	
	for (int i = 1; i <= n; i++) cin >> a[start[i]];
	
	for (int i = 0; i < n; i++) b[i/SQ] += a[i];
	
	
	
	cin >> qq;
	while (qq--){
		string x;
		int v;
		cin >> x >> v;
		if (x == "get") get(start[v], start[r[v]]);
		else update(start[v], start[r[v]]);
	}
	
	return 0;
}