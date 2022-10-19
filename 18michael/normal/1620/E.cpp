#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 500000
using namespace std;
int q,n=0;
int a[500002],rt[500002],la[500002]={};
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
	read(q);
	for(int opt,x,y;q--;)
	{
		read(opt),read(x);
		if(opt==1)
		{
			++n;
			if(la[x])rt[n]=la[x];
			else la[x]=rt[n]=n;
		}
		else
		{
			read(y);
			if(!la[x] || x==y)continue;
			if(la[y])getroot(la[x]),getroot(la[y]),rt[rt[la[x]]]=rt[la[y]];
			else la[y]=rt[la[x]];
			la[x]=0;
		}
	}
	for(int i=1;i<=Mx;++i)if(la[i])a[la[i]]=i;
	for(int i=1;i<=n;++i)getroot(i),printf("%d ",a[rt[i]]);
	return 0;
}