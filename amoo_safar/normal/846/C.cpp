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
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN], ps[MAXN];

ll sum(ll l, ll r){
	return ps[r] - ps[l];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	ps[0] = 0;
	for(int i = 1;i <= n;i++) ps[i] = ps[i -1] + a[i - 1];
	ll a = 0,b = 0,c = 0;
	ll ans = -INF;
	ll aa,bb,cc;
	for(int i = 0;i<= n;i++){
		ll mx1 = -INF, mx2 = -INF;
		aa = bb = cc = 0;
		for(int j = 0; j <= i; j++){
			if(sum(0, j) - sum(j, i) > mx1){
				mx1 = sum(0, j) - sum(j, i);
				aa = j;
			}
		}
		
		for(int j = i; j <= n; j ++){
			if(sum(i, j) - sum(j, n) > mx2){
				mx2 = sum(i, j) - sum(j, n);
				cc = j;
			}
		}
		if(mx1 + mx2 > ans){
			ans = mx1 + mx2;
			a = aa;
			b = i;
			c = cc;
		}
	}
	cout << a << " " << b << " " << c;
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;