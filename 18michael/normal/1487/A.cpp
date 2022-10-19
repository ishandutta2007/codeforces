#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,Test_num;
int a[102];
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
		for(i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(i=2;i<=n;++i)if(a[i]!=a[1])break;
		printf("%d\n",n-i+1);
	}
	return 0;
}