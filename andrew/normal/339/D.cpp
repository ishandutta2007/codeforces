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
ll l,fl,p[1000000],i,j,n,m,k,sc,s,dp,x,a[100000],b[100000],a1,b1,c1,ans;
void modify(ll v, ll tl , ll tr , ll pos, ll val, ll mig)
{
    mig%=2;
    if(tl==tr)
    {
        p[v]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)modify(v*2,tl,tm,pos,val,mig+1);else modify(v*2+1,tm+1,tr,pos,val,mig+1);
    if(mig==1)p[v]=p[v*2]|p[v*2+1];else p[v]=p[v*2]^p[v*2+1];
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> m;
    n=(1 << k);
    if(k%2==1)fl=1;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        modify(1,1,n,i,x,fl);
    }
    for(i=0;i<m;i++)
    {
        cin >> l >> x;
        modify(1,1,n,l,x,fl);
        cout << p[1] << endl;
    }
    return 0;
}