# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 5e5+10;
const int xm = 3e1+10;

int h[xn], n, qq, prt_sm[xn][xm], t, start[xn], finish[xn], tt;
string a, abc = "abcdefghijklmnopqrstuvwxyz";
vector <int> adj[xn], flor[xn];
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	flor[h[v]].pb(v);
	start[v] = t++;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		h[u] = h[v] + 1;
		DFS(u);
	}
	finish[v] = tt++;
}

void fill_prt(){
	for (int i = 1; i <= n; i++){
		if (!flor[i].size()) break;
		int v = flor[i][0];
		prt_sm[v][int(a[v]-'a')]++;
		for (int j = 1; j < flor[i].size(); j++){
			int u = flor[i][j];
			for (int k = 0; k < 26; k++) prt_sm[u][k] += prt_sm[flor[i][j-1]][k];
			prt_sm[u][int(a[u]-'a')]++;
		}
	}
}

pii find(int v, int d){
	pii ans;
	
	int l = 0, r = flor[d].size()-1, mid;
	
	while (r - l > 1){
		mid = (l+r)/2;
		int u = flor[d][mid];
		
		if (start[u] < start[v]) l = mid;
		else r = mid;
	}
	if (start[flor[d][0]] >= start[v]) r = 0;
	ans.F = r;
	
	l = 0, r = flor[d].size(), mid;
	
	while (r - l > 1){
		mid = (l+r)/2;
		int u = flor[d][mid];
		
		if (finish[u] < finish[v]) l = mid;
		else r = mid;
	}
	ans.S = flor[d][l];
	
	return ans;
	
}

bool solve(int v, int d){
	if (h[v] >= d || !flor[d].size()) return true;
	
	pii kind = find(v, d);
	
	int fards = 0;
	
	for (int i = 0; i < 26; i++){
		int s = prt_sm[kind.S][i];
		if (kind.F > 0) s -= prt_sm[flor[d][kind.F-1]][i];
		fards += s%2;
	}
	
	return (fards <= 1);
}


int main(){
    fast_io;
    
    cin >> n >> qq;
    int v;
    for (int i = 2; i <= n; i++) cin >> v, adj[v].pb(i), adj[i].pb(v); 
    cin >> a;
    a = '#'+a;
    
    h[1] = 1;
    DFS(1);
    fill_prt();
    
    while (qq--){
    	int v, p;
    	cin >> v >> p;
    	
    	if (solve(v, p)) cout << "Yes" << endl;
    	else cout << "No" << endl;
	}
    
    return 0;
}