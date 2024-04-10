#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=300005;

int bin[25],n,m,sz,root;
struct tree{int s,tag,l,r;}t[N*30];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void ins(int &d,int x,int y)
{
	if (!d) d=++sz;
	if (x==-1)
	{
		t[d].s=1;return;
	}
	if ((y&bin[x])) ins(t[d].r,x-1,y);
	else ins(t[d].l,x-1,y);
	t[d].s=t[t[d].l].s&t[t[d].r].s;
}

void pushdown(int d,int x)
{
	if (!t[d].tag||!x) return;
	int w=t[d].tag;t[d].tag=0;
	t[t[d].l].tag^=w;t[t[d].r].tag^=w;
	if ((w&bin[x-1])) swap(t[t[d].l].l,t[t[d].l].r),swap(t[t[d].r].l,t[t[d].r].r);
}

int query(int d,int x)
{
	if (x==-1) return 0;
	pushdown(d,x);
	if (!t[t[d].l].s) return query(t[d].l,x-1);
	else return query(t[d].r,x-1)+bin[x];
}

int main()
{
	//freopen("a.in","r",stdin);
	bin[0]=1;
	for (int i=1;i<=20;i++) bin[i]=bin[i-1]*2;
	n=read();m=read();
	for (int i=1,x;i<=n;i++) x=read(),ins(root,20,x);
	while (m--)
	{
		int x=read();
		if ((x&bin[20])) swap(t[root].l,t[root].r);
		t[root].tag^=x;
		printf("%d\n",query(root,20));
	}
	return 0;
}