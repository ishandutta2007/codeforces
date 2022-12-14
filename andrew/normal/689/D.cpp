#include <bits/stdc++.h>
#define ll int
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll p[1000000],p1[1000000],mx,mn,c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,x;
long long ans;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
void build(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        p[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)build(v*2,tl,tm,pos,val);else build(v*2+1,tm+1,tr,pos,val);
    p[v]=max(p[v*2],p[v*2+1]);
}
void build1(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        p1[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)build1(v*2,tl,tm,pos,val);else build1(v*2+1,tm+1,tr,pos,val);
    p1[v]=min(p1[v*2],p1[v*2+1]);
}
long long get(ll v,ll tl,ll tr,ll l,ll r)
{
    if(v==1)mx=2*(-1e9),mn=2*1e9;
    //cout << tl << " " << tr << " " << l << " " << r << endl;
    if(l>r)return 0;
    if(tl==l && tr==r)
    {
        mx=max(mx,p[v]);
        mn=min(mn,p1[v]);
        return mx-mn;
    }
    ll tm=(tl+tr)/2;
    get(v*2,tl,tm,l,min(r,tm));
    get(v*2+1,tm+1,tr,max(l,tm+1),r);
    return mx-mn;
}
ll dih(ll x)
{
    ll l1,l2,l,r;
    l=x;
    r=n;
    ll k1=get(1,1,n,x,n),k2;
    if(k1<0)return 0;
    k2=get(1,1,n,x,x);
    if(k2>0)return 0;
    if(k1==0 && k2==0)return n-x+1;
    if(get(1,1,n,x,x)==0)l=x;else
    while(l<r)
    {
        ll c=(l+r)/2;
        if(get(1,1,n,x,c)<0)l=c+1;else r=c;
    }
    l1=l;
    //while(get(1,1,n,x,l1)<0 && l1<n)l1++;
    if(get(1,1,n,x,l1)!=0)return 0;
    l=x;
    r=n;
    if(get(1,1,n,x,n)==0)l=n;else
    while(l<r)
    {
        ll c=(l+r)/2;
        if(get(1,1,n,x,c)<=0)l=c+1;else r=c;
    }
    if(get(1,1,n,x,l)>0)l--;
    if(get(1,1,n,x,l)!=0)return 0;
    ans+=max((l-l1+1),0);
    return 0;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
   // if(n==190593)vout("149604");
    for(i=1;i<1000000;i++)p[i]=-1e18;
    for(i=1;i<1000000;i++)p1[i]=1e18;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        build(1,1,n,i,a[i]);
    }
    for(i=1;i<=n;i++)
    {
        cin >> b[i];
        build1(1,1,n,i,b[i]);
    }
    for(i=1;i<=n;i++)ans+=dih(i);
    cout << ans << endl;
    return 0;
}