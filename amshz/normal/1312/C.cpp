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
const int xn = 1e4+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n;
ll k, a[xn], cnt[xn];



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n >> k;
		for (int i = 0; i < n; i ++) cin >> a[i];
		
		memset(cnt, 0, sizeof cnt);
		bool fl1 = true;
		for (int i = 0; i < n; i ++){
			ll x = a[i];
			ll t = 0;
			while (x){
				if (x % k > 1) fl1 = false;
				if (x % k) cnt[t] ++;
				t ++;
				x /= k;
			}
		}
		for (int i = 0; i < 60; i ++) if (cnt[i] > 1) fl1 = false;
		if (fl1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	return 0;
}