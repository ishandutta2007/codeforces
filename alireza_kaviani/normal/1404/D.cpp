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
//#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , A[MAXN] , P[MAXN] , ind[MAXN] , mark[MAXN];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	if(n % 2 == 0){
		cout << "First" << endl;
		for(int i = 1 ; i <= n + n ; i++){
			cout << i % n + 1 << sep;
		}
		cout << endl;
		return 0;
	}
	cout << "Second" << endl;
	for(int i = 1 ; i <= n + n ; i++){
		cin >> P[i];
		if(ind[P[i]] != 0){
			A[i] = ind[P[i]];
			A[ind[P[i]]] = i;
		}
		ind[P[i]] = i;
	}
	for(int i = 1 ; i <= n + n ; i++){
		if(mark[i % n])	continue;
		int x = i;
		while(1){
			if(mark[x % n])	break;
			mark[x % n] = 1;
			ans.push_back(x);
			x = A[x];
			if(x > n)	x -= n;
			else	x += n;
		}
	}
	ll sum = 0;
	for(int i : ans)	sum += i;
	if(sum % 2 == 1){
		fill(mark , mark + MAXN , 0);
		for(int i : ans)	mark[i] = 1;
		for(int i = 1 ; i <= n + n ; i++){
			if(!mark[i]){
				cout << i << sep;
			}
		}
		cout << endl;
		return 0;
	}
	for(int i : ans)	cout << i << sep;
	cout << endl;

    return 0;
}
/*

*/