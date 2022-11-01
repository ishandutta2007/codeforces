#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,a[N];
struct tree{int mx,pl,pr,s,l,r,sl,sr,ppl,ppr;}t[N*5];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void updata(int d,int l,int r)
{
	int mid=(l+r)/2;
	if (!t[d*2].mx) t[d]=t[d*2+1];
	else if (!t[d*2+1].mx) t[d]=t[d*2];
	else
	{
		t[d].s=t[d*2].s+t[d*2+1].s;
		if (t[d*2].sl==t[d*2].s&&t[d*2].l==t[d*2+1].l) t[d].sl=t[d*2].sl+t[d*2+1].sl,t[d].l=t[d*2].l,t[d].ppl=t[d*2+1].ppl;
		else t[d].sl=t[d*2].sl,t[d].l=t[d*2].l,t[d].ppl=t[d*2].ppl;
		if (t[d*2+1].sr==t[d*2+1].s&&t[d*2+1].r==t[d*2].r) t[d].sr=t[d*2+1].sr+t[d*2].sr,t[d].r=t[d*2+1].r,t[d].ppr=t[d*2].ppr;
		else t[d].sr=t[d*2+1].sr,t[d].r=t[d*2+1].r,t[d].ppr=t[d*2+1].ppr;
		t[d].mx=t[d*2].mx;t[d].pl=t[d*2].pl;t[d].pr=t[d*2].pr;
		if (t[d*2].r==t[d*2+1].l&&t[d*2].sr+t[d*2+1].sl>t[d].mx) t[d].mx=t[d*2].sr+t[d*2+1].sl,t[d].pl=t[d*2].ppr,t[d].pr=t[d*2+1].ppl;
		if (t[d*2+1].mx>t[d].mx) t[d].mx=t[d*2+1].mx,t[d].pl=t[d*2+1].pl,t[d].pr=t[d*2+1].pr;
	}
}

void build(int d,int l,int r)
{
	if (l==r)
	{
		t[d].sl=t[d].sr=1;
		t[d].l=t[d].r=a[l];
		t[d].mx=1;
		t[d].pl=t[d].pr=t[d].ppl=t[d].ppr=l;
		t[d].s=1;
		return;
	}
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
	updata(d,l,r);
}

void ins(int d,int l,int r,int x,int y)
{
	if (x>y) return;
	if (l==x&&r==y)
	{
		t[d].l=t[d].r=t[d].sl=t[d].sr=t[d].mx=t[d].pl=t[d].pr=t[d].s=t[d].ppl=t[d].ppr=0;
		return;
	}
	int mid=(l+r)/2;
	ins(d*2,l,mid,x,min(y,mid));
	ins(d*2+1,mid+1,r,max(x,mid+1),y);
	updata(d,l,r);
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	int ans=0;
	while (t[1].mx)
	{
		ins(1,1,n,t[1].pl,t[1].pr);
		ans++;
	}
	printf("%d",ans);
	return 0;
}