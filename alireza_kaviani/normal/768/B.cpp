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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , l , r;

ll calc(ll n){
	if(n <= 1)	return 1;
	return 2 * calc(n / 2) + 1;
}

ll solve(ll n , ll l , ll r){
	ll all = calc(n) , half = all / 2 + 1;
//	cout << n << sep << all << sep << half << endl;
	r = min(r , all);
	if(r < l || r <= 0)	return 0;
	if(n <= 1)	return n;
	ll ans = solve(n / 2 , l , r) + (n % 2) * (l <= half && half <= r) + solve(n / 2 , l - half , r - half);
//	cout << n << sep << l << sep << r << sep << ans << endl;
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> l >> r;
	cout << solve(n , l , r) << endl;

    return 0;
}
/*

*/