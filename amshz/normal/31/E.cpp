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
	if (b == 0) return 1;
	if (b == 1) return (a);
	if (b%2 == 0) return (pw(a*a, b/2));
	else return (a*pw(a*a, b/2));
}
 
const int xn = 5e1+10;
const int xm = 5e4+10;
 
struct dp1{
	ll A, B, tA, tB;
	string ans;
};
 
dp1 dp[xn][xn];
 
 
int main(){
	fast_io;
	
	//cout << pw(10, 1) * 5 << endl;
	
	ll n;
	cin >> n;
	string a;
	cin >> a;
	
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			if (i == 0 && j == 0) continue;
			
			ll s1 = 0, s2 = 0;
			if (i > 0) s1 = dp[i-1][j].A + ll(a[n+n-i-j]-'0') * pw(ll(10), dp[i-1][j].tA) + dp[i-1][j].B;
			if (j > 0) s2 = dp[i][j-1].B + ll(a[n+n-i-j]-'0') * pw(ll(10), dp[i][j-1].tB) + dp[i][j-1].A;
			
			
			if (s1 >= s2 && i > 0){
				dp[i][j].ans = dp[i-1][j].ans + 'H';
				dp[i][j].A = dp[i-1][j].A + ll(a[n+n-i-j]-'0') * pw(ll(10), dp[i-1][j].tA);
				dp[i][j].tA = dp[i-1][j].tA + 1;
				dp[i][j].tB = dp[i-1][j].tB;
				dp[i][j].B = dp[i-1][j].B;
			}
			else {
				dp[i][j].ans = dp[i][j-1].ans + 'M';
				dp[i][j].B = dp[i][j-1].B + ll(a[n+n-i-j]-'0') * pw(ll(10), dp[i][j-1].tB);
				dp[i][j].tB = dp[i][j-1].tB + 1;
				dp[i][j].tA = dp[i][j-1].tA;
				dp[i][j].A = dp[i][j-1].A;
			}
		}
	}
	
	reverse(dp[n][n].ans.begin(), dp[n][n].ans.end());
	
	cout << dp[n][n].ans << endl;
	
	return 0;
}