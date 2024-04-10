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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll dp[MAXN][4], a[MAXN], b[MAXN];
ll n;
bool check(ll x){
	for(int i = 1; i<=n; i++) b[i] = a[i];
	ll nd = 0;
	for(int i = n; i > 0; i--){
		ll po = min(2*x,b[i]) / 2ll;
		x-=po;
		b[i]-= (po + po);
		nd += po;
		nd -= b[i];
		nd = max(nd, 0ll);
	}
	//debug(x); debug(nd);
	return (x == 0) and (nd == 0);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//ll n;
	cin >> n;
	ll sm = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	check(3);
	ll l = -1, r = INF, mid;
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}