#include<bits/stdc++.h>
#define LL long long
using namespace std;
int Test_num,ans;LL n,Mx;
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
		read(n),ans=0,Mx=205000000000000000LL;
		while(Mx>=2050)ans+=n/Mx,n%=Mx,Mx/=10;
		printf("%d\n",n? -1:ans);
	}
	return 0;
}