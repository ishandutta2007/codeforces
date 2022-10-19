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

int cnt(int x, int i)
{
	int y = x/(2<<i);
	x -= y*(2<<i);
	return y*(1<<i) + min(x, 1<<i);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r; ++ r;
		int ans = 1000000000;
		Loop(i,0,31){
			ans = min(ans, cnt(r,i) - cnt(l,i));
		}
		cout << ans << '\n';
	}
}