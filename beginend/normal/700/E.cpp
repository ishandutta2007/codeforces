#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=400005;

int n,ch[N][26],mx[N],fa[N],b[N],c[N],cnt,sz,rt[N],dp[N],last,id[N],pos[N];
char s[N];
struct tree{int l,r;}t[N*50];

void extend(int i,int x)
{
	int p,q,np,nq;
	p=last;last=np=++cnt;mx[np]=mx[p]+1;id[np]=i;
	for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if (!p) fa[np]=1;
	else
	{
		q=ch[p][x];
		if (mx[q]==mx[p]+1) fa[np]=q;
		else
		{
			nq=++cnt;mx[nq]=mx[p]+1;id[nq]=i;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
}

void ins(int &d,int l,int r,int x)
{
	if (!d) d=++sz;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

int merge(int x,int y)
{
	if (!x||!y) return x+y;
	int d=++sz;
	t[d].l=merge(t[x].l,t[y].l);
	t[d].r=merge(t[x].r,t[y].r);
	return d;
}

bool query(int d,int l,int r,int x,int y)
{
	if (!d) return 0;
	if (l==x&&r==y) return 1;
	int mid=(l+r)/2;
	if (x<=mid&&query(t[d].l,l,mid,x,min(y,mid))) return 1;
	if (y>mid&&query(t[d].r,mid+1,r,max(x,mid+1),y)) return 1;
	return 0;
}

void build()
{
	for (int i=1;i<=cnt;i++) b[mx[i]]++;
	for (int i=1;i<=cnt;i++) b[i]+=b[i-1];
	for (int i=cnt;i>=1;i--) c[b[mx[i]]--]=i;
	for (int i=cnt;i>=2;i--)
	{
		int x=c[i];
		ins(rt[x],1,n,id[x]);
		rt[fa[x]]=merge(rt[fa[x]],rt[x]);
	}
}

int main()
{
	scanf("%d%s",&n,s+1);
	last=cnt=1;
	for (int i=1;i<=n;i++) extend(i,s[i]-'a');
	build();
	int ans=1;
	for (int i=2;i<=cnt;i++)
	{
		int x=c[i];
		if (fa[x]==1) dp[x]=1,pos[x]=x;
		else if (query(rt[pos[fa[x]]],1,n,id[x]-mx[x]+mx[pos[fa[x]]],id[x]-1)) dp[x]=dp[fa[x]]+1,pos[x]=x;
		else dp[x]=dp[fa[x]],pos[x]=pos[fa[x]];
		ans=max(ans,dp[x]);
	}
	printf("%d",ans);
	return 0;
}