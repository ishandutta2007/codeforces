///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#define int ll

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> a;
		ll cnt = 0;
		Loop(i,0,n){
			ll x;
			cin >> x;
			ll z = __builtin_ctzll(x);
			cnt += z;
			x >>= z;
			a.push_back(x);
		}
		sort(a.begin(), a.end(), greater<ll>());
		ll ans = a[0]<<cnt;
		Loop(i,1,n) ans += a[i];
		cout << ans << '\n';
	}
}