#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,cnt,t,Test_num;
LL ans,res;
int a[100002];
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
		read(n),cnt=ans=t=0;
		for(int i=1;i<=n;++i)read(a[i]),cnt+=(a[i]&=1);
		if(abs(n-2*cnt)>1)
		{
			puts("-1");
			continue;
		}
		if(!(n-2*cnt))
		{
			res=0;for(int i=1;i<=n;++i)if(a[i]==1)res+=abs(i-(2*t+1)),++t;
			t=0;for(int i=1;i<=n;++i)if(a[i]==1)ans+=abs(i-(2*t+2)),++t;
			ans=min(ans,res);
		}
		else if(n-2*cnt==1)
		{
			for(int i=1;i<=n;++i)if(a[i]==1)ans+=abs(i-(2*t+2)),++t;
		}
		else for(int i=1;i<=n;++i)if(a[i]==1)ans+=abs(i-(2*t+1)),++t;
		printf("%lld\n",ans);
	}
	return 0;
}