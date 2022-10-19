#include<cstdio>
int Test_num,a,b,c,d,e;
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
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e=(a&1)+(b&1)+(c&1)+(d&1);
		puts((e==2 || (e>2 && !(a && b && c)))? "No":"Yes");
	}
	return 0;
}