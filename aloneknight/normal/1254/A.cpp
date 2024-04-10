#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5000005;
int n,m,k,ss;char s[105][105],t[105][105];
int main()
{
	int T;scanf("%d",&T);
	string id="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);ss=0;
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='R')ss++;
		int nn=ss/k,p=ss%k,w=0,tt=0;
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				for(int j=1;j<=m;j++)
				{
					tt+=s[i][j]=='R';t[i][j]=id[w];
					if((w<p&&tt==nn+1)||(w>=p&&tt==nn&&w<k-1)){w++;tt=0;}
				}
			}
			else
			{
				for(int j=m;j;j--)
				{
					tt+=s[i][j]=='R';t[i][j]=id[w];
					if((w<p&&tt==nn+1)||(w>=p&&tt==nn&&w<k-1)){w++;tt=0;}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)printf("%c",t[i][j]);
			putchar('\n');
		}
	}
	return 0;
}