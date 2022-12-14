#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
//#define endl "\n"
#define pll pair<ll,ll>
ll sm[1000000],pz1,pz2,uk,p1[1000000],p[1000000],a[1000000],b[10000],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
set <ll> s;
void modify(ll v,ll tl,ll tr ,ll pos,ll val)
{
    if(tl==tr)
    {
        p[v]=val;
        p1[v]=pos;
        if(val==1e18)sm[v]=1;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
    if(p[v*2]<=p[v*2+1])
    {
        p[v]=p[v*2];
        p1[v]=p1[v*2];
    }else
    {
        p[v]=p[v*2+1];
        p1[v]=p1[v*2+1];
    }
    sm[v]=sm[v*2]+sm[v*2+1];

}
void get(ll v,ll tl,ll tr, ll l, ll r)
{
    if(l>r)return;
    if(tl==l && tr==r)
    {
        if(p[v]==x)pz1=min(pz1,p1[v]);
        return;
    }
    ll tm=(tl+tr)/2;
    get(v*2,tl,tm,l,min(tm,r));
    get(v*2+1,tm+1,tr,max(tm+1,l),r);
}
void get1(ll v,ll tl,ll tr, ll l, ll r)
{
    if(l>r)return;
    if(tl==l && tr==r)
    {
        if(p[v]==x)pz2=min(pz2,p1[v]);
        return;
    }
    ll tm=(tl+tr)/2;
    get1(v*2,tl,tm,l,min(tm,r));
    get1(v*2+1,tm+1,tr,max(tm+1,l),r);
}
ll getkek(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return 0;
    if(tl==l && tr==r)return sm[v];
    ll tm=(tl+tr)/2;
    return getkek(v*2,tl,tm,l,min(tm,r))+
    getkek(v*2+1,tm+1,tr,max(tm+1,l),r);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        s.insert(x);
        a[x]++;
        modify(1,1,n,i,x);
    }
    uk=0;
    while(s.size()>0)
    {
    set <ll> :: iterator  it=s.begin();
        x=*it;
        pz1=1e18;
        pz2=1e18;
       if(uk!=n)get(1,1,n,uk+1,n);
       // cout << pz1 << " " << uk << " " << x << endl;
        //cout << ans << endl;
        a[x]--;
        if(a[x]==0)s.erase(x);
        if(pz1!=1e18)
        {
            ans+=pz1-uk;
            ans-=getkek(1,1,n,uk+1,pz1);
            uk=pz1;
            modify(1,1,n,pz1,1e18);
            continue;
        }
        get1(1,1,n,1,uk-1);
        ans+=n-uk;
        ans-=getkek(1,1,n,uk+1,n);
        ans-=getkek(1,1,n,1,pz2);
        ans+=pz2;
        modify(1,1,n,pz2,1e18);
       // ans++;
        uk=pz2;

    }
cout << ans << endl;
return 0;
}