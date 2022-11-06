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
int taxi,a,b,c;
long long ans1,ans2;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		a=read(),b=read(),c=read();ans1=ans2=1;
		c--;putchar('1');
		for(int i=2;i<=a;i++)putchar('0');putchar(' ');
		for(int i=1;i<=b-c;i++)putchar('9');
		for(int i=1;i<=c;i++)putchar('0');
		puts("");
	}
	return 0;
}