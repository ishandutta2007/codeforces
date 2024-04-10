/*     !ya khoda!     */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define ld long double

#define pp push
#define po pop()
#define pb push_back
#define pf push_front
#define pob pop_back()
#define pof pop_front()

#define F first
#define S second

#define mkp make_pair
#define pll pair<ll,ll>

#define coutghat(x)      cout<<tolower(x);
#define coutashar(x,d)   cout<<fixed<<setprecision(x)<<(ld)d
#define IOS ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
//#define poow(a,b,M)   b?(poow((a*a)%M,b/2)%M * (b&1?a))%M:1 ;
/*==========================================================================*/
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#pragma optimize O3
// 107,109, 211,223, 307, 401,409, 503,509, 601,607, 701,709, 809, 907, 1009
/*==========================================================================*/
const int N=1e6+100 , M=26 , LG=30 , base=2;
const int MOD=1e9+7 , mod=1e9+9;
const ll  INF=1e9   , inf=1e18 ;
ll x,ans , m[N];
vector<ll>p[N];
bool vis[N];
/*==========================================================================*/
int main()
{
    IOS;
	for(int i=2;i<N;i++)
		if(!vis[i])
			for(int j=i*2;j<N;j+=i)
				vis[j]=1 , p[j].pb(i);

	for(int i=3;i<N;i++)
    {
		m[i]=INF;
		for(auto a:p[i])
			m[i]=min( m[i],max(i-a+1,a+1) );
	}

	cin>>x , ans=x;
	for(auto a:p[x])
		for(int i=max(x-a+1,a+1) ; i<=x ; i++)
			ans=min(ans,m[i]);

	cout<<ans;
	return 0;
}