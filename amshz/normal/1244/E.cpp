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

ll a[xn], n, k;

 
int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a+1, a+n+1);
	
	for (int i = 1; i <= n/2; i++){
		ll s = (a[i+1] - a[i] + a[n-i+1] - a[n-i]) * i;
		if (k >= s) k -= s;
		else{
			cout << a[n-i+1]-a[i]-k/i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	
	
	return 0;
}