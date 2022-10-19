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

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		Loop(i,0,n) cout << i+2 << ' ';
		cout << '\n';
	}
}