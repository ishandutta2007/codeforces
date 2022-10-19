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

const int N = 5e6+10;
int cnt[N], cntm[N];
ll dp[N];
int n;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(ll x=1; x<N; ++x){
		cntm[x]=cnt[x];
		for(ll y=2*x; y<N; y+=x)
			cntm[x] += cnt[y];
	}
	dp[1]=n;
	for(ll y=1; y<N; ++y){
		for(ll x=2*y; x<N; x+=y)
			dp[x] = max(dp[x], dp[y]+(x-y)*cntm[x]);
	}
	ll ans=0;
	Loop(i,1,N) ans=max(ans,dp[i]);
	cout << ans << '\n';
}