#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,m,x,INF=720720;
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			x=read();
			if((i+j)%2==0)printf("%d ",INF);
			else printf("%d ",INF-x*x*x*x);	
		}
		puts("");
	}
	return 0;
}