#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1e6+5;
int n,m;
int A[N+5];
int t[N+5],pri[N+5],d[N+5],tot=0;
bool ok[N+5];
void prepare ()
{
	memset(ok,true,sizeof(ok));
	d[1]=1;
	for (int u=2;u<=N;u++)
	{
		if (ok[u]) {pri[++tot]=u;d[u]=2;t[u]=1;}
		for (int i=1;i<=tot;i++)
		{
			int j=pri[i];
			if (j*u>N) break;
			ok[j*u]=false;
			if (u%j==0)
			{
				d[u*j]=d[u]/(t[u]+1)*(t[u]+2);
				t[u*j]=t[u]+1;
				break;
			}
			else	{d[u*j]=d[u]*2;t[u*j]=1;}
		}
	}
	//for (int u=1;u<=N;u++) if (d[u]==u) printf("%d\n",u);
}
int f[N+5];
struct qq
{
	int l,r;
	int s1,s2;
	LL c;// 
	bool ok;//1 
}tr[N*2];int num=0;
void update (int x)
{
	int s1=tr[x].s1,s2=tr[x].s2;
	tr[x].c=tr[s1].c+tr[s2].c;
	tr[x].ok=(tr[s1].ok&tr[s2].ok);
	return ;
}
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r)
	{
		tr[a].c=A[l];
		if (A[l]==1||A[l]==2)	tr[a].ok=true;
		else tr[a].ok=false;
		return ;
	}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	update(a);
}
void change (int now,int l,int r)
{
	if (tr[now].ok) return ;
	if (tr[now].l==tr[now].r)
	{
		tr[now].c=d[tr[now].c];
		if (tr[now].c==1||tr[now].c==2) tr[now].ok=true;
		return ;
	}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) change(s1,l,r);
	else if (l>mid) change(s2,l,r);
	else change(s1,l,mid),change(s2,mid+1,r);
	update(now);
}
LL get (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)
		return tr[now].c;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid)  return get(s1,l,r);
	else if (l>mid) return get(s2,l,r);
	else return get(s1,l,mid)+get(s2,mid+1,r);
}
int read ()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	prepare();
	n=read();m=read();
	for (int u=1;u<=n;u++)	A[u]=read();
	bt(1,n);
	for (int u=1;u<=m;u++)
	{
		int op,l,r;
		op=read();l=read();r=read();
		if (op==1)	change(1,l,r);
		else printf("%I64d\n",get(1,l,r));
	}
	return 0;
}