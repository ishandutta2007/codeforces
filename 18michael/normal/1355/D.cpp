#include<cstdio>
int x,y;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(x),read(y);
	if(x>=y-x+1)printf("NO");
	else
	{
		puts("YES");
		for(int i=1;i<x;++i)printf("1 ");
		printf("%d\n%d",y-x+1,x);
	}
	return 0;
}