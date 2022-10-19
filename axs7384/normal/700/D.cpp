#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],c[N],f[N],g[N],n,q,m,len,ans[N];
map<int,int> mp;
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
inline void write(int x)
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
		putchar(a[a[0]--]+'0');
	putchar('\n');
}
struct data
{
	int l,r,pos;
	bool operator<(const data &a)const
	{
		return l/m==a.l/m?((l/m)&1?r>a.r:r<a.r):l/m<a.l/m;
	}
}b[N];
inline void add(int x,int y)
{
	if (f[x]>=m)
		mp.erase(x);
	else
		--g[f[x]];
	f[x]+=y;
	if (f[x]>=m)
		mp[x]=f[x];
	else
		++g[f[x]];
}
int heap[N];
inline void down(int x)
{
	int y=x*2;
	if (y>len)
		return;
	if (heap[y]>heap[y+1]&&y+1<=len)
		y=y+1;
	if (heap[x]>heap[y])
	{
		swap(heap[x],heap[y]);
		down(y);
	}
}
inline int work()
{
	int ans=0,pr=0;
	len=0;
	for (int i=1;i<m;++i)
		c[i]=g[i];
	for (int i=1;i<m;++i)
	{
		if (!c[i])
			continue;
		if (pr)
		{
			--c[i];
			int p=pr+i;
			ans+=p;
			if (p<m)
				++c[p];
			else
				heap[++len]=p;
			pr=0;
		}
		if (c[i]%2==1)
			pr=i;
		ans+=i*2*(c[i]/2);
		if (i*2<m)
			c[i*2]+=c[i]/2;
		else
		{
			for (int j=1;j<=c[i]/2;++j)
				heap[++len]=i*2;
		}
	}
	if (pr!=0)
		heap[++len]=pr;
	map<int,int>::iterator it;
	for (it=mp.begin();it!=mp.end();++it)
		heap[++len]=it->second;
	for (int i=len/2;i>=1;--i)
		down(i);
	while (len!=1)
	{
		int p=heap[1];
		heap[1]=heap[len];
		--len;
		down(1);
		int q=heap[1];
		ans+=p+q;
		heap[1]+=p;
		down(1);
	}
	return ans;
}
inline void change(int x,int y)
{
	if (b[x].l>b[y].l)
	{
		for (int i=b[y].l;i<b[x].l;++i)
			add(a[i],1);
	}
	else
	{
		for (int i=b[x].l;i<b[y].l;++i)
			add(a[i],-1);
	}
	if (b[x].r<b[y].r)
	{
		for (int i=b[x].r+1;i<=b[y].r;++i)
			add(a[i],1);
	}
	else
	{
		for (int i=b[y].r+1;i<=b[x].r;++i)
			add(a[i],-1);	
	}
}
int main()
{
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;++i)
		read(a[i]);
	read(q);
	for (int i=1;i<=q;++i)
	{
		read(b[i].l);
		read(b[i].r);
		b[i].pos=i;
	}
	m=(int)sqrt(n);
	sort(b+1,b+1+q);
	m*=10;
	g[0]=n;
	for (int i=b[1].l;i<=b[1].r;++i)
		add(a[i],1);
	for (int i=1;i<q;++i)
	{
		ans[b[i].pos]=work();
		change(i,i+1);
	}
	ans[b[q].pos]=work();
	for (int i=1;i<=q;++i)
		write(ans[i]);
}