#include<cstdio>
int a,b,k;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(a),read(b),read(k);
	if(b==1)
	{
		if(!k)
		{
			puts("Yes");
			printf("1");for(int i=1;i<=a;++i)printf("0");puts("");
			printf("1");for(int i=1;i<=a;++i)printf("0");
		}
		else puts("No");
		return 0;
	}
	if(!a)
	{
		if(!k)
		{
			puts("Yes");
			for(int i=1;i<=b;++i)printf("1");puts("");
			for(int i=1;i<=b;++i)printf("1");
		}
		else puts("No");
		return 0;
	}
	if(k>a+b-2)return 0&puts("No");
	puts("Yes");
	if(k<=a)
	{
		for(int i=1;i<b;++i)printf("1");
		for(int i=1;i<=a-k;++i)printf("0");
		printf("1");for(int i=1;i<=k;++i)printf("0");
		puts("");for(int i=1;i<b;++i)printf("1");
		for(int i=1;i<=a;++i)printf("0");printf("1");
	}
	else
	{
		for(int i=1;i<=b;++i)printf("1");
		for(int i=1;i<=a;++i)printf("0");
		puts(""),printf("1");
		for(int i=1;i<=a+b-2-k;++i)printf("1");
		printf("0");for(int i=1;i<=k-a;++i)printf("1");
		for(int i=1;i<a;++i)printf("0");printf("1");
	}
	return 0;
}