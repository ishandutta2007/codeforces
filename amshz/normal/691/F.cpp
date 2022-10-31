# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 3e6 + 10;
const int xm = 1e6 + 11;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}


ll n, a[xn], m, cnt[xn], ans[xn], ezafe;


 
int main(){
	fast_io;
	srand(time(0));
	
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i], cnt[a[i]] ++;
	
	for (ll i = 1; i <= 3e6; i ++){
		for (ll j = 1; j <= 3e6/i; j ++){
			ans[i * j] += cnt[i] * cnt[j];
			if (i == j) ans[i * j] -= cnt[i];
		}
	}
	
	for (ll i = 3e6; i >= 1; i --) ans[i] += ans[i + 1];
	
	ezafe = ((n - 1) * n) - ans[1];
	
	cin >> m;
	while (m --){
		ll x;
		cin >> x;
		cout << ans[x] + ezafe << endl;
	}
	
	
	
	
	return 0;
}