#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,t,Test_num;LL res,tmp,ans;
LL a[200002],sum[200002],pre[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL count(int y,LL x)
{
	res=0,t=n-1-(n&1),t-=(t==n-1? 2*((y>>1)&1):0);
	for(int i=1+(y&1);i<n;++i){if((sum[i]+x)>tmp)break;++res;}
	for(int i=1+2*(y&1);i<t;i+=2)
	{
		while(i<t && sum[i]+pre[t]-pre[i]+x>tmp)t-=2;
		if(i<t)res+=(t-i)/2;
	}
	t=n-1-((n&1)^1),t-=(t==n-1? 2*((y>>1)&1):0);
	for(int i=2;i<t;i+=2)
	{
		while(i<t && sum[i]+pre[t]-pre[i]+x>tmp)t-=2;
		if(i<t)res+=(t-i)/2;
	}
	return res;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=0,tmp=-1;for(int i=1;i<=n;++i)read(a[i]),tmp+=a[i];
		if(n==1){puts("1");continue;}
		if(n==2){printf("%d\n",1+(a[1]!=a[2]));continue;}
		for(int i=2;i<n;++i)sum[i]=sum[i-1]+a[i],pre[i]=pre[i-2]+a[i];
		tmp>>=1,res=0;for(int i=n;i>1;--i){++ans;if((res+=a[i])>tmp)break;}
		printf("%lld\n",(ans+count(1,0)+count(0,a[1])+count(3,a[n])+count(2,a[1]+a[n]))%mod);
	}
	return 0;
}