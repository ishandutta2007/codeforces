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

ll MOD = (ll) 1e9 + 9;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

int num(char c){
	return c - 'a' + 1;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, x, y;
	cin >> n >> x >> y;
	str s;
	cin >> s;
	ll cnt = 0;
	for(int i = 1; i<=x;i++) cnt += (s[n - i] == '1');
	cout << cnt + ( s[n - y - 1] == '1' ? -1 : 1 );
	return 0;
}