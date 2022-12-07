#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
struct qq
{
	int s1,s2;
	int c[2];
}tr[N*30];int num;
struct qt
{
	int l,r;
}a[N];
bool cmp (qt x,qt y)	{return x.l<y.l;}
void change (int &now,int l,int r,int x,int o,int c)
{
	if (now==0)
	{
		now=++num;
		tr[now].c[0]=tr[now].c[1]=0;
		tr[now].s1=tr[now].s2=0;
	}
	tr[now].c[o]+=c;
	if (l==r) return ;
	int mid=(l+r)>>1;
	if (x<=mid) change(tr[now].s1,l,mid,x,o,c);
	else change(tr[now].s2,mid+1,r,x,o,c);
}
int query (int now,int l,int r,int L,int R,int o)
{
	if (now==0) return 0;
	if (l==L&&r==R) return tr[now].c[o];
	int mid=(l+r)>>1;
	if (R<=mid) return query(tr[now].s1,l,mid,L,R,o);
	else if (L>mid) return query(tr[now].s2,mid+1,r,L,R,o);
	else return query(tr[now].s1,l,mid,L,mid,o)+query(tr[now].s2,mid+1,r,mid+1,R,o);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int rt=0;num=0;
		scanf("%d",&n);
		for (int u=1;u<=n;u++)	 scanf("%d%d",&a[u].l,&a[u].r);
		sort(a+1,a+1+n,cmp);
		for (int u=1;u<=n;u++) change(rt,1,1e9,a[u].l,0,1);
		int mx=0;
		for (int u=1;u<=n;u++)
		{
			int cnt=query(rt,1,1e9,1,a[u].r,0)+query(rt,1,1e9,a[u].l,1e9,1);
			mx=max(mx,cnt);
			change(rt,1,1e9,a[u].l,0,-1);
			change(rt,1,1e9,a[u].r,1,1);
		}
		printf("%d\n",n-mx);
	}
	return 0;
}