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
 
string bin(ll n){
	string ans = "";
	while (n > 0){
		if (n%2 == 0) ans = '0'+ans;
		else ans = '1'+ans;
		n /= 2;
	}
	return ans;
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}
 
char fn1(int n){
	if (n == 0) return '0';
	if (n == 1) return '1';
	if (n == 2) return '2';
	if (n == 3) return '3';
	if (n == 4) return '4';
	if (n == 5) return '5';
	if (n == 6) return '6';
	if (n == 7) return '7';
	if (n == 8) return '8';
	if (n == 9) return '9';
}
 
const int xn = 1e5+10;
const int xm = 1e2+10;
 
vector <int> adj[xn], zero, d[xn];
map <pii, int> w;
int p[xn], s[xn];
pii dis[xn];
string ans;
bool mark[xn];
 
int main(){
	//fast_io;
	
	int n, m;
	cin >> n >> m;
	int x, y, z;
	for (int i=0; i<m; i++) cin >> x >> y >> z, adj[x].pb(y), adj[y].pb(x), w[{x, y}] = z, w[{y, x}] = z;
	//cout << "3cj3p5jh " << endl;
	
	for (int i=0; i<n; i++) dis[i].F = -1, dis[i].S = -1;
	
	queue <int> q;
	q.push(0);
	dis[0].F = 0;
	
	while (q.size()){
		int v = q.front();
		q.pop();
		//d[dis[u]].pb(u);
		
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			if (dis[u].F == -1) dis[u].F = dis[v].F+1, q.push(u);
		}
	}
	
	q.push(n-1);
	dis[n-1].S = 0;
	
	while (q.size()){
		int v = q.front();
		q.pop();
		
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			if (dis[u].S == -1) dis[u].S = dis[v].S+1, q.push(u);
		}
	}
	
	q.push(n-1);
	int mn = dis[n-1].F;
	mark[n-1] = true;
	zero.pb(n-1);
	while (q.size()){
		int v = q.front();
		q.pop();
		
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			if (!mark[u] && w[{v, u}] == 0) mark[u] = true, mn = min(mn, dis[u].F), q.push(u), zero.pb(u), p[u] = v;
		}
	}
	deque <int> dq;
	for (int i=0; i<n; i++) mark[i] = false;
	for (int i=0; i<zero.size(); i++) if (dis[zero[i]].F == mn) dq.push_front(zero[i]), mark[zero[i]] = true;
	
	mark[n-1] = true;
	int l = -1;
	while (dq.size()){
		int mn = 1e9;
		
		for (int i=0; i<dq.size(); i++){
			int v = dq[i];
			for (int j=0; j<adj[v].size(); j++){
				int u = adj[v][j];
				if (dis[u].F == dis[v].F-1) mn = min(mn, w[{v, u}]);
			}
		}
		
		deque <int> dq2;
		for (int i=0; i<dq.size(); i++){
			int v = dq[i];
			for (int j=0; j<adj[v].size(); j++){
				int u = adj[v][j];
				if (dis[u].F == dis[v].F-1 && !mark[u] && w[{v, u}] == mn) dq2.push_front(u), mark[u] = true, p[u] = v;
				if (dis[u].F == dis[v].F-1 && w[{v, u}] == mn && mark[u] && dis[p[u]].S > dis[v].S) p[u] = v;
			}
		}
		
		while (dq.size()) dq.pop_front();
		for (int i=0; i<dq2.size(); i++) dq.push_front(dq2[i]);
	}
	
	x = 0;
	int t = 1;
	while (x != n-1){
		ans = fn1(w[{x, p[x]}]) + ans;
		x = p[x];
		t++;
	}
	
	bool fl1 = false;
	//if (ans.size() == 0) cout << '0';
	for (int i=0; i<ans.size(); i++){
		if (ans[i] != '0') fl1 = true, cout << ans[i];
		else if (fl1) cout << ans[i];
	}
	if (fl1 == false) cout << '0';
	cout << endl;
	cout << t << endl;
	
	x = 0;
	string s = "";
	while (x != n-1){
		cout << x << sep;
		x = p[x];
	}
	cout << n-1 << endl;
	
	return 0;
}