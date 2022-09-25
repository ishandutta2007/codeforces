#include<cstdio>
#include<algorithm>
using namespace std;
#define N 500500
#define ll long long
int n,k,v[3][N],st[N][3],id[N];
ll s[3][N],sl[N],sr[N],su,as=-1e18;
bool cmp(int a,int b){return st[a][1]<st[b][1];}
struct seg1{
	struct node{int l,r;ll mx;}e[N*4];
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;
		if(l==r){e[x].mx=sl[l];return;}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		e[x].mx=max(e[x<<1].mx,e[x<<1|1].mx);
	}
	void modify(int x,int l)
	{
		if(e[x].l==e[x].r){e[x].mx=sl[l];return;}
		int mid=(e[x].l+e[x].r)>>1;
		modify(x<<1|(mid<l),l);
		e[x].mx=max(e[x<<1].mx,e[x<<1|1].mx);
	}
	ll query(int x,int l,int r)
	{
		if(e[x].l==l&&e[x].r==r)return e[x].mx;
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return query(x<<1,l,r);
		else if(mid<l)return query(x<<1|1,l,r);
		else return max(query(x<<1,l,mid),query(x<<1|1,mid+1,r));
	}
}t1;
struct sth{ll ls,rs,as;};
sth operator +(sth a,sth b)
{
	sth as;
	as.ls=max(a.ls,b.ls);
	as.rs=max(a.rs,b.rs);
	as.as=max(max(a.as,b.as),a.ls+b.rs);
	return as;
}
struct seg2{
	struct node{int l,r;sth mx;}e[N*4];
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;
		if(l==r){e[x].mx=(sth){sl[l],sr[l],sl[l]+sr[l]};return;}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		e[x].mx=e[x<<1].mx+e[x<<1|1].mx;
	}
	sth query(int x,int l,int r)
	{
		if(e[x].l==l&&e[x].r==r)return e[x].mx;
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return query(x<<1,l,r);
		else if(mid<l)return query(x<<1|1,l,r);
		else return query(x<<1,l,mid)+query(x<<1|1,mid+1,r);
	}
}t2;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%d",&v[i][j]),s[i][j]=s[i][j-1]+v[i][j];
	su=s[1][n];
	for(int i=1;i<=n;i++)
	{
		sl[i]=s[0][i]-s[1][i-1];
		sr[i]=s[2][n]-s[2][i-1]-s[1][n]+s[1][i];
	}
	for(int i=1;i<=k;i++)scanf("%d%d%d",&st[i][0],&st[i][1],&st[i][2]),id[i]=i;
	sort(id+1,id+k+1,cmp);
	t1.build(1,1,n);
	for(int i=1;i<=k;i++)
	{
		int u=id[i];
		ll tp=t1.query(1,st[u][0],st[u][1])-st[u][2];
		sl[st[u][1]+1]=max(sl[st[u][1]+1],tp);
		if(st[u][1]+1<=n)t1.modify(1,st[u][1]+1);
	}
	t2.build(1,1,n);
	for(int i=1;i<=k;i++)
	{
		sth ls=t2.query(1,st[i][0],st[i][1]);
		as=max(as,ls.as-st[i][2]);
	}
	printf("%lld\n",as+su);
}