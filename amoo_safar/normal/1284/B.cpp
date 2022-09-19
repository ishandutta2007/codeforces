#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> v;
ll a[Maxn], cnt[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll sz;
		cin >> sz;
		for(int j = 0; j < sz; j++) cin >> a[j];
		ll f = 1;
		for(int j = 0; j + 1 < sz; j++){
			if(a[j] < a[j + 1]) f = 0;
		}
		if(f == 1){
			cnt[a[0]]++;
			v.pb(a[sz - 1]);
			
		}
	}
	for(int i = 1; i < Maxn; i++) cnt[i] += cnt[i - 1];
	ll ans = n*n;
	for(auto x : v) ans -= cnt[x];
	cout << ans << '\n';
	return 0;
}