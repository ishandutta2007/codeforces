# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, a[xn], d;
ll ans;


int main(){
	fast_io;
	
	cin >> n >> d;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	for (int i = 0; i < n; i ++){
		ll L = i, R = n, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (a[Mid] - a[i] <= d) L = Mid;
			else R = Mid;
		}
		ll x = L - i;
		if (x > 1){
			ans += (x * (x - 1)) / 2;
		}
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}