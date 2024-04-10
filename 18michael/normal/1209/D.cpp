#include<bits/stdc++.h>
using namespace std;
int n,m,t=0;
int rt[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(m),read(n);
	for(int i=1;i<=m;++i)rt[i]=i;
	for(int i=1,x,y;i<=n;++i)
	{
		read(x),read(y),getroot(x),getroot(y);
		if((x=rt[x])!=(y=rt[y]))rt[x]=y,++t;
	}
	return 0&printf("%d",n-t);
}