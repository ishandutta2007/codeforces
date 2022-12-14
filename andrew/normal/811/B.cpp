#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll a[100001],st[100001],v[10001],i,j,n,l,r;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll m;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        ll x=a[i];
        v[x]=i;
    }
    for(i=0;i<m;i++)
    {
        ll x;
        ll stn=0;
        cin >> l >> r >> x;
        for(ll j=1;j<=n;j++)if(v[j]>=l && v[j]<=r)
        {
          stn++;
          st[stn]=j;
        }
        if(st[x-l+1]==a[x])cout << "Yes"; else cout << "No";
        cout << endl;
    }
    return 0;
}