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
int taxi,n,b[200009],Min,Max,len,now; 
bool k[400009];
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();Max=-1e9,Min=1e9;
		for(int i=1;i<=2*n;i++)k[i]=0;
		for(int i=1;i<=n;i++)b[i]=read(),k[b[i]]=1;
		now=0;
		for(int i=1;i<=2*n;i++)
		{
			if(k[i]==1)now++;
			else now--;
			Min=min(Min,now);
			Max=max(Max,now);
		}
		printf("%d\n",n-(Max-Min)+1);
	}
	return 0;
}