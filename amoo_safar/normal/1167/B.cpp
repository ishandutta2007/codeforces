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

ll a[10];


int main(){
	ll g = 0;	
	for(int i = 2; i <= 5; i++){
		cout << "? 1 " << i << endl;
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	if(g == 30 or g == 46) g /= 2ll;
	a[1] = g;
	for(int i = 2; i<=5; i++) a[i] /= a[1];
	a[6] = 108;
	for(int i = 1; i<=5;i++) a[6] -= a[i];
	cout << "! ";
	for(int i = 1; i<=6;i++) cout << a[i] << " ";
	cout << endl;
	
	return 0;
}