/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-09-06 19:05:01
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int q , n , k , val[MAXN];
string s;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> k >> s;
		fill(val , val + k , -1);
		int flag = 1;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){
				if(val[i % k] == 1)	flag = 0;
				val[i % k] = 0;
			}
			if(s[i] == '1'){
				if(val[i % k] == 0)	flag = 0;
				val[i % k] = 1;
			}
		}
		if(flag == 0){
			cout << "NO" << endl;
			continue;
		}
		int cnt0 = 0 , cnt1 = 0;
		for(int i = 0 ; i < k ; i++){
			if(val[i] == 0)	cnt0++;
			if(val[i] == 1)	cnt1++;
		}
		if(max(cnt0 , cnt1) > k / 2){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}

    return 0;
}
/*

*/