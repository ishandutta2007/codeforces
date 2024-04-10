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

ll n, a[Maxn];

ll ans = Inf;

void check(ll x){
	if(x == 1) return ;
	ll res = 0;
	ll s = 0;
	for(int i = 1; i <= n; i++){
		s += a[i];
		res += min(s % x, x - (s % x));
	}
	//cerr << x << " " << res << '\n';
	ans = min(res, ans);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	ll s = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s += a[i];
	}
	if(s < 2) return cout << -1, 0;
	//ll ans = Inf;
	ll d = 2;
	while(d*d <= s){
		while(s % d == 0){
			check(d);
			s /= d;
		}
		d++;
	}
	if(s > 1) check(s);
	cout << ans << '\n';
	return 0;
}