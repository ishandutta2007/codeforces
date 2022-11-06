#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005];
char s[1005][1005]; 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=2;i<n;i++)for(int j=2;j<m;j++)
	{
		bool f=1;
		for(int ii=-1;ii<=1;ii++)for(int jj=-1;jj<=1;jj++)
		{
			if(!ii&&!jj)continue;
			if(s[i+ii][j+jj]!='#')f=0;
		}
		if(f==1)
		{
			for(int ii=-1;ii<=1;ii++)for(int jj=-1;jj<=1;jj++)
			{
				if(!ii&&!jj)continue;
				a[i+ii][j+jj]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='#'&&!a[i][j])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}