#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=300005;

int n,m,sz;
struct tree{int l,r,s,tag;}t[N*50];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void pushdown(int d,int l,int r)
{
	if (l==r||t[d].tag==-1) return;
	int mid=(l+r)/2;
	if (!t[d].l) t[d].l=++sz;
	if (!t[d].r) t[d].r=++sz;
	if (t[d].tag==0)
	{
		t[t[d].l].tag=t[t[d].r].tag=0;
		t[t[d].l].s=mid-l+1;
		t[t[d].r].s=r-mid;
	}
	else
	{
		t[t[d].l].tag=t[t[d].r].tag=1;
		t[t[d].l].s=t[t[d].r].s=0;
	}
	t[d].tag=-1;
}

void ins(int &d,int l,int r,int x,int y,int z)
{
	if (!d) d=++sz,t[d].tag=-1;
	if (t[d].tag==z) return;
	pushdown(d,l,r);
	if (l==x&&r==y) {t[d].tag=z;t[d].s=!z?r-l+1:0;return;}
	int mid=(l+r)/2;
	if (y<=mid) ins(t[d].l,l,mid,x,y,z);
	else if (x>mid) ins(t[d].r,mid+1,r,x,y,z);
	else ins(t[d].l,l,mid,x,mid,z),ins(t[d].r,mid+1,r,mid+1,y,z);
	t[d].s=t[t[d].l].s+t[t[d].r].s;
}

int main()
{
	n=read();m=read();sz=1;t[1].s=n;t[1].tag=0;
	int rt=1;
	while (m--)
	{
		int l=read(),r=read(),op=read();
		if (op==1) ins(rt,1,n,l,r,1);
		else ins(rt,1,n,l,r,0);
		printf("%d\n",t[1].s);
	}
	return 0;
}