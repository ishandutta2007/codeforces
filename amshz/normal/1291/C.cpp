# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n, m, k, a[xn];



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i <= min(m-1, k); i++){
			int mn = inf;
			for (int j = i; j <= m - 1; j++){
				if (m - 1 - j < min(m-1, k) - i) continue;
				mn = min(mn, max(a[j], a[n - m + j]));
			}
			if (mn != inf) ans = max(ans, mn);
		}
		cout << ans << endl;
	}
	
	
	return 0;
}