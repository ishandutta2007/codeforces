#include<bits/stdc++.h>
using namespace std;
int a[5050];
long long f[5050][5050];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=5e18;
	for(int i=1;i<=n;i++)
	{
		f[0][i]=max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1);
		ans=min(ans,f[0][i]);
	}
	f[0][0]=1e18;
	printf("%I64d ",ans);
	int tmp=0;
	for(int k=2;k<=(n+1)/2;k++)
	{
		tmp^=1;
		ans=5e18;
		memset(f[tmp],42,sizeof(f[tmp])); 
		long long pw=1e18;
		for(int i=1;i<=n;i++)
		{
			if(i>1)
				f[tmp][i]=f[tmp^1][i-2]-max(0,a[i-1]-a[i-2]+1)+max(0,max(a[i-1]-a[i-2],a[i-1]-a[i])+1)+max(0,a[i+1]-a[i]+1);
			f[tmp][i]=min(f[tmp][i],pw+max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1));
			ans=min(ans,f[tmp][i]);
			if(i>1)
				pw=min(pw,f[tmp^1][i-2]);
		}
		printf("%I64d ",ans);
	}
	printf("\n");
	return 0;
}