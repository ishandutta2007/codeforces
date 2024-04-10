#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10883;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
//const ll P = 104107;

ll mul(ll a, ll b){
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

int main(){
	ll t;
	cin >> t;
	ll n;
	str s;
	for(int i = 0; i< t;i++){
		bool fl = false;
		cin >> n >> s;
		for(int j = 0; j + 10 < n; j++){
			if(s[j] == '8') fl = true;
		}
		cout << (fl ? "YES\n" : "NO\n" );
	}
	return 0;
}