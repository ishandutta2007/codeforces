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

ll Solve(ll n, ll l, ll x){
	ll t = (l + 1) / 2;
	ll t2 = l / 2;
	if(x - t < 0) return 0;
	if(x + t2 > n) return n - l;
	return x - t;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	ll g = __gcd(a, b);
	a /= g;
	b /= g;
	ll x1, y1;
	ll k = min(n / a, m / b);
	a *= k;
	b *= k;
	x1 = Solve(n, a, x);
	y1 = Solve(m, b, y);
	//cerr << a << " " << b << '\n';
	cout << x1 << " " << y1 << " " << x1 + a << " " << y1 + b << '\n';

	return 0;
}