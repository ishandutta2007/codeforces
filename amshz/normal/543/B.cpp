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

const int xn = 3e3+10;
const int xm = 1e2+10;

int dis[xn][xn];
vector <int> adj[xn];

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	int s1, s2, t1, t2, l1, l2;
	int x, y;
	for (int i=0; i<m; i++) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dis[i][j] = -1;
	
	//queue <int> q;
	
	for (int i=1; i<=n; i++){
		queue <int> q;
		q.push(i);
		dis[i][i] = 0;
		while (q.size()){
			int v = q.front();
			q.pop();
			
			for (int j=0; j<adj[v].size(); j++){
				int u = adj[v][j];
				if (dis[i][u] == -1) dis[i][u] = dis[i][v]+1, q.push(u);
			}
		}
	}
	//cout << "q;3ceg" << endl;
	int mn = 1e9;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if ((min(dis[i][t1] + dis[j][s1], dis[i][s1] + dis[j][t1]) + dis[i][j] <= l1) && (min(dis[i][t2] + dis[j][s2], dis[i][s2] + dis[j][t2]) + dis[i][j] <= l2)) mn = min(mn, min(dis[i][s1] + dis[j][t1], dis[i][t1] + dis[j][s1]) + dis[i][s2] + dis[j][t2] + dis[i][j]), mn = min(mn, min(dis[i][s1] + dis[j][t1], dis[i][t1] + dis[j][s1]) + dis[i][t2] + dis[j][s2] + dis[i][j]);
	
	if (dis[s1][t1] <= l1 && dis[s2][t2] <= l2) mn = min(mn, dis[s1][t1] + dis[s2][t2]);
	if (mn == 1e9){
		cout << -1 << endl;
		return 0;
	}
	cout << m - mn << endl;
	
	
	return 0;
}