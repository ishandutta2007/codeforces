//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,x,a[109],taxi,now,flag; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),x=read();flag=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1&&a[1]==x)
		{
			puts("NO");continue;
		}
		now=0;
		for(int i=1;i<=n;i++)
		{
			now+=a[i];
			if(now>x)break;
			if(now==x)
			{
				if(i==n)flag=1;
				swap(a[i],a[i+1]);break;
			}
		}
		if(flag)
		{
			puts("NO");continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}