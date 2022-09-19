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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
ll a[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		ll ans = -1;
		
		for(int i = 0; i+1 < n; i++) if(abs(a[i] - a[i + 1]) > 1) ans = i;
		
		if(ans == -1) cout << "NO\n";
		else cout << "YES\n" << ans + 1 << " " << ans + 2 << '\n';
	}
	return 0;
}