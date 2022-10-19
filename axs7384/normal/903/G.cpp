#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int inf=1e9+7;
#define ll long long
const ll Inf=1e18+7;
const int N=200005;
int a[N],b[N];
int x,y,z,n,m,q;
ll ans[N];
int cnt;
vector<pair<int,int> > v[N];
struct data
{
	int m,tag;
}t[N*4];
inline void read(int &x)
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
	if (x==0)
		putchar('0');
	int a[20];
	a[0]=0;
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar('0'+a[a[0]--]);
	putchar('\n');
}


inline void pushup(int x)
{
	t[x].m=min(t[x*2].m,t[x*2+1].m);
}
inline void pushdown(int x)
{
	if (t[x].tag)
	{
		t[x*2].tag+=t[x].tag;
		t[x*2+1].tag+=t[x].tag;
		t[x*2].m-=t[x].tag;
		t[x*2+1].m-=t[x].tag;
		t[x].tag=0;
	}
}
void build(int l,int r,int x)
{
	if (l==r)
	{
		t[x].m=b[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,x*2);
	build(mid+1,r,x*2+1);
	pushup(x);
}
int ask(int l,int r,int L,int R,int x)
{
	if ((l==L)&&(r==R))
		return t[x].m;
	int mid=(L+R)/2;
	//if (x>=1000000)
		//cout<<l<<' '<<r<<' '<<L<<' '<<R<<' '<<x<<'\n';
	pushdown(x);
	if (l>mid)
		return ask(l,r,mid+1,R,x*2+1);
	if (r<=mid)
		return ask(l,r,L,mid,x*2);
	return min(ask(l,mid,L,mid,x*2),ask(mid+1,r,mid+1,R,x*2+1));
}
void dec(int l,int r,int L,int R,int x,int y)
{
	if (l==L&&r==R)
	{
		t[x].m-=y;
		t[x].tag+=y;
		return;
	}
	pushdown(x);
	int mid=(L+R)/2;
	if (l>mid)
		dec(l,r,mid+1,R,x*2+1,y);
	if (r<=mid)
		dec(l,r,L,mid,x*2,y);
	if (l<=mid&&r>mid)
	{
		dec(l,mid,L,mid,x*2,y);
		dec(mid+1,r,mid+1,R,x*2+1,y);
	}
	pushup(x);
}


int rt[N],ls[N*40],rs[N*40],tot,s[N*40];
inline void push_up(int x)
{
	s[x]=s[ls[x]]+s[rs[x]];
}
void add(int l,int r,int p,int y,int qx,int &hx)
{
	if (!hx)
		hx=++tot;
	if (l==r)
	{
		s[hx]=y;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid)
	{
		rs[hx]=rs[qx];
		add(l,mid,p,y,ls[qx],ls[hx]);
	}
	else
	{
		ls[hx]=ls[qx];
		add(mid+1,r,p,y,rs[qx],rs[hx]);
	}
	push_up(hx);
}
int js(int l,int r,int L,int R,int x)
{
	if (x==0)
		return 0;
	if (l==L&&r==R)
		return s[x];
	int mid=(L+R)/2;
	if (l>mid)
		return js(l,r,mid+1,R,rs[x]);
	if (r<=mid)
		return js(l,r,L,mid,ls[x]);
	return js(l,mid,L,mid,ls[x])+js(mid+1,r,mid+1,R,rs[x]);
}


ll f[N*4];
inline ll erfen(int x,int y)
{
	int l=0,r=m;
	ll sum=0;
	while (l<=r)
	{
		int mid=(l+r)/2,p=js(x,n,1,n,rt[mid]);
		if (p<=y)
		{
			if (mid!=m)
				sum=ans[mid]+y-p;
			else
				sum=ans[mid];
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return sum;
}
inline void Pushup(int x)
{
	f[x]=min(f[x*2],f[x*2+1]);
}
void Build(int l,int r,int x)
{
	if (l==r)
	{
		if (l==1)
			f[x]=Inf;
		else
			f[x]=erfen(l,a[l-1]);
		return;
	}
	int mid=(l+r)/2;
	Build(l,mid,x*2);
	Build(mid+1,r,x*2+1);
	Pushup(x);
}
void change(int l,int r,int x,int p,int y)
{
	if (l==r)
	{
		f[x]=erfen(l,y);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid)
		change(l,mid,x*2,p,y);
	else
		change(mid+1,r,x*2+1,p,y);
	Pushup(x);
}


int g[N];
int main()
{
	//freopen("flow.in","r",stdin);
	//freopen("flow.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for (int i=1;i<n;++i)
	{
		read(a[i]);
		read(b[i]);
		//c[i].push_back(mp(a[i],0));
	}
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		read(z);
		v[x].push_back(mp(y,z));
	}


	/*read(q);
	for (int i=1;i<=q;++i)
	{
		read(x);
		read(y);
		//c[x].push_back(mp(y,i));
	}
	//for (int i=1;i<n;++i)
		//sort(c[x].begin(),c[x].end());*/


	build(1,n-1,1);
	ans[0]=0;
	for (int i=1;i<=n;++i)
	{
		for (unsigned j=0;j<v[i].size();++j)
		{
			x=v[i][j].first;
			y=v[i][j].second;
			if (x!=n)
				y=min(y,ask(x,n-1,1,n-1,1));
			++cnt;
			g[i]+=y;
			ans[cnt]=ans[cnt-1]+y;
			add(1,n,i,g[i],rt[cnt-1],rt[cnt]);
			if (x!=n)
				dec(x,n-1,1,n-1,1,y);
		}
	}


	Build(1,n,1);
	write(f[1]);
	while (q--)
	{
		read(x);
		read(y);
		change(1,n,1,x+1,y);
		write(f[1]);
	}
	return 0;
}