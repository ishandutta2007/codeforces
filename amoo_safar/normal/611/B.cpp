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
const int Maxn = 2e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll n = 0;
	ll ans = 0;
	for(int l = 2; l <= 60; l++){
		for(int j = 0; j < l - 1; j++){
			n = (1ll << l) - 1;
			n ^= (1ll << j);
			if((a <= n) && (n <= b)) ans ++;
		}
	}
	cout << ans;
	return 0;
}