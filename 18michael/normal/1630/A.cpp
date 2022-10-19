#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,k,Test_num;
int a[1000002];
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
		read(n),read(k);
		if(k>(n/2)*(n/2-1))
		{
			puts("-1");
			continue;
		}
		if(k<n-1)
		{
			for(int i=0;i<n;++i)
			{
				if(!i)printf("%d %d\n",i,n-1-k);
				else if(i==k)printf("%d %d\n",i,n-1);
				else if(i!=n-1-k && i!=n-1 && i<n-1-i)printf("%d %d\n",i,n-1-i);
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				if(!i)printf("%d %d\n",0,2);
				else if(i==1)printf("%d %d\n",1,n-3);
				else if(i==n-2)printf("%d %d\n",n-2,n-1);
				else if(i!=2 && i!=n-3 && i!=n-1 && i<n-1-i)printf("%d %d\n",i,n-1-i);
			}
		}
	}
	return 0;
}