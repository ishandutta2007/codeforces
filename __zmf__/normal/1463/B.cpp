//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,a[59],n,now,sum; 
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];now=0;
		for(int i=1;i<=n;i+=2)now=now+a[i];
		if(now*2<=sum)
		{
			for(int i=1;i<=n;i++)
				if(i%2==1)printf("1 ");
				else printf("%d ",a[i]);
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(i%2==0)printf("1 ");
				else printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}