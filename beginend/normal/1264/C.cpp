#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=200005;
const int MOD=998244353;

int n,q,ny[105],inv[N],p[N],pre[N],w[N];
bool vis[N];
struct tree{int sw,cw;}t[N*4];
std::set<int> se;
std::set<int>::iterator it;

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

void update(int d,int len)
{
	t[d].sw=(t[ls].sw+t[rs].sw)%MOD;
	t[d].cw=(t[ls].cw+t[rs].cw)%MOD;
	(t[d].cw+=(LL)len*t[rs].sw%MOD)%=MOD;
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].sw=t[d].cw=w[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	update(d,mid-l+1);
}

pi query(int d,int l,int r,int x,int y)
{
	if (x==l&&r==y) return mp(t[d].cw,t[d].sw);
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else
	{
		pi w1=query(ls,l,mid,x,mid),w2=query(rs,mid+1,r,mid+1,y),ans;
		ans.first=((LL)w1.first+(LL)w2.first+(LL)w2.second*(mid-x+1))%MOD;
		ans.second=(w1.second+w2.second)%MOD;
		return ans;
	}
}

int query(int l,int r)
{
	int ans=(LL)query(1,1,n,l,r).first*inv[l-1]%MOD,pp=(LL)pre[r]*inv[l-1]%MOD;
	(ans+=(LL)(r-l+1)*pp%MOD)%=MOD;
	ans=(LL)ans*ksm(pp,MOD-2)%MOD;
	return ans;
}

int main()
{
	ny[0]=ny[1]=1;
	for (int i=2;i<=100;i++) ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	scanf("%d%d",&n,&q);
	pre[0]=inv[0]=1;
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]),inv[i]=(LL)100*ny[p[i]]%MOD,p[i]=(LL)p[i]*ny[100]%MOD;
	for (int i=1;i<=n;i++) pre[i]=(LL)pre[i-1]*p[i]%MOD,inv[i]=(LL)inv[i-1]*inv[i]%MOD;
	for (int i=1;i<=n;i++) w[i]=(LL)(1+MOD-p[i])*pre[i-1]%MOD;
	build(1,1,n);
	int ans=query(1,n);
	se.insert(1);se.insert(n+1);
	while (q--)
	{
		int x;scanf("%d",&x);
		if (vis[x])
		{
			it=se.upper_bound(x);
			int x2=(*it);
			(ans+=MOD-query(x,x2-1))%=MOD;
			it=se.lower_bound(x);
			it--;
			int x1=(*it);
			(ans+=MOD-query(x1,x-1))%=MOD;
			(ans+=query(x1,x2-1))%=MOD;
			se.erase(x);
			vis[x]=0;
		}
		else
		{
			it=se.lower_bound(x);
			int x2=(*it);
			(ans+=query(x,x2-1))%=MOD;
			it--;
			int x1=(*it);
			(ans+=query(x1,x-1))%=MOD;
			(ans+=MOD-query(x1,x2-1))%=MOD;
			se.insert(x);
			vis[x]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}