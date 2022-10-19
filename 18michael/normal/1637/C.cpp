#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,cnt,Test_num;
LL sum,sum1;
bool ok;
int a[1000002];
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
		read(n),sum=sum1=cnt=0,ok=0;
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=2;i<n;++i)sum+=a[i],sum1+=(a[i]&1),cnt+=(a[i]>0),ok|=(a[i]>1);
		if(n==3 && a[2]&1)
		{
			puts("-1");
			continue;
		}
		if(sum && !ok)
		{
			puts("-1");
			continue;
		}
		if(cnt==1 && (sum&1))
		{
			if(sum==3)
			{
				puts("-1");
				continue;
			}
			printf("%lld\n",(sum/2)+2);
			continue;
		}
		if(!cnt)
		{
			puts("0");
			continue;
		}
		printf("%lld\n",(sum+sum1)/2);
	}
	return 0;
}