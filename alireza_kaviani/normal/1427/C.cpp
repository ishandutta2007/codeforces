/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-10-10 18:20:02
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
const int MAX = 1010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int r , n , t[MAXN] , x[MAXN] , y[MAXN] , dp[MAXN] , mx[MAXN];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> r >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> t[i] >> x[i] >> y[i];
	}
	x[0] = y[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		dp[i] = -MOD;
		int A = max(0 , i - MAX);
		for(int j = A ; j < i ; j++){
			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]){
				dp[i] = max(dp[i] , dp[j] + 1);
			}
		}
		if(A){
			dp[i] = max(dp[i] , mx[A - 1] + 1);
		}
		mx[i] = max(mx[i - 1] , dp[i]);
	}
	cout << mx[n] << endl;

    return 0;
}
/*

*/