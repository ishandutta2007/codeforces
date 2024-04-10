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
 
const ll md = 998244353;
const int xn = 2e5+10;
const int xm = 5e1+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

ll qq, n, x, a[xn];



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int p;
		for (int i = 0; i < n; i++){
			if (a[i] <= x) p = i;
		}
		ll ans = (x + a[n - 1] - 1) / a[n - 1];
		if (ans == 1 && a[n - 1] > x) ans++;
		for (int i = 0; i < n; i++){
			if (a[i] == x) ans = 1;
		}
		cout << ans << endl;
	}
	
	
	
	return 0;
}