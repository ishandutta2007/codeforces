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
const int N=1e5+100 , M=30 , LG=30 , base=2;
const int MOD=1e9+7 , mod=1e9+9;
const ll  INF=1e9   , inf=1e18 ;
ll n,k , dp[N],x[N];
/*==========================================================================*/
int main()
{
    IOS;
    cin>>n>>k;
    for(int i=0;i<n;i++)   cin>>x[i];

    for(int i=1;i<n;i++)
        if(x[i]-x[i-1]>k)
            return cout<<-1 , 0;

    memset(dp,63,sizeof dp);
    dp[0]=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(x[i]-x[j]<=k)
                dp[i]=min(dp[j]+1,dp[i]);

    cout<<dp[n-1];
    return 0;
}