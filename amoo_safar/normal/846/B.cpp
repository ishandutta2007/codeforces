#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll t[MAXN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, m;
    cin >> n >> k >> m;
	ll s = 0;
	for(int i = 0; i < k; i++){
		cin >> t[i];
		s+=t[i];
	}
	sort(t, t + k);
	ll ans = 0;
	ll cm, p;
	for(int i = 0; i <= n; i++){
		cm = m;
		cm -= (i * s);
		if(cm < 0) continue;
		p = (k + 1) * i;
		if(i == n){
			ans = max(ans, p);
			break;
		}
		for(int j = 0; j < k; j++){
			ll sl = min(n - i, cm / t[j]);
			p += sl;
			cm -= (sl * t[j]);
		}
		ans = max(ans, p);
	}
	cout << ans;
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;