#include <bits/stdc++.h>
using namespace std;
#define N (3300)
typedef long long ll;
ll n,a[N],b[N],c[N],dp[N],dp2[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    
    dp[0]=a[0],dp2[0]=b[0];
    for(int i=1;i<n;i++)
    {
    	dp2[i]=max(dp2[i-1]+b[i],dp[i-1]+c[i]);
    	dp[i]=max(dp[i-1]+b[i],dp2[i-1]+a[i]);
	}
	cout<<dp[n-1];
    return 0;
}