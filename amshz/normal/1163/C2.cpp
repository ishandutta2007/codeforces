# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ld;
typedef pair <ld, ld> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e3+10;
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
 
int n;
ll x[xn], y[xn], ans;
vector <pii> vec;

map <pii, bool> mp;
map <ld, ll> cnt;
 
 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			ld a, b;
			if (x[j] - x[i] == 0){
				a = {1e5, 1};
				b = {x[i], 1};
			}
			else{
				a = {(y[j] - y[i]), (x[j] - x[i])};
				b = {(- x[i]) *(y[j] - y[i]),(x[j] - x[i])};
				int g = __gcd(a.F, a.S);
				a.F /= g, a.S /= g;
				b.F += y[i] * (x[j] - x[i]);
				g = __gcd(b.F, b.S);
				b.F /= g, b.S /= g;
			} 
			if (mp[{a, b}]) continue;
			mp[{a, b}] = true;
			vec.pb({a, b});
		}
	}
	ll t = vec.size();
	ans = t * (t - 1) / 2;
	for (int i = 0; i < vec.size(); i++){
		ld a = vec[i].F, b = vec[i].S;
		ans -= cnt[a];
		cnt[a]++;
	}
	
	cout << ans << endl;
	
	return 0;
}