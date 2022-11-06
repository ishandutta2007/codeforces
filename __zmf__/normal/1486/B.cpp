#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,x[1009],y[1009],taxi;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
		if(n%2==1)puts("1");
		else
		{
			sort(x+1,x+n+1);
			sort(y+1,y+n+1);
			printf("%lld\n",(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1));
		}
	}
	return 0;
}