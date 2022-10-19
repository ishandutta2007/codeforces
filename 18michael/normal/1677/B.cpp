#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,tot,las,Test_num;
int ans[1000002],ans2[1000002];
bool u[1000002];
char s[1000002];
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
		read(n),read(m),scanf("%s",s+1),tot=n*m,las=-inf;
		for(int i=0;i<m;++i)u[i]=0;
		for(int i=1;i<=tot;++i)
		{
			if(s[i]=='1')las=i;
			ans[i]=(las>=i-m+1);
		}
		for(int i=m+1;i<=tot;++i)ans[i]+=ans[i-m];
		for(int i=1;i<=tot;++i)
		{
			ans2[i]=ans2[i-1];
			if(!u[i%m])ans2[i]+=(u[i%m]|=(s[i]=='1'));
		}
		for(int i=1;i<=tot;++i)printf("%d%c",ans[i]+ans2[i],i==tot? '\n':' ');
	}
	return 0;
}