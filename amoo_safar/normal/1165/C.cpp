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

ll a[MAXN];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	str s, t;
	cin >> s;
	t = "";
	char last = '.';
	for(int i = 0; i< n;i++){
		if(last == '.'){
			last = s[i];
			continue;
		}
		if(last != s[i]){
			t += last;
			t += s[i];
			last = '.';
		} else {
			last = s[i];
		}
	}
	cout << n - t.size() << '\n' << t;
	return 0;
}