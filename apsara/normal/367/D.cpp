#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1000100;
int s[21][V/10];
bool can[V];
int n,m,D;
int pos[V],x,y;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&D))
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d",&x);
			for(int j=0;j<x;j++)
			{
				scanf("%d",&y);
				pos[y]=i;
			}
		}
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			s[j][i]=s[j][i-1];
			s[pos[i]][i]++;
		}
		for(int i=0;i<(1<<m);i++)
		can[i]=1;
		for(int l=1;l<=n;l++)
		{
			int r=l+D-1;
			if(r>n)break;
			int bs=(1<<m)-1;
			for(int i=0;i<m;i++)
			if(s[i][r]-s[i][l-1])
			bs^=(1<<i);
			can[bs]=0;
		}
		for(int i=(1<<m)-1;i>=0;i--)
		for(int j=0;j<m;j++)
		if(!can[i|(1<<j)])
		can[i]=0;
		int ret=m;
		for(int i=0;i<(1<<m);i++)
		if(can[i])
		{
			int t=0;
			for(int j=0;j<m;j++)
			if(i&(1<<j))
			t++;
			ret=min(ret,t);
		}
		printf("%d\n",ret);
	}
	return 0;
}