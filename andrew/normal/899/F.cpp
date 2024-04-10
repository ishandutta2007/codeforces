#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef int ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <ll> s[1000];
string s2,s1,s3;
char cc;
ll l,r,sc[800001];
ll r2,c,n,m,i,j,a[100],a1,b1,c1,ans,x,k;
void modify(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        sc[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);
    else modify(v*2+1,tm+1,tr,pos,val);
    ll j;
    sc[v]=sc[v*2]+sc[v*2+1];
}
ll get(ll v,ll tl,ll tr,ll pos)
{
    if(tl==tr)return sc[v];
    ll tm=(tl+tr)/2;
    if(pos<=tm)return get(v*2,tl,tm,pos);
    return get(v*2+1,tm+1,tr,pos);
}
ll gge(ll v,ll tl,ll tr)
{
    if(tl==tr)return tl;
    ll tm=(tl+tr)/2;
    if(x-sc[v*2+1]<r2)return gge(v*2+1,tm+1,tr);
    return x-=sc[v*2+1], gge(v*2,tl,tm);
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    cin >> s1;
    for(i=1;i<=n;i++)
    {
        modify(1,1,n,i,1);
        s[s1[i-1]].insert(i);
    }
    set <ll> :: iterator it;
    set <ll> :: iterator it1;
    while(m--)
    {
        cin >> l >> r >> cc;
        ll l1,r1;
        r2=l;
        x=sc[1];
        l1=gge(1,1,n);
        r2=r;
        x=sc[1];
        r1=gge(1,1,n);
        //if(x>r2)r1--;
        //cout << l1 << " " << r1 << endl;
        it=lower_bound(s[cc].begin(),s[cc].end(),l1);
        while(it!=s[cc].end())
        {
            x=*it;
            if(!(l1<=x && x<=r1))break;
            it1=it;
            ++it;
            modify(1,1,n,x,0ll);
            s[cc].erase(it1);
        }
    }
    for(i=1;i<=n;i++)if(get(1,1,n,i))s2+=s1[i-1];
    cout << s2 << endl;
    return 0;
}