#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 20
using namespace std;
int l,r,mn,Test_num;
int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int calc(int x,int y)
{
	int res=((x>>(y+1))<<y);
	x&=((1<<(y+1))-1);
	if((++x)>(1<<y))x=(1<<y);
	return res+x;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(l),read(r),mn=r-l+1;
		for(int i=0;i<=Mx;++i)mn=min(mn,calc(r,i)-calc(l-1,i));
		printf("%d\n",mn);
	}
	return 0;
}