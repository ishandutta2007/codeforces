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
const int xn = 1e5+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;


ll x, y, a, b, c, d;
ll v, u, t;
int mx;
vector <pll> vec;

ll del(pll x, pll y){
	return abs(x.F-y.F) + abs(x.S-y.S);
}

 
int main(){
	fast_io;
	
	cin >> x >> y >> a >> b >> c >> d;
	cin >> v >> u >> t;
	
	vec.pb({x, y});
	while (x < 1e16 && y < 1e16){
		x = a*x+c;
		y = b*y+d;
		vec.pb({x, y});
	}
	for (int i = 0; i < vec.size(); i++){
		for (int j = i; j < vec.size(); j++){
			for (int k = j; k < vec.size(); k++){
				ll s = del({v, u}, vec[j]);
				s += min(del(vec[i], vec[j]), del(vec[j], vec[k]));
				s += del(vec[i], vec[k]);
				if (s <= t) mx = max(mx, k-i+1);
			}
		}
	}
	
	cout << mx << endl;
	
	
	return 0;
}