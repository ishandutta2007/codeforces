#include<cstdio>
#include<cmath>
int n,k,Test_num;
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
	while(Test_num--)read(n),k=sqrt(2*n-1),k-=((k&1)^1),printf("%d\n",(k-1)/2);
	return 0;
}