#include<bits/stdc++.h>
using namespace std;
int n,ans,Test_num;
int a[1002];
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
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			if(n-i+1<=a[i])
			{
				ans=n-i+1;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}