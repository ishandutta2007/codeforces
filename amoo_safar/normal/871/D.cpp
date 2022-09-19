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
const int Maxn = 1e7 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int p[Maxn];

ll C2(ll x){
	return x * (x - 1) / 2LL;
}

ll ans[Maxn], sm[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2; i * i < Maxn; i++){
		if(p[i]) continue;
		for(ll j = i * i; j < Maxn; j += i)
			if(!p[j])
				p[j] = i;
	}
	for(int i = 2; i < Maxn; i++) if(!p[i]) p[i] = i;
	
	ll n;
	cin >> n;
	//n = 10000000;
	ll cnt;
	ll res = 0, rem = 0;
	for(int j = 2; j < Maxn; j++){
		if(p[j] + p[j] <= n && j <= n){
			rem ++;
			sm[p[j]] ++;
		}
	}
	
	for(int i = Maxn - 2; i > 0; i--) sm[i] += sm[i + 1];
	
	rem = C2(rem);
	for(int i = Maxn - 1; i > 1; i--){
		cnt = 0;
		for(int j = i; j < Maxn; j += i) cnt += (p[j] + p[j] <= n && j <= n);
		ans[i] = C2(cnt);
		for(int j = i + i; j < Maxn; j += i) ans[i] -= ans[j];
		res += ans[i];
		//if(ans[i]) cerr << "! " << i << " : " << ans[i] << '\n';
	}
	//cerr << res << '\n';
	//cerr << rem << '\n';
	rem -= res;
	cnt = 0;
	for(int i = 2; i <= n; i++){
		cnt += (sm[i] - sm[i + 1]) * sm[(n / i) + 1];
		if(1ll * i * i > n) cnt -= (sm[i] - sm[i + 1]);
	}
	
	res += (cnt / 2) * 3;
	rem -= (cnt / 2);
	cout << res + rem + rem << '\n';
	return 0;
}