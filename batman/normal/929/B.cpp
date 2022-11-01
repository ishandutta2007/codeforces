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
const int N=1e3+100 , M=30 , LG=30 , base=2;
const int MOD=1e9+7 , mod=1e9+9;
const ll  INF=1e9   , inf=1e18 ;
ll n,k , cnt,ans;
string s[N];
vector< pair<ll,pll> >v;
/*==========================================================================*/
int main()
{
    IOS;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>s[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<s[i].size();j++)
            if(s[i][j]=='.')
            {
                cnt=0;
                if(j!=0 && s[i][j-1]=='S')
                    cnt++;
                if(j!=s[i].size()-1 && s[i][j+1]=='S')
                    cnt++;
                v.pb(  {cnt , {i,j} }  );
            }

    sort(v.begin(),v.end());
    for(int i=0;i<k;i++)
        s[v[i].S.F][v[i].S.S] = 'x';

    for(int i=0;i<n;i++)
        for(int j=0;j<s[i].size();j++)
            if(s[i][j]=='S')
            {
                if(j!=0 && s[i][j-1]!='.' && s[i][j-1]!='-')
                    ans++;
                if(j!=s[i].size()-1 && s[i][j+1]!='.' && s[i][j+1]!='-')
                    ans++;
            }

    cout<<ans<<"\n";
    for(int i=0;i<n;i++)
        cout<<s[i]<<"\n";
    return 0;
}