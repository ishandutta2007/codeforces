/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-10-27 11:21:02
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 4e18 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll k , t , d;

ll check(ll x){
	ll A = (k + t - 1) / t * t;
	ll B = A + k;
	ll res = x / A * B + x % A + min(x % A , k);
	return res >= d;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> k >> t >> d;
	k *= 2; t *= 2; d *= 4;
	ll l = 0 , r = INF;
	while(r - l > 1){
		ll mid = l + r >> 1;
		if(check(mid))	r = mid;
		else	l = mid;
	}
	cout << fixed << setprecision(10) << double(r) / double(2) << endl;

    return 0;
}
/*

*/