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

ll st[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	fill(st, st + MAXN, 1);
	ll ans = 0;
	ans = 2;
	ans += min(k - 1, n - k) + n - 1;
	ans += n;
	ans += n - 1;
	cout << ans;
	return 0;
}