#include<bits/stdc++.h>
using namespace std;
int n,t,Test_num;
int cnt[32];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),t=0;
		for(int i=0;i<=31;++i)cnt[i]=0;
		for(int i=1,x;i<=n;++i)
		{
			read(x);
			for(int i=31;~i;--i)cnt[i]+=((x>>i)&1);
		}
		for(int i=0;i<=31;++i)t=__gcd(t,cnt[i]);
		for(int i=1;i<=n;++i)if(!(t%i))printf("%d ",i);
		puts("");
	}
	return 0;
}