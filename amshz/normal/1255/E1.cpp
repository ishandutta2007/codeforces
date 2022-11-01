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
const int xn = 2e5+10;
const int xm = 3e5+10;
const int SQ = 500;
const ll inf = 1e18+10;


ll n, a[xn], ans = inf, t;
bool f[xn];
vector <int> p, vec;

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], t += a[i];
	
	for (int i = 2; i <= 1e5; i++){
		if (f[i]) continue;
		p.pb(i);
		for (int j = i+i; j <= 1e5; j += i) f[j] = true;
	}
	
	for (int i = 0; i < p.size(); i++){
		int k = p[i];
		if (t%k != 0) continue;
		vec.resize(0);
		ll g = 0;
		for (int j = 0; j < n; j++){
			if (a[j]) vec.pb(j);
			if (vec.size() == k){
				ll d = inf;
				ll s = 0;
				for (int l = 0; l < vec.size(); l++) s += vec[l] - vec[0];
				ll m = vec.size();
				d = min(d, s);
				m--;
				for (int l = vec[0]+1; l <= vec[m-1]; l++){
					s += k - m - m;
					d = min(d, s);
					if (a[l]) m--;
				}
				g += d;
				vec.resize(0);
			}
			
		}
		ans = min(ans, g);
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	
	
	return 0;
}
/*
100
1 1 0 1 1 1 1 0 1 0 0 1 1 1 1 1 0 1 0 1 0 1 1 1 1 1 0 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 0 1 0 1 0 1 1 0 0 1 0 0 1 1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 0 0 1 0 1 1 1 1
*/