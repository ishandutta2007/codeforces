#include<bits/stdc++.h>
using namespace std;
int a[105],f[105],p[105][105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n+1;i++)f[i]=max(a[i],a[i-1])+1;
		for(int i=2;i<=n+1;i++)
		{
			for(int j=1;j<=a[i-1];j++)p[i][j]=p[i-1][j];
			p[i][a[i-1]+1]=(p[i-1][a[i-1]+1]+1)%26;
		}
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=f[i];j++)printf("%c",p[i][j]+'a');
			puts("");
		}
	}
	return 0;
}