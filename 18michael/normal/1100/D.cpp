#include<bits/stdc++.h>
using namespace std;
int t;bitset<1002> u[1002];
int pre[1002][1002];
struct aaa
{
	int x,y;
}p[672],k;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	for(int i=0;i<=666;++i)read(p[i].x),read(p[i].y),u[p[i].x][p[i].y]=1;
	while(p[0].x!=500 || p[0].y!=500)
	{
		k=(aaa){p[0].x+(p[0].x<500)-(p[0].x>500),p[0].y+(p[0].y<500)-(p[0].y>500)};
		if(u[k.x][k.y]){if(p[0].y<500)--k.y;if(p[0].y>500)++k.y;}
		p[0]=k,printf("%d %d\n",p[0].x,p[0].y),fflush(stdout),read(t);if(t<0)return 0;
		u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1;
	}
	for(int i=1;i<=999;++i)
	{
		for(int j=1;j<=999;++j)pre[i][j]=pre[i][j-1]+u[i][j];
		for(int j=1;j<=999;++j)pre[i][j]+=pre[i-1][j];
	}
	if(pre[499][499]<=166)for(;;)
	{
		if(u[p[0].x+1][p[0].y+1])
		{
			printf("%d %d\n",++p[0].x,p[0].y),fflush(stdout),read(t);if(t<0)return 0;
			u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1,printf("%d %d\n",p[0].x,++p[0].y);
		}
		else printf("%d %d\n",++p[0].x,++p[0].y);
		fflush(stdout),read(t);if(t<0)return 0;u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1;
	}
	else if(pre[999][499]-pre[500][499]<=166)for(;;)
	{
		if(u[p[0].x-1][p[0].y+1])
		{
			printf("%d %d\n",--p[0].x,p[0].y),fflush(stdout),read(t);if(t<0)return 0;
			u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1,printf("%d %d\n",p[0].x,++p[0].y);
		}
		else printf("%d %d\n",--p[0].x,++p[0].y);
		fflush(stdout),read(t);if(t<0)return 0;u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1;
	}
	else if(pre[499][999]-pre[499][500]<=166)for(;;)
	{
		if(u[p[0].x+1][p[0].y-1])
		{
			printf("%d %d\n",++p[0].x,p[0].y),fflush(stdout),read(t);if(t<0)return 0;
			u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1,printf("%d %d\n",p[0].x,--p[0].y);
		}
		else printf("%d %d\n",++p[0].x,--p[0].y);
		fflush(stdout),read(t);if(t<0)return 0;u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1;
	}
	else for(;;)
	{
		if(u[p[0].x-1][p[0].y-1])
		{
			printf("%d %d\n",--p[0].x,p[0].y),fflush(stdout),read(t);if(t<0)return 0;
			u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1,printf("%d %d\n",p[0].x,--p[0].y);
		}
		else printf("%d %d\n",--p[0].x,--p[0].y);
		fflush(stdout),read(t);if(t<0)return 0;u[p[t].x][p[t].y]=0,read(p[t].x),read(p[t].y),u[p[t].x][p[t].y]=1;
	}
	return 0;
}