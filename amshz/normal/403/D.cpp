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

const int xn = 1e3+10;
const int xm = 1e2+10;

ll ent[xn][xn], fact[xn], R[xn][xn];


int main(){
	fast_io;
	
	for (int i=0; i<=1e3; i++) ent[0][i] = 1;
	for (int i=1; i<=1e3; i++){
		for (int j=1; j<=1e3; j++) ent[i][j] = (ent[i-1][j-1] + ent[i][j-1] + md) % md;
	}
	fact[1] = 1;
	for (int i=2; i<=1e3; i++) fact[i] = (fact[i-1] * i + md) % md;
	
	R[0][0] = 1;
	for (int i=1; i<=1e3; i++) for (int j=i; j<=1e3; j++) if (j >= i) R[i][j] = (R[i][j-i] + R[i-1][j-i] + md) % md;
	
	int qq;
	cin >> qq;
	while (qq--){
		int n, k;
		cin >> n >> k;
		ll ans = 0;
		for (int i=k; i<=n; i++){
			ll s = 1;
			s = (s * R[k][i]) % md;
			s = (s * ent[k][n-i+k]) % md;
			s = (s * fact[k]) % md;
			ans = (ans + s) % md;
		}
		cout << ans << endl;
	}
	
	return 0;
}