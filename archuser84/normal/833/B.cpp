///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("O3,unroll-loops,no-tree-loop-distribute-patterns")
#pragma GCC target("avx2")
#define max(x,y) ((x)>(y)?(x):(y))

const int N = 35008;
const int K = 50;
unsigned short dp1[N], dp2[N], a[N], lst[N];
int n, k;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,0,n) cin >> a[i], a[i]--;
	Loop(i,0,n) dp1[i+1] = dp1[i]+(!lst[a[i]]), lst[a[i]]=1;
	Loop(j,1,k){
		Loop(i,0,n) lst[i] = 0;
		dp1[0]=dp2[0]=0;
		Loop(i,0,n){
			#define update(dp1, dp2) {\
				Loop(z,lst[a[i]],i+1) ++dp1[z]; \
				lst[a[i]]=i+1; \
				unsigned short x = 0; \
				Loop(z,0,i+1) \
					x = max(x, dp1[z]); \
				dp2[i+1] = x; }
			if(j&1) update(dp1, dp2) else update(dp2, dp1)
			#undef update
		}
	}
	cout << (k&1? dp1[n]: dp2[n]) << '\n';
}