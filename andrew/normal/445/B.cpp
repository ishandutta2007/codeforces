#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ddd,stn,res,cv[1000],tt[100][100],a[1000],b[1000],xx[51][51],v[1000000],y,i,j,n,m,k,l,sc,ans,fl;
void rec(ll x)
{
    ll i;
    ll t=x;

    if(cv[x]>0)return;
   // cout << x << endl;
    cv[x]=res;
    stn++;
    //ans=max(ans,stn);
    //cout << x << endl;
   // cout << sc << " " << x << " " << a[x] << " " << b[x] << endl;
    for(i=1;i<=n;i++)if(tt[x][i]==1)rec(i);
    //v[a[x]]=0;
 //   sc-=c[x];
    stn--;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(m==0)
    {
        cout << 1 << endl;
        return 0;
    }
    ll cc=m;
    m=-1;
    for(i=1;i<=cc;i++)
    {
        ll ccc,x1,y1;
        m++;
        cin >> a[m] >> b[m];
        tt[a[m]][b[m]]=1;
        tt[b[m]][a[m]]=1;
    }
    res=0;
        for(i=1;i<=n;i++)if(cv[i]==0)
        {
            res++;
            rec(i);
        }
   // cout << ans << endl;
    ll x=1;
    ans=n-res;
    for(i=1;i<=ans;i++)x*=2;
    cout << x << endl;
    return 0;
}