#include<bits/stdc++.h>
using namespace std;
int a[305][305],f[305][305],n,m;
int valid(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			a[i][j]=valid(i-1,j)+valid(i+1,j)+valid(i,j-1)+valid(i,j+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			scanf("%d",&f[i][j]);
		int pp=1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			if(f[i][j]>a[i][j])pp=0;
		if(pp==0)cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<m;j++)printf("%d ",a[i][j]);
				printf("%d\n",a[i][m]);
			}
		}
	}
	return 0;
}