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
 
const ll md = 1e9+7;
const int xn = 1e7 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll menha(ll a, ll b){
	return (a - b + 10 * md) % md;
}


int n, a[xn], ps[xn], cnt[xn], ans, k, mn = 1e9;
 
 
int main(){
	fast_io;
	
	
	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> a[i], mn = min(mn, a[i]);
	
	for (int i = 0; i < n; i ++) ps[max(0, a[i] - k)] ++, ps[a[i] + 1] --;
	for (int i = 1; i <= 2e6; i ++) ps[i] += ps[i - 1];
	
	for (int i = 1; i <= 2e6; i ++){
		if (i > mn) break;
		for (int j = i; j <= 2e6; j += i) cnt[i] += ps[j];
		if (cnt[i] >= n) ans = i;
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}