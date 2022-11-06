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
int taxi,a,b,c,k; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		a=read(),b=read(),c=read();
		if((a+b+c)%9!=0)
		{
			puts("NO");
			continue;
		}
		k=(a+b+c)/9;
		if(k>a||k>b||k>c)puts("NO");
		else puts("YES");
	}
	return 0;
}