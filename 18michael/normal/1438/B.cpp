#include<cstdio>
#include<algorithm>
using namespace std;
int n,Test_num,ans;
int a[1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n);
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1,cmp),ans=0;
		for(int i=1;i<n;++i)
			if(a[i]==a[i+1])
			{
				ans=1;
				break;
			}
		puts(ans? "YES":"NO");
	}
	return 0;
}