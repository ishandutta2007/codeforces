#include<bits/stdc++.h>
using namespace std;
int n,m,sq,Test_num;
int X[200002],Y[200002],Z[200002],p[200002]={},la[200002];
int t[452][200002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void Main()
{
	read(n),read(m),sq=sqrt(m);
	for(int i=1;i<=n;++i)read(X[i]),read(Y[i]),Z[i]=X[i]+Y[i];
	for(int i=1,op,x;i<=m;++i)
	{
		read(op),read(x),op=(op==2? -1:1);
		if(Z[x]>sq)
		{
			if(op>0)la[x]=i;
			else
			{
				la[x]+=(i-la[x])/Z[x]*Z[x];
				if(max(la[x]+X[x],i)<=m)p[max(la[x]+X[x],i)]+=op;
				if(la[x]+Z[x]<=m)p[la[x]+Z[x]]-=op;
				la[x]+=Z[x];
			}
			for(int j=la[x];j<=m;j+=Z[x])
			{
				if(j+X[x]<=m)p[j+X[x]]+=op;
				if(j+Z[x]<=m)p[j+Z[x]]-=op;
			}
		}
		else
		{
			if(op>0)la[x]=i;
			else
			{
				la[x]+=(i-la[x])/Z[x]*Z[x];
				if(max(la[x]+X[x],i)<=m)p[max(la[x]+X[x],i)]+=op;
				if(la[x]+Z[x]<=m)p[la[x]+Z[x]]-=op;
				la[x]+=Z[x];
			}
			if(la[x]+X[x]<=m)t[Z[x]][la[x]+X[x]]+=op;
			if(la[x]+Z[x]<=m)t[Z[x]][la[x]+Z[x]]-=op;
		}
	}
	for(int i=1;i<=sq;++i)
		for(int j=1;j<=m;++j)
		{
			if(j>i)t[i][j]+=t[i][j-i];
			p[j]+=t[i][j];
		}
	for(int i=1;i<=m;++i)printf("%d\n",p[i]+=p[i-1]);
}
int main()
{
	//for(read(Test_num);Test_num--;)
	Main();
	return 0;
}