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

const int N = 100'010;
ll dp1[N], dp2[N];
int a[N];
int d[N];
int n, m, p;

const ll inf = 1e18;

void up(int l, int r, int b, int e){
	if(l>=r) return;
	ll mn = inf; int mni=b;
	int m = (l+r)/2;
	Loop(i,b,min(e,m+1))
		if(dp1[i] + a[m-1]*(m-i) < mn)
			mn = dp1[i] + a[m-1]*(m-i), mni=i;
	dp2[m] = mn;
	up(l,m,b,mni+1);
	up(m+1,r,mni,e);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> p;
	Loop(i,1,n) cin >> d[i], d[i]+=d[i-1];
	Loop(i,0,m){
		int h, t;
		cin >> h >> t; --h;
		a[i] = t-d[h];
	}
	sort(a, a+m);
	Loop(i,1,N) dp1[i]=i*a[i-1];
	while(--p) {
		up(0,m+1,0,m+1);
		Loop(i,0,N) dp1[i] = dp2[i];
	}
	ll ans = dp1[m];
	Loop(i,0,m) ans -= a[i];
	cout << ans << '\n';
}