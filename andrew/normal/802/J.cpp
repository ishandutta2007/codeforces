#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll stn,a[1000],b[1000],c[1000],v[1000],x[1000],i,j,n,m,k,l,sc,ans;
void rec(ll x)
{
    ll i;
    ll t=a[x];
    //cout << x << endl;
    if(v[t]==1)return;
    sc+=c[x];
    v[t]=1;
    stn++;
    ans=max(sc,ans);
   // cout << sc << " " << x << " " << a[x] << " " << b[x] << endl;
    for(i=0;i<=m;i++)if(a[i]==b[x] && b[i]!=a[x])rec(i);
    v[t]=0;
    sc-=c[x];
    stn--;
}
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m=n;
    n--;
    for(i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        m++;
        b[m]=a[i];
        a[m]=b[i];
        c[m]=c[i];
    }
    for(i=0;i<=m;i++)if(a[i]==0)rec(i);
    cout << ans << endl;
    return 0;
}