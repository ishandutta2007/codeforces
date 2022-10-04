#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005;

int n,a[MAXN];
ll sum[MAXN<<2],rt[MAXN<<2],tag[MAXN<<2];
void build(int id,int l,int r)
{
	if(l==r){sum[id]=rt[id]=tag[id]=a[l];return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	sum[id]=sum[id<<1]+sum[id<<1|1];
	rt[id]=rt[id<<1|1];
}
void maintain(int id,int l,int r,ll c){rt[id]=tag[id]=c;sum[id]=1ll*(r-l+1)*c;}
void pushdown(int id,int l,int r)
{
	if(!tag[id])return;
	int mid=(l+r)>>1;
	maintain(id<<1,l,mid,tag[id]);
	maintain(id<<1|1,mid+1,r,tag[id]);
	tag[id]=0;
}
int find(int id,int l,int r,ll x)
{
	if(rt[id]>x)return n+1;
	if(l==r)return l;
	pushdown(id,l,r);
	int mid=(l+r)>>1;
	int t=find(id<<1,l,mid,x);
	return t<=mid?t:find(id<<1|1,mid+1,r,x);
}
ll qsum(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[id];
	pushdown(id,l,r);
	int mid=(l+r)>>1;
	if(qr<=mid)return qsum(id<<1,l,mid,ql,qr);
	if(ql>mid)return qsum(id<<1|1,mid+1,r,ql,qr);
	return qsum(id<<1,l,mid,ql,mid)+qsum(id<<1|1,mid+1,r,mid+1,qr);
}
void cover(int id,int l,int r,int ql,int qr,ll c)
{
	if(l==ql && r==qr)return maintain(id,l,r,c);
	pushdown(id,l,r);
	int mid=(l+r)>>1;
	if(qr<=mid)cover(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)cover(id<<1|1,mid+1,r,ql,qr,c);
	else cover(id<<1,l,mid,ql,mid,c),cover(id<<1|1,mid+1,r,mid+1,qr,c);
	sum[id]=sum[id<<1]+sum[id<<1|1];
	rt[id]=rt[id<<1|1];
}
int query(int id,int l,int r,ll y)
{
	if(sum[id]<=y)return n+1;
	if(l==r)return l;
	pushdown(id,l,r);
	int mid=(l+r)>>1;
	int t=query(id<<1,l,mid,y);
	return t<=mid?t:query(id<<1|1,mid+1,r,y-sum[id<<1]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,op,x;
	ll y;
	readint(n),readint(Q);
	for(int i=1;i<=n;++i)readint(a[i]);
	build(1,1,n);
	while(Q--)
	{
		readint(op),readint(x),readint(y);
		if(op==1)
		{
			int l=find(1,1,n,y);
			if(l<=x)cover(1,1,n,l,x,y);
		}
		else
		{
			int ans=0;
			chkmax(x,find(1,1,n,y));
			while(x<=n)
			{
				int t=query(1,1,n,y+(x==1?0:qsum(1,1,n,1,x-1)));
				ans+=t-x;
				y-=qsum(1,1,n,x,t-1);
				x=max(find(1,1,n,y),t);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}