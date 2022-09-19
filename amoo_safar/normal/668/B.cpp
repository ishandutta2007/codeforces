#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll ans[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	ll p1 = 0;
	ll p2 = 1;
	ll t, x;
	for(int i =0 ;i < q; i++){
		cin >> t;
		if(t == 1) {
			cin >> x;
			p1 += x;
			p2 += x;
		} else {
			p1 ^= 1;
			p2 ^= 1;
		}
		p1 += n;
		p2 += n;
		p1 %= n;
		p2 %= n;
	}
	for(int j = 1; j <= n; j += 2){
		ans[p1] = j;
		p1 += 2;
		p1 %= n;
	}
	
	for(int j = 2; j <= n; j += 2){
		ans[p2] = j;
		p2 += 2;
		p2 %= n;
	}
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	
	return 0;
}