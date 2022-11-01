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


int n;
ll ans;
pii a[xn];


bool cmp(pii i, pii j){
	return i.F - i.S < j.F - j.S;
}


int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i].F;
	for (int i = 0; i < n; i ++) cin >> a[i].S;
	
	sort(a, a + n, cmp);
	
	for (int i = 0; i < n; i ++){
		if (a[i].F - a[i].S <= 0) continue;
		int x = a[i].S - a[i].F;
		int L = -1, R = i, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (a[Mid].F - a[Mid].S > x) R = Mid;
			else L = Mid;
		}
		ans += ll(i - L - 1);
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}