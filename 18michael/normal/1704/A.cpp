#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,ok,ok1,Test_num;
char a[1000002],b[1000002];
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
		read(n),read(m),scanf("%s%s",a+1,b+1),ok=1,ok1=0;
		for(int i=2;i<=m;++i)if(a[n-m+i]!=b[i])ok=0;
		for(int i=1;i<=n-m+1;++i)if(a[i]==b[1])ok1=1;
		puts(ok && ok1? "YES":"NO");
	}
	return 0;
}