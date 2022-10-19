#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
inline void read(ll &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void write(ll x)
{
	int a[20];
	a[0]=0;
	if (x==0)
		putchar('0');
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar('0'+a[a[0]--]);
	putchar('\n');
}
const int N=100005;
struct data
{
	int s,add,d,pos;
}a[N*4];
int n,q,x,y,z,w,b[100];
inline void pushup(int x)
{
	if (a[x*2].d<a[x*2+1].d)
	{
		a[x].d=a[x*2].d;
		a[x].pos=a[x*2].pos;
	}
	else
	{
		a[x].d=a[x*2+1].d;
		a[x].pos=a[x*2+1].pos;
	}
}
void build(int l,int r,int x)
{
	if (l==r)
	{
		read(a[x].s);
		a[x].d=*lower_bound(b+1,b+1+b[0],a[x].s)-a[x].s;
		a[x].pos=l;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,x*2);
	build(mid+1,r,x*2+1);
	pushup(x);
}
inline void fg(ll y,int x)
{
	a[x].add=0;
	a[x].s=y;
	a[x].d=*lower_bound(b+1,b+1+b[0],a[x].s)-a[x].s;
}
inline void add(ll y,int x)
{
	if (a[x].s)
		fg(y+a[x].s,x);
	else
	{
		a[x].add+=y;
		a[x].d-=y;
	}
}
inline void pushdown(int x)
{
	if (a[x].s)
	{
		fg(a[x].s,x*2);
		fg(a[x].s,x*2+1);
	}
	else
	{
		if (a[x].add)
		{
			add(a[x].add,x*2);
			add(a[x].add,x*2+1);
		}
	}
	a[x].add=a[x].s=0;
	pushup(x);
}
ll getsum(int l,int r,int k,int x)
{
	if (l==r)
		return a[x].s;
	pushdown(x);
	int mid=(l+r)/2;
	if (k<=mid)
		return getsum(l,mid,k,x*2);
	else
		return getsum(mid+1,r,k,x*2+1);
}
void modify_fg(int l,int r,int L,int R,int k,int x)
{
	if (l==L&&r==R)
	{
		fg(k,x);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if (R<=mid)
		modify_fg(l,mid,L,R,k,x*2);
	if (L>mid)
		modify_fg(mid+1,r,L,R,k,x*2+1);
	if (R>mid&&L<=mid)
	{
		modify_fg(l,mid,L,mid,k,x*2);
		modify_fg(mid+1,r,mid+1,R,k,x*2+1);
	}
	pushup(x);
}
void modify_add(int l,int r,int L,int R,int k,int x)
{
	if (l==L&&r==R)
	{
		add(k,x);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if (R<=mid)
		modify_add(l,mid,L,R,k,x*2);
	if (L>mid)
		modify_add(mid+1,r,L,R,k,x*2+1);
	if (R>mid&&L<=mid)
	{
		modify_add(l,mid,L,mid,k,x*2);
		modify_add(mid+1,r,mid+1,R,k,x*2+1);
	}
	pushup(x);
}
void reset(int l,int r,int y,int x)
{
	if (l<=y&&y<=r&&a[x].s)
	{
		a[x].d=*lower_bound(b+1,b+1+b[0],a[x].s)-a[x].s;
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if (y<=mid)
		reset(l,mid,y,x*2);
	else
		reset(mid+1,r,y,x*2+1);
	pushup(x);
}
int getpos(int l,int r,int L,int R,int x)
{
	if (l==L&&r==R)
		return a[x].d<0?-a[x].pos:a[x].d==0?0:a[x].pos;
	pushdown(x);
	int mid=(l+r)/2;
	if (R<=mid)
		return getpos(l,mid,L,R,x*2);
	if (L>mid)
		return getpos(mid+1,r,L,R,x*2+1);
	return min(getpos(l,mid,L,mid,x*2),getpos(mid+1,r,mid+1,R,x*2+1));
}
signed main()
{
	//freopen("e.in","r",stdin);
	//freopen("e.out","w",stdout);
	read(n);
	read(q);
	for (ll i=1;i<=(ll)1e17;i*=42LL)	
		b[++b[0]]=i;
	build(1,n,1);
	while (q--)
	{
		read(x);
		if (x==1)
		{
			read(y);
			write(getsum(1,n,y,1));
		}
		if (x==2)
		{
			read(y);
			read(z);
			read(w);
			modify_fg(1,n,y,z,w,1);
		}
		if (x==3)
		{
			read(y);
			read(z);
			read(w);
			int k;
			do
			{
				modify_add(1,n,y,z,w,1);
				k=getpos(1,n,y,z,1);
				while(k<0)
				{
					reset(1,n,-k,1);
					k=getpos(1,n,y,z,1);
				}
			}while (k==0);
		}
	}
	return 0;
}