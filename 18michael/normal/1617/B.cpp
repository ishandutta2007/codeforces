#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
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
		read(n);
		if(n&1)
		{
			if((n/2)&1)printf("%d %d %d\n",n/2-2,n/2+2,1);
			else printf("%d %d %d\n",n/2-1,n/2+1,1);
		}
		else printf("%d %d %d\n",2,n-3,1);
	}
	return 0;
}