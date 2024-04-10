#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <ll> tt[1000];
set <ll> s,sv;
ll kek,p[10000001],i,j,n,m,m1,k,sc,dp,x,a[100000],b[100000],a1,b1,c1,ans;
void modify(ll v,ll tl, ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        a1=pos;
        b1=0;
        if(a1>=k)a1-=k,b1++;
        b1+=a1/(k+1);
        p[v]+=val*(b1);
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
    p[v]=p[v*2]+p[v*2+1];
}
ll get(ll v, ll tl,ll tr,ll l, ll r)
{
    if(l>r)return 0;
    if(tl==l && tr==r)return p[v];

    ll tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(tm,r))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    s.insert(0);
    s.insert(n+1);
    cin >> kek;
    modify(1,1,n,n,1);
    for(i=0;i<kek;i++)
    {
         cin >> x;
         if(s.find(x)!=s.end())continue;
         s.insert(x);
         set<ll> :: iterator it=s.find(x);
         --it;
         ll l1=*it;
         ++it;
         ++it;
         ll l2=*it;
         dp=l2-l1-1;
        // cout << dp << endl;
         modify(1,1,n,dp,-1);
         //cout << x-l1-1 << " " << l2-x-1 << endl;
         modify(1,1,n,x-l1-1,1);
         modify(1,1,n,l2-x-1,1);
         //cout << get(1,1,n,1,n) << endl;
         if(get(1,1,n,k,n)<m)
         {
             cout << i+1 << endl;
             return 0;
         }
    }
    cout << -1 << endl;
    return 0;
}