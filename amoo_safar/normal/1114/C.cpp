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
const ll MAXN = (ll) 5e4 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
 
ll calc(ll n, ll k){
	//debug(k);
	ll res = 0;
	while(n > 0){
		res += (n / k);
		n /= k;
	}
	return res;
} 

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, b;
    cin >> n >> b;
    ll i = 2;
    ll ans = INF;
    while(i * i <= b){
		ll cnt = 0;
		while(b % i == 0){
			cnt ++;
			b /= i;
		}
		if(cnt > 0){
			ans = min(ans, calc(n, i) / cnt);
		}
		i++;
	}
	if(b > 1){
		ans = min(ans, calc(n, b));
	}
	cout << ans;
    return 0;
}