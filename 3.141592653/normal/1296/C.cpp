#include<cstdio>
#include<map>
typedef long long ll;
#define F(x,y) ((x)*200000000ll+(y))
std::map<ll,int>m;
int n;
char str[1111111];
void exec()
{
	scanf("%d%s",&n,str+1);
	m.clear();
	register int i;
	m[F(0,0)]=1;
	int nx=-1,ny=-1,mnl=1e9,px=0,py=0;
	for(i=1;i<=n;i++)
	{
		if(str[i]=='L')px--;
		if(str[i]=='R')px++;
		if(str[i]=='D')py--;
		if(str[i]=='U')py++;
		int t=m[F(px,py)];
		if(t)
		{
			int del=i-t+1;
			if(del<mnl)nx=t,mnl=del,ny=i;
		}m[F(px,py)]=i+1;
	}
	if(~nx)printf("%d %d\n",nx,ny);
	else puts("-1");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/