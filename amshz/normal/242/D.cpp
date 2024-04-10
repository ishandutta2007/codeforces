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

const int xn = 2e5+10;
const int xm = 1e2+10;

int a[xn], val[xn];
vector <int> adj[xn], ans;
bool mark[xn];


int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	
	int x, y;
	for (int i=0; i<m; i++) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	for (int i=1; i<=n; i++) cin >> a[i];
	
	queue <int> q;
	for (int i=0; i<n; i++) 
		if (a[i+1] == 0) q.push(i+1);
		
	while (q.size()){
		int v = q.front();
		
		val[v]++;
		ans.pb(v);
		q.pop();
		
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			val[u]++;
			if (val[u] == a[u] && !mark[u]) q.push(u), mark[u] = true;
		}
	}
	
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}