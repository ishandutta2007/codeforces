#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;bool ok;
int a[1000002],b[1000002],cnt[1000002],cnt1[1000002];
bool u[1000002];
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
		read(n),ok=1;
		for(int i=1;i<=n;++i)cnt[i]=cnt1[i]=u[i]=0;
		for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]],++cnt1[a[i]];
		for(int i=1;i<=n;++i)read(b[i]);
		for(int i=n,j=n;i;--i)
		{
			u[a[i]]=1;
			while(j && b[j]==a[i])--cnt[b[j]],--j;
			--cnt1[a[i]];
			//printf(" %d %d %d\n",i,cnt[a[i]],cnt1[a[i]]);
			if(cnt1[a[i]]<cnt[a[i]])
			{
				ok=0;
				break;
			}
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}