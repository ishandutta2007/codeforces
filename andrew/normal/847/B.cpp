#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef int ll;
ll pz,uk,p[5000000],i,j,n,m,k,sc,x,a[1000000],b[1000000],a1,b1,c1,v[1000000];
void modify(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        p[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
    p[v]=max(p[v*2],p[v*2+1]);
}
void get(ll v,ll tl,ll tr,ll l,ll r,ll kek)
{
    if(tl==tr)
    {
        pz=tl;
        return;
    }
    ll tm=(tl+tr)/2;
    if(tm>=l && p[v*2]>kek)get(v*2,tl,tm,l,r,kek);
    if(pz)return;
    if(tm+1<=r && p[v*2+1]>kek)get(v*2+1,tm+1,tr,l,r,kek);
    return;
}
int main() {
    ll l1,r1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
   for(i=1;i<=n;i++)cin >> a[i];
   for(i=1;i<5000000;i++)p[i]=-1e9;
    for(i=1;i<=n;i++)modify(1,1,n,i,a[i]);
    for(i=1;i<=n;i++)if(!v[i])
    {
        uk=i;
        while(1)
        {
            cout << a[uk] << " ";
            pz=0;
            v[uk]=1;
            modify(1,1,n,uk,-1e9);
            get(1,1,n,uk,n,a[uk]);
            if(!pz)break;
            if(pz==uk)break;
            uk=pz;
        }
        cout << endl;
    }
    return 0;
}