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
const ll LOG = 61;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , xr , A[MAXN] , B[MAXN] , ans[MAXN] , ind[LOG] , val[LOG];
vector<pll> vec;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		xr ^= A[i];
		ans[i] = 1;
	}
	for(int i = 0 ; i < LOG ; i++){
		if(xr & (1ll << i)){
			vec.push_back({0 , i});
		}
		else{
			vec.push_back({1 , i});
		}
	}
	sort(all(vec));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < LOG ; j++){
			int x = vec[j].Y;
			if(A[i] & (1ll << x))   B[i] |= (1ll << j);
		}
	}
	for(int i = 1 ; i <= n ; i++){
		ll v = 0;
		for(int j = LOG - 1 ; j >= 0 ; j--){
			if((B[i] & (1ll << j)) == 0)    continue;
			B[i] ^= B[ind[j]];
			v ^= val[j];
			if(ind[j] == 0){
				ind[j] = i;
				val[j] = v ^ (1ll << j);
				break;
			}
		}
	}
	ll res = 0;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if((res ^ B[ind[i]]) > res){
			for(int j = 0 ; j < LOG ; j++){
				if(val[i] & (1ll << j)){
					ans[ind[j]] ^= 3;
				}
			}
			res ^= B[ind[i]];
		}
	}
	for(int i = 1 ; i <= n ; i++)	cout << ans[i] << sep;

	return 0;
}
/*

*/