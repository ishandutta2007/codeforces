#include<bits/stdc++.h>
#define pb push_back
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=150005;
const int MOD=998244353;

int n,q,dep[N],fa[N],size[N],top[N],pos[N],mx[N],son[N],tim,a[N];
std::vector<int> e[N];
struct tree{int s1,s2;}t[N*4];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void dfs1(int x)
{
	dep[x]=dep[fa[x]]+1;size[x]=1;
	for (auto to:e[x])
	{
		if (to==fa[x]) continue;
		fa[to]=x;
		dfs1(to);
		size[x]+=size[to];
	}
}

void dfs2(int x,int chain)
{
	top[x]=chain;pos[x]=++tim;int k=0;
	for (auto to:e[x])
		if (to!=fa[x]&&size[to]>size[k]) k=to;
	if (k) dfs2(k,chain);
	son[x]=k;
	for (auto to:e[x])
		if (to!=k&&to!=fa[x]) dfs2(to,to);
	mx[x]=tim;
}

void updata(int d)
{
	t[d].s1=(t[ls].s1+t[rs].s1)%MOD;
	t[d].s2=(t[ls].s2+t[rs].s2)%MOD;
}

void ins(int d,int l,int r,int x,int y,int op)
{
	if (l==r)
	{
		if (op==1) (t[d].s1+=y)%=MOD;
		else (t[d].s2+=y)%=MOD;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,op);
	else ins(rs,mid+1,r,x,y,op);
	updata(d);
}

int query(int d,int l,int r,int x,int y,int op)
{
	if (x>y) return 0;
	if (x<=l&&r<=y)
	{
		if (op==1) return t[d].s1;
		else return t[d].s2;
	}
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y,op);
	else if (x>mid) return query(rs,mid+1,r,x,y,op);
	else return (query(ls,l,mid,x,y,op)+query(rs,mid+1,r,x,y,op))%MOD;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	dfs1(1);
	dfs2(1,1);
	int sum=0,inv=ksm(n,MOD-2);
	while (q--)
	{
		int op;scanf("%d",&op);
		if (op==1)
		{
			int x,y;scanf("%d%d",&x,&y);
			(a[x]+=y)%=MOD;
			(sum+=y)%=MOD;
			if (son[x]) ins(1,1,n,pos[x],(LL)size[son[x]]*y%MOD,1);
			ins(1,1,n,pos[x],(LL)(n-size[x])*y%MOD,2);
			int z=top[x];
			while (fa[z]) ins(1,1,n,pos[fa[z]],(LL)(n-size[x])*y%MOD,1),z=top[fa[z]];
		}
		else
		{
			int x;scanf("%d",&x);
			int ans=0;
			if (pos[x]<mx[x]) (ans+=query(1,1,n,pos[x]+1,mx[x],2))%=MOD;
			int z=x;
			while (z) (ans+=query(1,1,n,pos[top[z]],pos[z]-1,1))%=MOD,z=fa[top[z]];
			z=top[x];
			while (fa[z])
			{
				(ans+=query(1,1,n,pos[fa[z]]+1,pos[z]-1,2))%=MOD;
				(ans+=query(1,1,n,mx[z]+1,mx[fa[z]],2))%=MOD;
				(ans+=(LL)a[fa[z]]*size[z]%MOD)%=MOD;
				z=top[fa[z]];
			}
			printf("%d\n",(sum+MOD-(LL)ans*inv%MOD)%MOD);
		}
	}
	return 0;
}