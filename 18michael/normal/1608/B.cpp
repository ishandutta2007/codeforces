#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,a,b,t1,t2,Test_num;
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
		read(n),read(a),read(b);
		if(a+b>n-2)puts("-1");
		else if(abs(a-b)>1)puts("-1");
		else if(a==b)
		{
			t1=1,t2=b+2;
			while(t1<=b+1)printf("%d %d ",t1,t2),++t1,++t2;
			while(t2<=n)printf("%d ",t2),++t2;
			puts("");
		}
		else if(a<b)
		{
			printf("%d ",b+1),t1=b+2,t2=1;
			while(t2<b+1)printf("%d %d ",t2,t1),++t2,++t1;
			while(t1<=n)printf("%d ",t1),++t1;
			puts("");
		}
		else
		{
			t1=1,t2=n-b;
			while(t1<n-a-b)printf("%d ",t1),++t1;
			while(t2<=n)printf("%d %d ",t2,t1),++t2,++t1;
			puts("");
		}
	}
	return 0;
}