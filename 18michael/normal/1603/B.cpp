#include<bits/stdc++.h>
#define LL long long
using namespace std;
int Test_num;
LL x,y,a,b,n;
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
		read(x),read(y),a=(y/x),b=(y%x),n=a*x+b;
		if(y<x)printf("%lld\n",n=x+y);
		else if(x==y)printf("%lld\n",n=x);
		else if(y>=2*x)printf("%lld\n",n=y-(x+(y%x))/2);
		else printf("%lld\n",n=y-(y-x)/2);
		/*{
			printf("%lld\n",n=y-(x+(y%x))/2);
			for(int i=x;i<=y;++i)
				if(i%x==y%i)
					printf("%d %lld\n",i,i%x);
		}*/
		//printf("(%lld = %lld)\n",n%x,y%n);
	}
	return 0;
}
/*
1000
4889598 6566956
4889598 9866956
*/