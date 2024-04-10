#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,a_t,t,Test_num;LL x;
LL a[2002],suf[2002];
char s[2002];
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
		read(n),read(k),read(x),scanf("%s",s),a_t=0;
		for(int i=0,j;i<n;++i)
			if(s[i]=='*')
			{
				a[++a_t]=0;
				for(j=i;j<n && s[j]=='*';++j)++a[a_t];
				i=j-1;
			}
		suf[a_t+1]=1,t=1;
		for(int i=a_t;i;--i)if(suf[i+1]<=1.0*x/(a[i]*k+1))suf[i]=suf[i+1]*(a[i]*k+1);else suf[i]=x;
		for(int i=0,j;i<n;++i)
		{
			if(s[i]!='*')
			{
				putchar('a');
				continue;
			}
			++t;
			while(suf[t]<x)x-=suf[t],putchar('b');
			for(j=i;j<n && s[j]=='*';++j);i=j-1;
		}
		puts("");
	}
	return 0;
}