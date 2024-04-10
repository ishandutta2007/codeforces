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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll ans = 0, s = 0, cnt = 0;
	for(int i = 0; i< n; i++){
		cin >> a[i];
		s += a[i];
	}
	ans = s;
	for(int i = 0;i<n;i++){
		s-=a[i];
		if(a[i] == 0) cnt ++;
		ans = max(ans, cnt + s);
	}
	cout << ans;
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;