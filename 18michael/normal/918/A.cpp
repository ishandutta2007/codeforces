#include<bits/stdc++.h>
using namespace std;
int n,t=0;
int f[16]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
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
	for(int i=1;i<=n;++i)if(i==f[t])printf("O"),++t;else printf("o");
	return 0;
}