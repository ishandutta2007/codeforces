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
const int xn = 1e3+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;

ll n, s, k, a[xn], q;


 
int main(){
	fast_io;
	
	cin >> q;
	while (q--){
		cin >> n >> s >> k;
		for (int i = 0; i < k; i++) cin >> a[i];
		
		sort(a, a+k);
		
		ll mn = inf;
		for (int i = 0; i < k; i++){
			if (a[i] > 1){
				if (i == 0 || a[i-1] != a[i]-1) mn = min(mn, abs(s- a[i]+ll(1)));
			}
			if (a[i] < n){
				if (i == k-1 || a[i+1] != a[i]+1) mn = min(mn, abs(s- a[i]-1));
			}
		}
		bool fl1 = true;
		for (int i = 0; i < k; i++){
			if (a[i] == s) fl1 = false;
		}
		if (fl1) mn = 0;
		cout << mn << endl;
	}
	
	return 0;
}