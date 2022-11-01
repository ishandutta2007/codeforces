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
 
const ll md = 1e9+7;
const int xn = 1e6+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}


int n;
vector <int> adj[xn];
ll dp[xn][2];


void DFS(int v){
	ll Zoj = 0, Fard = 1, Bz1 = 0, Bz2 = 1, Bfard = 1, Bzoj = 0;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		DFS(u);
		ll x = jaam(zarb(Zoj, dp[u][0]), zarb(Fard, dp[u][1]));
		ll y = jaam(zarb(Zoj, dp[u][1]), zarb(Fard, dp[u][0]));
		//Bad = jaam(Bad, zarb(Fard, jaam(-1, jaam(dp[u][0], dp[u][1]))));
		//Bzoj = jaam(Bzoj, zarb(Fard, dp[u][1]));
		//Bfard = jaam(Bfard, zarb(Fard, jaam(-1, dp[u][0])));
		Fard = y;
		Zoj = x;
		Bfard = zarb(Bfard, dp[u][0]);
		x = jaam(Bz2, zarb(Bz1, dp[u][1]));
		y = jaam(Bz1, zarb(Bz2, dp[u][1]));
		Bz1 = y;
		Bz2 = x;
	}
	Bzoj = Bz1;
	Zoj = zarb(2, Zoj);
	Fard = zarb(2, Fard);
	Bfard = zarb(-1, Bfard);
	Bzoj = zarb(-1, Bzoj);
	dp[v][0] = jaam(jaam(Zoj, 1), Bzoj);
	dp[v][1] = jaam(jaam(Fard, 0), Bfard);
	
	//cout << v << " : " << dp[v][0] << sep << dp[v][1] << endl;
}




int main(){
	fast_io;
	
	cin >> n;
	int v;
	for (int i = 2; i <= n; i ++){
		cin >> v;
		adj[v].push_back(i);
	}
	
	DFS(1);
	
	cout << jaam(-1, jaam(dp[1][0], dp[1][1])) << endl;
	
	
	return 0;
}