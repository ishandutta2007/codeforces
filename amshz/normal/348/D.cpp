# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;

# define endl		 '\n'
# define sep		 ' '
# define F 			 first
# define S 			 second
# define pb			 push_back
# define fast_io 	 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b);}
ll pw(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pw(a*a, b/2)+md)%md;
	else return (a*pw(a*a, b/2)+md)%md;
}

const int xn = 3e3+10;
const int xm = 5e4+10;

ll n, m, dp[xn][xn][2];
string a[xn];
 
int main() {
    fast_io;
 	
 	cin >> n >> m;
 	for (int i=1; i<=n; i++) cin >> a[i];
 	
 	dp[1][2][0] = 1;
 	dp[2][1][1] = 1;
 	
 	if (a[1][1] == '#' || a[2][0] == '#'){
 		cout << 0 << endl;
 		return 0;
	 }
 	
 	for (int i=1; i<=n; i++){
 		for (int j=1; j<=m; j++){
 			if (a[i][j-1] == '#') continue;
 			dp[i][j][0] += (dp[i-1][j][0] + dp[i][j-1][0] + md) % md;
			dp[i][j][1] += (dp[i-1][j][1] + dp[i][j-1][1] + md) % md;
		 }
	 }
	 //cout << dp[n][m][0] << sep << dp[n][m][1] << endl;
	 //cout << dp[n][m-1][0] << endl;
	 cout << ((dp[n-1][m][0] * dp[n][m-1][1]) % md - (dp[n][m-1][0] * dp[n-1][m][1] % md) + md*md) % md;
}