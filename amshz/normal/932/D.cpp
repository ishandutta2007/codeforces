# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 4e5 + 10;
const int xm = 4e1 + 10;
const int xlg = 3e1 + 10;
const int SQ = 320;
const int sq = 5e2 + 10;
const int inf = 1e9 + 10;


ll n = 2, par[xn][xlg], Par[xn][xlg], Mx[xn][xlg], dp[xn][xlg], last, qq, p, q, a[xn], h[xn], H[xn];


void Update(ll P, ll x){
	a[n] = x;
	h[n] = h[P] + 1;
	par[n][0] = P;
	Mx[n][0] = x;
	for (int j = 1; j <= 30; j++){
		if ((1 << j) > h[n]) continue;
		par[n][j] = par[par[n][j - 1]][j - 1];
		Mx[n][j] = max(Mx[n][j - 1], Mx[par[n][j - 1]][j - 1]);
	}
	int v = P;
	for (int i = 30; i >= 0; i--){
		if ((1 << i) > h[v]) continue;
		if (Mx[v][i] < x) v = par[v][i];
	}
	Par[n][0] = v;
	dp[n][0] = x;
	H[n] = H[v] + 1;
	for (int i = 1; i <= 30; i++){
		if ((1 << i) > H[n]) continue;
		Par[n][i] = Par[Par[n][i - 1]][i - 1];
		dp[n][i] = dp[n][i - 1] + dp[Par[n][i - 1]][i - 1];
	}
	n ++;
}
void Get(ll v, ll x){
	ll ans = 0;
	for (int i = 30; i >= 0; i--){
		if ((1 << i) > H[v]) continue;
		if (dp[v][i] > x) continue;
		x -= dp[v][i];
		v = Par[v][i];
		ans += (1 << i);
	}
	cout << ans << endl;
	last = ans;
}


 
int main(){
	fast_io;
	
	H[1] = 1;
	h[1] = 1;
	
	cin >> qq;
	int t;
	while (qq--){
		cin >> t >> p >> q;
		if (t == 1){
			p = last ^ p;
			q = last ^ q;
			Update(p, q);
		}
		else{
			p = last ^ p;
			q = last ^ q;
			Get(p, q);
		}
	}
	
	
	return 0;
}