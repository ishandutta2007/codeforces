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
int n,taxi;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		if(n%2==1)
		{
			puts("NO");continue;
		}
		n/=2;
		int k=sqrt(n);
		if(k*k==n)puts("YES");
		else 
		{
			if(n%2==0)n/=2;
			k=sqrt(n);
			if(k*k==n)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}