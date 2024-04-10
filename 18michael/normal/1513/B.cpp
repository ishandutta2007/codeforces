#include<bits/stdc++.h>
#define Mx 29
#define LL long long
#define mod 1000000007
using namespace std;
int n,Test_num;LL res,ans;
int a[200002],cnt[32];
bool u[200002];
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
		read(n),res=-1;
		for(int i=1;i<=n;++i)read(a[i]),u[i]=1;
		for(int i=0;i<=Mx;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=Mx;++j)
				cnt[j]+=((a[i]>>j)&1);
		for(int i=0;i<=Mx;++i)
			if(cnt[i]==n-1)
			{
				res=0;
				break;
			}
		if(!res)
		{
			puts("0");
			continue;
		}
		for(int i=0;i<=Mx;++i)
			if(cnt[i]<n-1)
				for(int j=1;j<=n;++j)
					if((a[j]>>i)&1)
						u[j]=0;
		res=0;
		for(int i=1;i<=n;++i)res+=u[i];
		ans=(res*(res-1))%mod;
		for(int i=1;i<=n-2;++i)ans=(ans*i)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}