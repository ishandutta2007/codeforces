#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,k,i,j,sc,mx,l,r,a[100000],b[10000],x[10000];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i=0;i<m;i++)cin >> x[i];
    for(i=1;i<m;i++)
    {
        if(x[i]<=x[i-1])
        {
           ll ans=n-x[i-1];
           ans+=x[i];
           ll dp=x[i-1];
           if(a[dp]!=0 and a[dp]!=ans){cout << -1 << endl; return 0;}
           a[dp]=ans;
        }else
        {
            ll ans=x[i]-x[i-1];
            ll dp=x[i-1];
           if(a[dp]!=0 and a[dp]!=ans){cout << -1 << endl; return 0;}
           a[dp]=ans;
        }
    }
    for(i=1;i<=n;i++)if(a[i]!=0)
    {
        //cout << a[i] << endl;
        if(b[a[i]]==1)
        {
            cout << -1 << endl;
            return 0;
        }
        b[a[i]]=1;
    }
    for(i=1;i<=n;i++)if(a[i]==0)
    {

        for(j=1;j<=n;j++)if(b[j]==0)break;
        a[i]=j;
        b[j]=1;
    }
    for(i=1;i<=n;i++)cout << a[i] << " ";
    cout << endl;
  return 0;
}