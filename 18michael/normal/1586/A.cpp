#include<bits/stdc++.h>
using namespace std;
int n,sum,Test_num;
int a[102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x)
{
	for(int i=2;i*i<=x;++i)
		if(!(x%i))
			return 1;
	return 0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),sum=0;
		for(int i=1;i<=n;++i)read(a[i]),sum+=a[i];
		if(check(sum))
		{
			printf("%d\n",n);
			for(int i=1;i<=n;++i)printf("%d%c",i,i==n? '\n':' ');
		}
		else
		{
			printf("%d\n",n-1);
			for(int i=1;i<=n;++i)
			{
				if(sum && check(sum-a[i]))
				{
					sum=0;
					continue;
				}
				printf("%d ",i);
			}
			puts("");
		}
	}
	return 0;
}