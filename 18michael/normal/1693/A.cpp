#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;
bool ok;
LL a[1000002];
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
		for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
		if(a[n])ok=0;
		while(!a[n])--n;
		for(int i=1;i<=n;++i)if(a[i]<=0)ok=0;
		puts(ok? "Yes":"No");
	}
	return 0;
}