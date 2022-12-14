/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-12-07 10:20:54
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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , k , A[MAXN] , cnt[MAXN] , cur , ql , qr , dp[LOG][MAXN];

void add(int x){
	cur += cnt[A[x]];
	cnt[A[x]]++;
}

void remove(int x){
	cnt[A[x]]--;
	cur -= cnt[A[x]];
}

void calc(int l , int r){
	while(qr < r)	add(++qr);
	while(ql > l)	add(--ql);
	while(qr > r)	remove(qr--);
	while(ql < l)	remove(ql++);
}

void solve(int k , int l , int r , int optl , int optr){
	if(l > r)	return;
	int mid = l + r >> 1;
	pll mn = {INF , 0};
	for(int i = min(optr , mid) ; i >= optl ; i--){
		calc(i , mid);
		mn = min(mn , pll(cur + dp[k - 1][i - 1] , i));
	}
	dp[k][mid] = mn.X;
	// cout << k << sep << mid << sep << dp[k][mid] << sep << mn.Y << sep << optl << sep << optr << endl;
	solve(k , l , mid - 1 , optl , mn.Y);
	solve(k , mid + 1 , r , mn.Y , optr);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	fill(dp[0] + 1 , dp[0] + MAXN , INF);
	ql = 1 , qr = 0;
	for(int i = 1 ; i <= k ; i++){
		solve(i , 1 , n , 1 , n);
	}
	cout << dp[k][n] << endl;

    return 0;
}
/*

*/