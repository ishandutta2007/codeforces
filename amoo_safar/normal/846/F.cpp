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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll rec[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ld ans = 0;
    ll n;
    cin >> n;
    ll v;
    for(int i = 1; i <= n; i++){
		cin >> v;
		ll all = 2 * (i - rec[v]) * (n - i + 1) - 1;
		ld pr = 1.0 * all / (n * n);
		rec[v] = i;
		ans += pr;
	}
    cout << fixed << setprecision(16) << ans;
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;