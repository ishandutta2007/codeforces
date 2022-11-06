#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,flag,taxi,h[109],now;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		n=read();
		for(int i=1;i<=n;i++)h[i]=read();
		now=h[1];
		for(long long i=2;i<=n;i++)
		{
			now+=h[i];
			if(i*(i-1)/2>now)
			{
				puts("NO");
				flag=1;
				break;
			}
		}
		if(!flag)puts("YES");
	}
	return 0;
}