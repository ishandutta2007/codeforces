#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
using namespace std;
vector <ll> tt[10000];
void vout(ll x)
{
    cout << x << endl;
    exit(0);
}
ll ans=-1e18,n,m,a[1000000],b[1000000],c[1000000],sc,i,mn=1e18,mx=-1e18;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)mn=min(mn,a[i]);
    for(i=0;i<n;i++)mx=max(mx,a[i]);
    if(m==1)vout(mn);
    if(m>2)vout(mx);
    mn=1e18;
    for(i=0;i<n;i++)
    {
        mn=min(mn,a[i]);
        b[i]=mn;
    }
    mn=1e18;
    for(i=n-1;i>=0;i--)
    {
        mn=min(mn,a[i]);
        c[i]=mn;
    }
    for(i=1;i<n;i++)ans=max(ans,max(b[i-1],c[i]));
    cout << ans << endl;
   return 0;
}