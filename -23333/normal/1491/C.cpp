#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const int N=2e5;
ll a[N],sum[N],f[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{ 
ll n;
	  cin>>n; ll ans=0;
	  rep(i,1,n) sum[i]=0;
	  rep(i,1,n)
	  {
	  	cin>>a[i]; sum[i]+=sum[i-1];
	  	if (a[i]>sum[i]+1) ans+=a[i]-sum[i]-1;
	  	if (sum[i]<=a[i]-1)
	  	{
	  		sum[i+2]+=1; sum[min(n+1,i+a[i]+1)]--;
	  	} else
	  	{
	  		sum[i+1]+=sum[i]-(a[i]-1);
	  		sum[i+2]-=sum[i]-(a[i]-1);
	  		sum[i+2]+=1;
	  		sum[min(n+1,i+a[i]+1)]--;
	  	}
	  }
	  cout<<ans<<endl;
    }
	return 0;
}