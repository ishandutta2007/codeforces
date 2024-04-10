#include<bits/stdc++.h>
using namespace std;
int n,mn,mx,Test_num;
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
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==1)mn=i;
		if(a[i]==n)mx=i;
	}
	printf("%d",min(max(n-min(mn,mx),max(mn,mx)-1),n-1));
	return 0;
}