#include<bits/stdc++.h>
using namespace std;
char s[2005][2005];
int a1[2005][2005],a2[2005][2005],a[2005][2005];
int b1[2005][2005],b2[2005][2005];
int f1[2005][2005],f2[2005][2005];
int l1[2005][2005],l2[2005][2005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++)a1[1][i]=a2[n][i]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<=m;j++)
		a1[i][j]=(s[i][j]==s[i-1][j])*a1[i-1][j]+1;
	for(int i=n-1;i>=1;i--)for(int j=1;j<=m;j++)
		a2[i][j]=(s[i][j]==s[i+1][j])*a2[i+1][j]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		a[i][j]=min(a1[i][j],a2[i][j]);
	for(int i=1;i<=n;i++)b1[i][1]=b2[m][1]=1;
	for(int i=2;i<=m;i++)for(int j=1;j<=n;j++)
		b1[j][i]=(s[j][i]==s[j][i-1])*b1[j][i-1]+1;
	for(int i=m-1;i>=1;i--)for(int j=1;j<=n;j++)
		b2[j][i]=(s[j][i]==s[j][i+1])*b2[j][i+1]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		f1[i][j]=a[i][j]-j;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		f2[i][j]=a[i][j]+j;
	for(int i=1;i<=n;i++)
	{
		l1[i][1]=1;
		for(int j=2;j<=m;j++)l1[i][j]=(s[i][j]==s[i][j-1])*min(l1[i][j-1],a[i][j]-1)+1;
		l2[i][m]=1;
		for(int j=m-1;j>=1;j--)l2[i][j]=(s[i][j]==s[i][j+1])*min(l2[i][j+1],a[i][j]-1)+1;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tt=min(a[i][j],min(l1[i][j],l2[i][j]));
			ans+=tt;
		}
	}
	cout<<ans<<endl;
	return 0;
}