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
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;

ld ans;
ll n;


 
int main(){
	fast_io;
	
	
	cin >> n;
	cout << fixed << setprecision(8);
	
	while (n >= 1){
		//cout << n << endl;
		ll m = (n+1)/2;
		ld f = 1;
		ld g = n;
		ans += f/g;
		n -= 1;
	}
	cout << ans << endl;
	
	return 0;
}