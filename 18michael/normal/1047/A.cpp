#include<bits/stdc++.h>
using namespace std;
int n;
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
	if(!(n%3))printf("%d %d %d",1,1,n-2);
	else printf("%d %d %d",1,2,n-3);
	return 0;
}