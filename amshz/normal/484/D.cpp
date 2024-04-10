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

const int xn = 1e6+10;
const int xm = 5e4+10;

ll n, a[xn], dp[xn][3];
bool flag[xn];

int main(){
	fast_io;
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=1; i<n; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
		if (a[i] >= a[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i] - a[i-1]);
		if (a[i] <= a[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1] + a[i-1] - a[i]);
	}
	
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	
	return 0;
}
/*
8
23 2 7 5 15 8 4 10
*/