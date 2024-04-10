#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ok;
int a[2002],pre[2002],suf[2002];
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
		read(n),ok=0;
		for(int i=1;i<=n;++i)read(a[i]);
		pre[0]=suf[n+1]=0;
		for(int i=1;i<=n;++i)pre[i]=(pre[i-1]^a[i]);
		for(int i=n;i;--i)suf[i]=(suf[i+1]^a[i]);
		for(int i=1;i<n;++i)if(pre[i]==suf[i+1])ok=1;
		for(int i=1;i<n-1;++i)
			for(int j=i+2;j<=n;++j)
				if(pre[i]==suf[j] && !pre[j-1])
					ok=1;
		puts(ok? "YES":"NO");
	}
	return 0;
}