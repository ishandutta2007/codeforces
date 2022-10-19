#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

ll n , m , k , G , L , A[MAXN] , B[MAXN] , posA[MAXN] , posB[MAXN];
vector<ll> vec;

ll check(ll x){
	ll ans = x , md = x % L , dv = x / L;
	for(ll i : vec){
		if(i < md)	ans -= dv + 1;
		else	ans -= dv;
	}
	return (ans >= k);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(posA , posA + MAXN , -1);
	fill(posB , posB + MAXN , -1);

	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
		posA[A[i]] = i;
	}
	for(int i = 0 ; i < m ; i++){
		cin >> B[i];
		posB[B[i]] = i;
	}
	G = __gcd(n , m);
	L = n * m / G;
	for(int i = 0 ; i < MAXN ; i++){
		if(posA[i] == -1 || posB[i] == -1)	continue;
		ll x = posA[i] , y = posB[i];
		if(x % G != y % G)	continue;
		ll pos = crt(x , n , y , m);
		vec.push_back(pos);
	}
	sort(all(vec));
	ll l = 0 , r = INF;
	while(r - l > 1){
		ll mid = l + r >> 1;
		if(check(mid))	r = mid;
		else	l = mid;
	}
	cout << r << endl;

    return 0;
}
/*

*/