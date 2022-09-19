#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 92233720368545;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, h;
	cin >> n >> h;
	for(int i = 0; i< n; i++) cin >> a[i];
	ll ans = 0;
	for(int k = 0; k <= n; k++){
		sort(a,a + k);
		ll s = 0;
		for(int i = (1 - (k % 2)); i < k; i += 2) s += a[i];
		if(s<=h) ans = k;
		//debug(s);
	}
	cout << ans;
	return 0;
}