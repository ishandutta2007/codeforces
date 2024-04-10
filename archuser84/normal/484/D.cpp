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
using namespace std;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	ll n, dp=0, madeinheaven = -1e18, stonefree = -1e18;
	cin >> n;
	while(n--)
	{
		ll x;
		cin >> x;
		auto tmp1 = madeinheaven, tmp2 = stonefree;
		madeinheaven = max(madeinheaven, dp-x);
		stonefree = max(stonefree, dp+x);
		dp = max({dp, x+tmp1, tmp2-x});
		//cout << dp << ' '<<madeinheaven<<' '<<stonefree<<'\n';
	}
	cout << dp << '\n';
}