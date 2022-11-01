#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=300005;

int n,a[N],sz,bin[35],rt;
struct tree{int l,r,s;}t[N*40];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void ins(int &d,int dep,int v)
{
	if (!d) d=++sz;
	t[d].s++;
	if (dep<0) return;
	if (v&bin[dep]) ins(t[d].r,dep-1,v);
	else ins(t[d].l,dep-1,v);
}

int query(int d,int dep,int v)
{
	t[d].s--;
	if (dep<0) return 0;
	if (v&bin[dep])
	{
		if (t[t[d].r].s) return query(t[d].r,dep-1,v);
		else return query(t[d].l,dep-1,v)+bin[dep];
	}
	else
	{
		if (t[t[d].l].s) return query(t[d].l,dep-1,v);
		else return query(t[d].r,dep-1,v)+bin[dep];
	}
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		ins(rt,30,x);
	}
	for (int i=1;i<=n;i++) printf("%d ",query(rt,30,a[i]));
	return 0;
}