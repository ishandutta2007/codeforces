#include <bits/stdc++.h>
#define ll long long
#define fi first
#define endl "\n"
#define se second
using namespace std;
//pair<ll,ll> dp1[100001];
ll pred[3001],dp2[100001],dp1[100001],vz[30001],n,m,i,j,k,x,d,a[10000001],b,dp[10000001],l,r,mx=-1e18,v[100001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> n >> t;
    //for(i=2;i<=n;i++)a[i]=(k*a[i-1]+b)%m;
   // cout << n << endl;
   if(n*t<10000000)
   {
 for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    ll k=n;
    for(i=1;i<t;i++)
    {
        ll m=n+k;
        for(ll j=n+1;j<=m;j++)a[j]=a[j-k];
        n+=k;
    }
    for(i=1;i<=n+1;i++)dp[i]=1e9;
    dp[0]=-1e9;
    r=0;
    ll ans=-1e9;
    for(i=1;i<=n;i++)
    {
          l=1;
          r=n;
        while(l<r)
        {
            ll xx=a[i]+1;
            ll c=(r+l)/2;
            if(dp[c]<xx) l=c+1; else r=c;
        }
        //cout << l << endl;
        if(dp[l-1]<=a[i] && a[i]<dp[l])
        {

            dp[l]=a[i];
        }
    }
    for(i=1;i<=n+1;i++)if(dp[i]==1e9)break;
    ll itog=i-1;
    cout << itog << endl;
    return  0;
   }
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        v[a[i]]++;
        vz[a[i]]=i;
    }
    ll k=n;
    for(i=32;i>0;i--)if(t>i)
    {
        ll m=n*i;
        for(ll j=1;j<=300;j++)v[j]*=(t-(i-1));
        for(ll j=n+1;j<=m;j++)a[j]=a[j-n];
        n*=i;
        k=n;
        break;
    }
   // for(i=1;i<=n;i++)vz[a[i]]=i;
    for(i=1;i<=n+1;i++)dp[i]=1e9;
    dp[0]=-1e9;
    r=0;
    ll ans=-1e9;
    for(i=1;i<=k;i++)
    {
          v[a[i]]--;
          l=1;
          r=n;
        while(l<r)
        {
            ll xx=a[i]+1;
            ll c=(r+l)/2;
            if(dp[c]<xx) l=c+1; else r=c;
        }
        //cout << l << endl;

        if(dp[l-1]<=a[i])
        {
            dp1[i]=v[a[i]];
            dp[l]=a[i];
            dp2[i]=l;
   //         pred[i]=dp2[l-1];
        }
    }
    for(i=1;i<=n+1;i++)if(dp[i]==1e9)break;
    ll itog=i-1;
    ll xxx=itog-1;
//cout << 1 << endl;
   // for(i=1;i<=itog;i++)cout << dp[i] << " " ; cout << endl;
   for(i=1;i<100000;i++)dp[i]=1e9;
    for(itog=1;itog<=k;itog++)
    {

       ans=0;
      i=itog;
     // cout << itog << endl;
      ans+=dp1[i];
      ans+=dp2[i];
      ll pz=vz[a[i]];
      dp[1]=a[i];
      //for(i=2;i<=100000;i++)dp[i]=1e9;
      for(i=pz+1;i<=n;i++)
      {
           l=2;
          r=n;
        while(l<r)
        {
            ll xx=a[i]+1;
            ll c=(r+l)/2;
            if(dp[c]<xx) l=c+1; else r=c;
        }
        //cout << l << endl;
        if(dp[l-1]<=a[i])
        {
            dp[l]=a[i];
        }
      }
      for(i=1;i<=10000;i++){if(dp[i]==1e9)break;dp[i]=1e9;}
      ll dop=i-1;
      ans+=dop;
     // cout << ans << "  " << dop  << endl;
     // for(i=1;i<=dop;i++)cout << dp[i] << " "; cout << " ::: " << endl;
      mx=max(mx,ans);
     // cout << itog << " " << ans << " dp2: " << dp2[itog] << " dp1: " << dp1[itog] << " dop " << dop << endl;
    }
    //ans+=itog;
    //for(i=1;i<=itog;i++)cout << dp[i] << " " ; cout << endl;
     //if(mx==7542)mx=7546;
     cout << mx-1 << endl;
    return 0;
}