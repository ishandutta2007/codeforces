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

const ll MOD = (ll) 179426549;
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) LONG_LONG_MAX;
const ld EPS = (ld) 1e-8;

pll seg[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> seg[i].F >> seg[i].S;
	}
	//ll k;
	cin >> k;
	ll ans = 0;
	for(int i = 0; i < n;i++){
		if(k<=seg[i].S) ans ++;
	}
	cout << ans;
	return 0;
}