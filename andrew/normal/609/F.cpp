#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
set <ll> s;
set <pll> ses[1000000];
map < ll , ll > mp;
map <ll,ll> mp1;
string s1;
char cc;
ll pv,ll1,ll2,ll3,ll4;
ll p2[1000000];
pair <ll,pll> a[1000000];
ll pz,p[1000000],p1[1000000],c,sc[1000000],n,m,i,j,b[1000000],a1,b1,c1,ans,x,k;
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
        p1[v]=val;
        p2[v]=val;
        ll1=p1[v];
        ll2=p2[v];
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)build(v*2,tl,tm,pos,val);else build(v*2+1,tm+1,tr,pos,val);
}
void modify(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        p2[v]+=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
    p1[v]=min(p1[v*2],p1[v*2+1]);
    p2[v]=max(p2[v*2],p2[v*2+1]);
}
void get1(ll v,ll tl,ll tr,ll l,ll r)
{
    if(tl==tr)
    {
        pz=tl;
        return;
    }
    ll tm=(tl+tr)/2;
    if(p2[v*2]>=x && tm>=l)get1(v*2,tl,tm,l,r);
    if(pz!=0)return;
    get1(v*2+1,tm+1,tr,l,r);
    return;
}
ll getm(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return -1e18;
    if(tl==l && tr==r)return p2[v];
    ll tm=(tl+tr)/2;
    return max(getm(v*2,tl,tm,l,min(r,tm)),getm(v*2+1,tm+1,tr,max(l,tm+1),r));
}
ll get(ll v,ll tl,ll tr,ll pos)
{
    if(tl==tr)return tl;
    ll tm=(tl+tr)/2;
    if(p1[v*2+1]<=pos)return get(v*2+1,tm+1,tr,pos);return get(v*2,tl,tm,pos);
}
ll gt(ll v,ll tl,ll tr,ll pos)
{
    if(tl==tr)return p2[v]-p[v];
    ll tm=(tl+tr)/2;
    if(pos<=tm)return gt(v*2,tl,tm,pos);
    return gt(v*2+1,tm+1,tr,pos);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<1000000;i++)p1[i]=1e18,p2[i]=-1e18;
    for(i=1;i<=n;i++)cin >> a[i].fi >> a[i].se.fi;
    for(i=1;i<=n;i++)a[i].se.se=i;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)build(1,1,n,i,a[i].fi);
    for(i=1;i<=n;i++)modify(1,1,n,i,a[i].se.fi);
    for(i=1;i<=m;i++)
    {
        cin >> x >> a1;
        if(p1[1]>x or (getm(1,1,n,1,get(1,1,n,x))<x))
        {
            ss.insert(x);
            mp[x]+=a1;
            mp1[x]++;
            continue;
        }
        //cout << getm(1,1,n,1,get(1,1,n,x)) << "cc" << x << endl;
        pz=0;
        get1(1,1,n,1,get(1,1,n,x));
        b1=pz;
        //cout << a[b1].fi << "kek" << endl;
        sc[a[b1].se.se]++;
        //if(a[b1].se.se==7)cout << " " << x << " " << i << endl;
        modify(1,1,n,b1,a1);
        if(ss.size()>0)
        {
            ll l1,l2;
            c1=gt(1,1,n,b1);
            l1=a[b1].fi;
            l2=a[b1].fi+c1;
            //cout << l1 << " " << l2 << " " << i << " " << ss.size() << endl;
            set <ll> :: iterator it;
            set <ll> :: iterator kek;
            set <ll> :: iterator it1;
            it=ss.lower_bound(l1);
            it1=ss.upper_bound(l2);
            kek=it;
            for(;kek!=it1;++kek)
            {
                //cout << "-";
                ll xx1,xx2;
                xx1=*kek;
                xx2=mp[*kek];
                l2+=xx2;
                it1=ss.upper_bound(l2);
                mp[*kek]=0;
                sc[a[b1].se.se]+=mp1[*kek];
                mp1[*kek]=0;
                modify(1,1,n,b1,xx2);
                s.insert(xx1);
            }
            //cout << endl;
            while(s.size()>0)
            {
                set <ll> :: iterator itkek=s.begin();
                ss.erase(*itkek);
                s.erase(*itkek);
            }
        }
    }
    for(i=1;i<=n;i++)b[a[i].se.se]=i;
    for(i=1;i<=n;i++)cout << sc[i] << " " << gt(1,1,n,b[i]) << endl;
    return 0;
}