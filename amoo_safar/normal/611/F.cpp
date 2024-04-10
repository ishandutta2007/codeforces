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
const int Maxn = 5e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp1[Maxn], dp2[Maxn];
ll sh[Maxn], sw[Maxn];
ll pmn[Maxn], pmx[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fill(dp1, dp1 + Maxn, Inf);
	fill(dp2, dp2 + Maxn, Inf);
	
	ll n, h, w;
	cin >> n >> h >> w;
	str s;
	cin >> s;
	s = '!' + s;
	for(int i = 1; i <= n; i++){
		sw[i] = sw[i - 1] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
		sh[i] = sh[i - 1] + (s[i] == 'D' ? 1 : (s[i] == 'U' ? -1 : 0));
	}
	if(sw[n] < 0){
		for(int i = 0; i <= n; i++) sw[i] = -sw[i];
	}
	if(sh[n] < 0){
		for(int i = 0; i <= n; i++) sh[i] = -sh[i];
	}
	
	pmn[0] = 0;
	for(int i = 1; i <= n; i++) pmn[i] = min(pmn[i - 1], sh[i]);
	pmx[0] = 0;
	for(int i = 1; i <= n; i++) pmx[i] = max(pmx[i - 1], sh[i]);
	
	ll l, r, mid;
	for(int i = h; i > 0; i--){
		if(i + pmx[n] <= h && i + pmn[n] > 0) dp1[i] = dp1[i + sh[n]] + n;
		else {
			l = 0; r = n;
			while(l + 1 < r){
				mid = (l + r) >> 1;
				if(i + pmx[mid] <= h && i + pmn[mid] > 0) l = mid;
				else r = mid;
			}
			dp1[i] = r;
		}
	}
	//for(int i = 1; i <= h; i++) cerr << dp1[i] << ' ';
	//cerr << '\n';
	
	pmn[0] = 0;
	for(int i = 1; i <= n; i++) pmn[i] = min(pmn[i - 1], sw[i]);
	pmx[0] = 0;
	for(int i = 1; i <= n; i++) pmx[i] = max(pmx[i - 1], sw[i]);
	
	for(int i = w; i > 0; i--){
		if(i + pmx[n] <= w && i + pmn[n] > 0) dp2[i] = dp2[i + sw[n]] + n;
		else {
			l = 0; r = n;
			while(l + 1 < r){
				mid = (l + r) >> 1;
				if(i + pmx[mid] <= w && i + pmn[mid] > 0) l = mid;
				else r = mid;
			}
			dp2[i] = r;
		}
	}
	//for(int i = 1; i <= w; i++) cerr << dp2[i] << ' ';
	//cerr << '\n';
	ll mx1 = *max_element(dp1 + 1, dp1 + h + 1);
	ll mx2 = *max_element(dp2 + 1, dp2 + w + 1);
	//cerr << mx1 << ' ' << mx2 << '\n';
	if((mx1 == mx2) && (mx1 >= Inf)) return cout << -1, 0;
	
	ll ans = 0;
	sort(dp1 + 1, dp1 + h + 1);
	sort(dp2 + 1, dp2 + w + 1);
	ll cnt = 0;
	for(int i = 1; i <= h; i++){
		cnt = (lower_bound(dp2 + 1, dp2 + w + 1, dp1[i]) - dp2) - 1;
		cnt = w - cnt;
		//cerr << cnt << '\n';
		ans += cnt * (dp1[i] % Mod);
		ans %= Mod;
	}
	//cerr << ans << '\n';
	for(int i = 1; i <= w; i++){
		cnt = lower_bound(dp1 + 1, dp1 + h + 1, dp2[i]) - dp1 - 1;
		cnt = h - cnt;
		
		ans += cnt * (dp2[i] % Mod);
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}