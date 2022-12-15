#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
int h,w;
int status[1010][1010];
int main()
{
	memset(status,255,sizeof(status));
	scanf("%d%d",&h,&w);
	for(int i=1,ti;i<=h;i++)
	{
		scanf("%d",&ti);
		for(int j=1;j<=ti;j++)status[i][j]=1;
		if(ti!=w)status[i][ti+1]=0;	
	}
	for(int i=1,ti;i<=w;i++)
	{
		scanf("%d",&ti);
		for(int j=1;j<=ti;j++)
		{
			if(status[j][i]==0)
			{
				puts("0");
				return 0;
			}
			status[j][i]=1;
		}
		if(ti!=h)
		{
			if(status[ti+1][i]==1)
			{
				puts("0");
				return 0;
			}
			status[ti+1][i]=1;
		}
	}
	int ans=1;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(status[i][j]==-1)ans=add(ans,ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}