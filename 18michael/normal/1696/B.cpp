#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,l,r,Test_num;
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
		read(n),ok=1;
		for(int i=1;i<=n;++i)read(a[i]),ok&=(!a[i]);
		if(ok)
		{
			puts("0");
			continue;
		}
		for(l=1,r=n;l<=r && !a[l];++l);
		for(;l<=r && !a[r];--r);
		ok=1;
		for(int i=l;i<=r;++i)ok&=(a[i]>0);
		printf("%d\n",2-ok);
	}
	return 0;
}