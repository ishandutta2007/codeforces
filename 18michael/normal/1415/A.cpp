#include<cstdio>
int n,m,r,c,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int abs(int x)
{
	return x>0? x:-x;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	read(Test_num);
	while(Test_num--)read(n),read(m),read(r),read(c),printf("%d\n",max(max(abs(n-r)+abs(m-c),abs(1-r)+abs(m-c)),max(abs(n-r)+abs(1-c),abs(1-r)+abs(1-c))));
	return 0;
}