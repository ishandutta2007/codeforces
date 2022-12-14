#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pll pair <ll,ll>
#define m_p make_pair
#define p_b push_back
using namespace std;
vector <ll> tt[10000];
void vout(ll x)
{
    cout << x << endl;
    exit(0);
}
set <ll> s;
ll a[1000000];
ll p[1000000],a1,b1,c1,stn,x,k,ans,n,m,l,r,b[1000000],j,c[1000000],sc,i,mn=1e18,mx=-1e18;
void modify(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        p[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
    p[v]=p[v*2]+p[v*2+1];
}
ll get(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return 0;
    if(tl==l && tr==r)return p[v];
    ll tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(l,tm+1),r);
}
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("bow.in","r",stdin);
    //freopen("bow.out","w",stdout);
    cin >> n;
//    n++;
    for(i=1;i<=n;i++)modify(1,1,n,i,0);
  //  modify(1,1,n,n,1);
    cout << 1;
    for(i=1;i<=n;i++)s.insert(i);
    for(i=0;i<n;i++)
    {
        cin >> x;
        mx=max(mx,x);
        modify(1,1,n,x,1);
        s.erase(x);
        l=1;
        r=n;
        if(i==n-1)break;
        set <ll> :: iterator it=s.end();
        --it;
        l=*it;
        //cout << l << " :" << i << endl;
        cout << " " << get(1,1,n,1,l)+1;
    }
    cout << " 1" << endl;
   return 0;
}