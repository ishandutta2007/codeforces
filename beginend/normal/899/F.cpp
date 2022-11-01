#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int N=200005;

int n,m;
char s[N];
struct tree{int s;}t[N*5];
set<int> w[65];
bool f[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int get_num(char c)
{
	if (c>='a'&&c<='z') return c-'a'+1;
	if (c>='A'&&c<='Z') return c-'A'+27;
	return c-'0'+53;
}

void build(int d,int l,int r)
{
	t[d].s=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
}

void ins(int d,int l,int r,int x)
{
	t[d].s--;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(d*2,l,mid,x);
	else ins(d*2+1,mid+1,r,x);
}

int query(int d,int l,int r,int k)
{
	if (l==r) return l;
	int mid=(l+r)/2;
	if (t[d*2].s>=k) return query(d*2,l,mid,k);
	else return query(d*2+1,mid+1,r,k-t[d*2].s);
}

int main()
{
	n=read();m=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		int x=get_num(s[i]);
		w[x].insert(i);
	}
	build(1,1,n);
	while (m--)
	{
		int l=read(),r=read();
		char ch[2];scanf("%s",ch);
		int x=get_num(ch[0]);
		l=query(1,1,n,l);r=query(1,1,n,r);
		set<int>::iterator it=w[x].lower_bound(l);
		while (it!=w[x].end()&&(*it)<=r)
		{
			ins(1,1,n,(*it));f[(*it)]=1;
			w[x].erase(it),it;it=w[x].lower_bound(l);
		}
	}
	for (int i=1;i<=n;i++) if (!f[i]) putchar(s[i]);
	return 0;
}