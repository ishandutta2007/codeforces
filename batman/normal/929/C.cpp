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
ll g,d,f , a[N],b[N],c[N] , ans;
/*==========================================================================*/
int main()
{
    IOS;
    cin>>g>>d>>f;
    for(int i=0;i<g;i++)   cin>>a[i];
    for(int i=0;i<d;i++)   cin>>b[i];
    for(int i=0;i<f;i++)   cin>>c[i];
    sort(a,a+g) , sort(b,b+d) , sort(c,c+f);
    if(d<2 || f<3)   return cout<<0 , 0;
/*===============   _FOR1_   ===============*/
    for(int i=0;i<d;i++)
    {
        for(int j=i+1;j<d;j++)
        {   ll p1,p2 , d1,d2;
            if(b[j]>2*b[i])
                continue;
            p1 = upper_bound(a,a+g,b[i]) - a;
            p2 = lower_bound(a,a+g,b[j]) - (a+1);
            d1 = max(0LL,p2-p1+1);

            p1 = upper_bound(c,c+f,b[i]) - a;
            p2 = lower_bound(c,c+f,b[j]) - (a+1);
            d2 = max(0LL,p2-p1+1);
            ans += d1*d2 * (d2-1)*(d2-2) / 6;
        }
    }
/*===============   _FOR2_   ===============*/
    for(int i=0;i<f;i++)
    {
        for(int j=i+1;j<f;j++)
        {   ll p1,p2 , d1,d2,d3;
            if(c[j]>2*c[i])
                continue;
            p1 = upper_bound(a,a+g,c[i]) - a;
            p2 = lower_bound(a,a+g,c[j]) - (a+1);
            d1 = max(0LL,p2-p1+1);

            p1 = upper_bound(b,b+d,c[i]) - b;
            p2 = lower_bound(b,b+d,c[j]) - (b+1);
            d2 = max(0LL,p2-p1+1);

            p1 = upper_bound(c,c+f,c[i]) - c;
            p2 = lower_bound(c,c+f,c[j]) - (c+1);
            d3 = max(0LL,p2-p1+1);

            ans += d1*d2*d3 * (d2-1)/2;
        }
    }
/*===============   _FOR3_   ===============*/
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<d;j++)
        {   ll p,q  ,  p1,p2 , d1,d2;

            p=min(a[i],b[j])  ,  q=max(a[i],b[j]);
            if(q>p*2)
                continue;

            p1 = upper_bound(b,b+d,p) - b;
            p2 = lower_bound(b,b+d,q) - (b+1);
            d1 = max(0LL,p2-p1+1);

            p1 = upper_bound(c,c+f,p) - c;
            p2 = lower_bound(c,c+f,q) - (c+1);
            d2 = max(0LL,p2-p1+1);

            ans += d1*d2 * (d2-1)*(d2-2) / 6;
        }
    }
/*===============   _FOR4_   ===============*/
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<f;j++)
        {   ll p,q  ,  p1,p2 , d1,d2;

            p=min(a[i],c[j])  ,  q=max(a[i],c[j]);
            if(q>p*2)
                continue;

            p1 = upper_bound(b,b+d,p) - b;
            p2 = lower_bound(b,b+d,q) - (b+1);
            d1 = max(0LL,p2-p1+1);

            p1 = upper_bound(c,c+f,p) - c;
            p2 = lower_bound(c,c+f,q) - (c+1);
            d2 = max(0LL,p2-p1+1);

            ans += d1*d2 * (d1-1)*(d2-1) / 4;
        }
    }
/*===============   _FOR5_   ===============*/
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<f;j++)
        {   ll p,q  ,  p1,p2 , d1,d2,d3;

            p=min(b[i],c[j])  ,  q=max(b[i],c[j]);
            if(q>2*p)
                continue;

            p1 = upper_bound(a,a+g,p) - a;
            p2 = lower_bound(a,a+g,q) - (a+1);
            d1 = max(0LL,p2-p1+1);

            p1 = upper_bound(c,c+f,p) - c;
            p2 = lower_bound(c,c+f,q) - (c+1);
            d2 = max(0LL,p2-p1+1);

            p1 = upper_bound(b,b+d,p) - b;
            p2 = lower_bound(b,b+d,q) - (b+1);
            d3 = max(0LL,p2-p1+1);

            ans += d1*d2*d3 * (d2-1) / 2;
        }
    }
/*===============   ^__^   ===============*/
  cout<<ans;
  return 0;
}