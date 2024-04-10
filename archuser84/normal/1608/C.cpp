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

void _dbg(){}
template<class T, class... U> void _dbg(T x, U... y){
	cout << x << ' ';
	_dbg(y...);
}
template<class... T> void dbg(T... x){
	#ifdef DBG
	cout << "dbg: ";
	_dbg(x...);
	cout << '\n';
	#endif
}
template<class... T> void vdbg(T... x){
	#ifdef VRB
	cout << "vdbg: ";
	_dbg(x...);
	cout << '\n';
	#endif
}

const int N = 100'010;
tuple<int,int,int> a[N];
bool ans[N];
int mx[N];

void solve()
{
	int n;
	cin >> n;
	Loop(i,0,n) cin >> get<0>(a[i]);
	Loop(i,0,n) cin >> get<1>(a[i]);
	Loop(i,0,n) get<2>(a[i]) = i;
	memset(ans,0,n);
	sort(a,a+n,greater<tuple<int,int,int>>());
	mx[n] = -1;
	LoopR(i,0,n) mx[i] = max(mx[i+1], get<1>(a[i]));
	ans[get<2>(a[0])]=1;
	int mn = get<1>(a[0]);
	Loop(i,1,n)
	{
		if(mx[i] < mn) break;
		mn = min(mn, get<1>(a[i]));
		ans[get<2>(a[i])]=1;
	}
	Loop(i,0,n) cout << ans[i];
	cout << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}