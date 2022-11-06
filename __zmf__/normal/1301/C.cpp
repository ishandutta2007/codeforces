//zhouakngyang txdy!
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
int taxi,n,m,ans,k1,k2,k3;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),m=read();
		if(m==0)
		{
			puts("0");continue;
		}
		ans=n*(n+1)/2;
		n=n-m,m++;
		ans=ans-(n%m)*(n/m+1)*(n/m+2)/2;
		ans=ans-(m-n%m)*(n/m)*(n/m+1)/2;	 
		printf("%lld\n",ans);
	}
	return 0;
}