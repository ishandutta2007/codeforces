#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	str s; cin >> s;
	ll ans = 0, fl = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '>') fl = 0;
		ans += fl;
	}
	fl = 1;
	for(int i = n- 1; i >= 0; i--){
		if(s[i] == '<') fl = 0;
		ans += fl;
	}
	cout << ans;
	return 0;
}