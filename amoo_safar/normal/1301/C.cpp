#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N], n;
ll C2(ll x){
	return x*(x - 1) / 2ll;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		ll n, m;
		cin >> n >> m;
		ll c0 = n - m;
		ll ans = C2(n + 1);
		ll k = c0 / (m + 1);
		ll r = c0 % (m + 1);
		ans -= r * C2(k + 2);
		ans -= (m + 1 - r) * C2(k + 1);
		
		cout << ans << '\n';
	}
	return 0;
}