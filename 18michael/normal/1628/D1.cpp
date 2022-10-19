#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,Test_num;
LL f[2002][2002];
LL pw[2002],ipw[2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	pw[0]=ipw[0]=1;
	for(int i=1;i<=2000;++i)pw[i]=(pw[i-1]<<1)%mod,ipw[i]=(ipw[i-1]*500000004)%mod,f[1][i]=ipw[i-1];
	for(int i=2;i<=2000;++i)
	{
		f[i][i]=i;
		for(int j=i+1;j<=2000;++j)f[i][j]=((f[i][j-1]+f[i-1][j-1])*500000004)%mod;
	}
	read(Test_num);
	for(int x,y,z;Test_num--;)read(x),read(y),read(z),printf("%lld\n",(f[y][x]*z)%mod);
	return 0;
}