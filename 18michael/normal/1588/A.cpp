#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
bool ok;
int a[102],b[102];
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
		for(int i=1;i<=n;++i)read(b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1),ok=1;
		for(int i=1;i<=n;++i)if(b[i]-a[i]!=0 && b[i]-a[i]!=1){ok=0;break;}
		puts(ok? "YES":"NO");
	}
	return 0;
}