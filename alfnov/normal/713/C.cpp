#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005],c[3005],d[3005];
long long f[3005][3005],t[3005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=n-i,b[i]=a[i];
	for(int i=1;i<=n;i++)c[i]=a[n-i+1],d[i]=c[i];
	sort(b+1,b+n+1);
	sort(d+1,d+n+1);
	long long ans=LLONG_MAX;
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++)f[1][i]=abs(a[1]-b[i]);
	for(int i=2;i<=n;i++)
	{
		memset(t,63,sizeof(t));
		for(int j=1;j<=n;j++)t[j]=min(t[j-1],f[i-1][j]);
		for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],t[j]+abs(b[j]-a[i]));
	}
	for(int i=1;i<=n;i++)ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}