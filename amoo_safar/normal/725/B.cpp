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
	char x;
	cin >> n >> x;
	ll ans = 0;
	if(n % 4 == 0){
		ans += (n - 3) + 12 * ((n - 1) / 4) + 6;
	}
	if(n % 4 == 3){
		ans += (n - 3) + 12 * ((n - 1) / 4);
	}
	if(n % 4 == 1){
		ans += (n - 1) + 12 * ((n - 1) / 4);
	}
	if(n % 4 == 2){
		ans += (n - 1) + 12 * ((n - 1) / 4) + 6;
	}
	ll d[] = {3,4,5,2,1,0};
	cout << ans + d[x - 'a'] + 1;
	return 0;
}