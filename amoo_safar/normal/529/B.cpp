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
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll h[Maxn], w[Maxn];
vector<ll> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll mn = 1;
	for(int i = 0; i < n; i++){
		cin >> w[i] >> h[i];
		mn = max(mn, min(h[i], w[i]));
	}
	ll W, rem, ans = Inf;
	for(int H = mn; H <= 1000; H++){
		rem = n/2;
		W = 0;
		v.clear();
		for(int i = 0; i < n; i++){
			if(h[i] <= H){
				W += w[i];
				if(w[i] <= H){
					v.pb(h[i] - w[i]);
				}
			} else {
				rem --;
				W += h[i];
			}
		}
		if(rem < 0) continue;
		sort(all(v));
		for(int i = 0; i < min(rem, (ll) v.size()); i++){
			if(v[i] < 0) W += v[i];
		}
		ans = min(ans, H * W);
	}
	cout << ans;
	return 0;
}