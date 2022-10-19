#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,t,ans,Test_num;
int a[1000002],cnt[102],f[102];
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
		read(n),ans=0;
		for(int i=1;i<=n;++i)read(a[i]);
		for(int o=1;o<=n;++o)
		{
			f[o-1]=0;
			for(int i=o;i<=n;++i)f[i]=0;
			for(int i=o-1;i<n;++i)
			{
				t=0;
				for(int j=0;j<=n;++j)cnt[j]=0;
				for(int j=i+1;j<=n;++j)
				{
					if(a[j]<=n)
					{
						++cnt[a[j]];
						while(cnt[t])++t;
					}
					f[j]=max(f[j],f[i]+t+1);
				}
			}
			for(int i=o;i<=n;++i)ans+=f[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}