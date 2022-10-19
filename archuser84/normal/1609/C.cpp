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

const int N = 200'010;
const int M = 1000'010;
vector<int> dard[N];
bool prm[M];

void sieve()
{
	memset(prm, 1, sizeof prm);
	prm[0] = prm[1] = 0;
	for(ll x=2; x*x<M; ++x)
	{
		if(!prm[x]) continue;
		for(ll y=x*x; y<M; y += x)
			prm[y] = 0;
	}
}

ll count(int i){
	ll l = 0;
	ll p = -1;
	ll ans = 0;

	dard[i].push_back(4);
	Loop(j,0,dard[i].size())
	{
		if(prm[dard[i][j]]){
			if(p==-1) p=j;
			else {
				ans += (p-l+1)*(j-p)-1;
				l = p+1;
				p = j;
			}
		} else if(dard[i][j] != 1) {
			if(p!=-1) ans += (p-l+1)*(j-p)-1;
			l = j+1;
			p = -1;
		}
	}

	return ans;
}

void solve()
{
	ll n, e;
	cin >> n >> e;
	Loop(i,0,e) dard[i].clear();
	Loop(i,0,n){
		int x;
		cin >> x;
		dard[i%e].push_back(x);
	}
	ll ans = 0;
	Loop(i,0,e) ans += count(i);
	cout << ans << '\n';
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int q;
	cin >> q;
	sieve();
	while(q--) solve();
}