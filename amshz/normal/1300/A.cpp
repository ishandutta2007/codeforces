# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n, a[xn], ans, s;



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ans = 0;
		s = 0;
		for (int i = 0; i < n; i++){
			if (a[i] != 0){
				s += a[i];
				continue;
			}
			s++;
			ans++;
		}
		if (s == 0) ans++;
		cout << ans << endl;
	}
	
	
	return 0;
}