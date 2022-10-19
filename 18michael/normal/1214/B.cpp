#include<bits/stdc++.h>
using namespace std;
int n,b,g;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(b),read(g),read(n);
	return 0&printf("%d",min(b,n)-max(0,n-g)+1);
}