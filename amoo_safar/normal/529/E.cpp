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
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

bitset<10000010> mk;
ll a[Maxn];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		a[i] = v;
		mk[v] = 1;
	}
	ll q;
	cin >> q;
	ll rem;
	int ans;
	for(int i = 0; i < q; i++){
		cin >> v;
		ans = k + 1;
		for(int ind = 0; ind < n; ind ++){
			for(int c = 1; c <= k; c++){
				rem = v - (c * a[ind]);
				if(rem < 0) break;
				if(rem == 0){
					ans = min(ans, c);
					break;
				}
				for(int c2 = 1; c2 + c <= k; c2++){
					if(rem % c2) continue;
					if(rem/c2 > 10000003) continue;
					if(mk[rem/c2]) ans = min(ans, c2 + c);
				}
			}
		}
		cout << (ans <= k ? ans : -1) << '\n';
	}
	return 0;
}