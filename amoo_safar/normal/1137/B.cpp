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

const ll MOD = (ll) 179426549;
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) LONG_LONG_MAX;
const ld EPS = (ld) 1e-8;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p % 2 == 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}

ll phs[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll inv = pw(2, MOD - 2);
	
	str s, t;
	cin >> s >> t;
	ll n = s.size();
	ll m = t.size();
	ll hs = 0;
	for(int i = 1; i <= m; i++){
		phs[i] = 2ll * phs[i - 1];
		if(t[i - 1] == '1'){
			phs[i] ++;
		}
		phs[i] %= MOD;
		//debug(phs[i]);
	}
	ll x = 1;
	ll la = 0;
	ll j = 0;
	ll has = 0;
	for(int i = m; i > 1; i--){
		if(t[i - 1] == '1') has += pw(2 ,j);
		has %= MOD;
		if(has == phs[x]){
			la = x;
		}
		j++;
		x++;
		
	}
	ll c1 = 0;
	ll c0 = 0;
	for(auto x : s){
		if(x == '0') c0 ++;
		else c1 ++;
	}
	ll n0 = 0;
	ll n1 = 0;
	for(int i = m - 1; i > m - 1 - (m- la);i--){
		if(t[i]=='0') n0 ++;
		else n1++;
	}
	//debug(n0); debug(n1);
	ll cc0 = 0;
	ll cc1 = 0;
	for(auto x : t){
		if(x == '0') cc0 ++;
		else cc1 ++;
	}
	if((cc1 > c1) or (cc0 > c0)){
		return cout << s, 0;
	}
	cout << t;
	c1 -= cc1;
	c0 -= cc0;
	while((c0>=n0) and (c1>=n1)){
		for(int j = m - (m - la); j < m;j++) cout << t[j];
		c0 -= n0;
		c1 -= n1;
		//debug(n1);
	}
	for(int i = 0; i < c0; i++) cout << '0';
	for(int i = 0; i < c1; i++) cout << '1';
	return 0;
}