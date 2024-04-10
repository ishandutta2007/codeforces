#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,k,i,p,j,t[N],x[N],l,r,f[N][N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d %d",&t[i],&x[i]);
	memset(f,0x7f,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
			if(1ll*f[i-1][j]+abs(x[i]-x[i-1])<=t[i])
				f[i][j]=t[i];
		for(j=i+1;j<=n;++j)
		{
			if(max(1ll*f[i-1][i-1]+abs(x[i-1]-x[j]),1ll*t[i-1])+abs(x[j]-x[i])<=t[i])
				f[i][j]=t[i];
			if(i>=2)
				if(max(1ll*f[i-2][i-1]+abs(x[j]-x[i-2]),1ll*t[i-1])+abs(x[j]-x[i])<=t[i])
					f[i][j]=t[i];
		}
		if(1ll*f[i-1][i-1]+abs(x[i]-x[i-1])<=t[i])
			f[i][i]=min(1ll*f[i][i],max(1ll*f[i-1][i-1]+abs(x[i]-x[i-1]),1ll*t[i-1]));
		if(i>=2)
			if(max(1ll*f[i-2][i-1]+abs(x[i]-x[i-2]),1ll*t[i-1])<=t[i])
				f[i][i]=min(1ll*f[i][i],max(1ll*f[i-2][i-1]+abs(x[i]-x[i-2]),1ll*t[i-1]));
	}
	puts((f[n][n]<=(1<<30)||f[n-1][n]<=(1<<30))?"YES":"NO");
}