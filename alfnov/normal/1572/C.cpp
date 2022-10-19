#include<bits/stdc++.h>
using namespace std;
int f[3005][3005],a[3005],b[3005],s[3005],d[3005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,n=0;
		cin>>m;
		for(int i=1;i<=m;i++)scanf("%d",&b[i]),d[b[i]]=0;
		for(int i=1;i<=m;)
		{
			int j=i;
			while(j<=m&&b[j]==b[i])j++;
			a[++n]=b[i],i=j;
		}
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			if(d[a[i]])s[i]=d[a[i]];
			d[a[i]]=i;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			f[i][j]=INT_MAX;
		for(int i=1;i<=n;i++)f[i][i]=f[i+1][i]=0;
		for(int l=2;l<=n;l++)for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			f[i][j]=min(f[i][j-1],f[i+1][j])+1;
			for(int k=s[j];k>=i;k=s[k])
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
		cout<<f[1][n]<<endl;
	}
	return 0;
}