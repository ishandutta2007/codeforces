#include<cstdio>
using namespace std;
#define N 300050
int n,a,b,v[N],l[N],rb,l2[N],rb2;
long long as;
struct node{int l,r,mn,ct,lz;}e[N*4];
void pushup(int x){if(e[x<<1].mn==e[x<<1|1].mn)e[x].mn=e[x<<1].mn,e[x].ct=e[x<<1].ct+e[x<<1|1].ct;else if(e[x<<1].mn<e[x<<1|1].mn)e[x].mn=e[x<<1].mn,e[x].ct=e[x<<1].ct;else e[x].mn=e[x<<1|1].mn,e[x].ct=e[x<<1|1].ct;}
void pushdown(int x){if(e[x].lz)e[x<<1].mn+=e[x].lz,e[x<<1].lz+=e[x].lz,e[x<<1|1].mn+=e[x].lz,e[x<<1|1].lz+=e[x].lz,e[x].lz=0;}
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;e[x].ct=1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int v)
{
	if(e[x].l==l&&e[x].r==r){e[x].lz+=v;e[x].mn+=v;return;}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)modify(x<<1,l,r,v);
	else if(mid<l)modify(x<<1|1,l,r,v);
	else modify(x<<1,l,mid,v),modify(x<<1|1,mid+1,r,v);
	pushup(x);
}
int query(int x,int l,int r)
{
	if(e[x].l==l&&e[x].r==r)return e[x].mn==0?e[x].ct:0;
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query(x<<1,l,r);
	else if(mid<l)return query(x<<1|1,l,r);
	else return query(x<<1,l,mid)+query(x<<1|1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a,&b),v[a]=b;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		l[rb+1]=i;
		while(rb&&v[l[rb]]<v[i])
		{
			int t=l[rb-1]+1,t1=l[rb];
			modify(1,t,t1,v[i]-v[l[rb]]);
			rb--;
		}
		l[++rb]=i;
		l2[rb2+1]=i;
		while(rb2&&v[l2[rb2]]>v[i])
		{
			int t=l2[rb2-1]+1,t1=l2[rb2];
			modify(1,t,t1,v[l2[rb2]]-v[i]);
			rb2--;
		}
		l2[++rb2]=i;
		if(i>1)modify(1,1,i-1,-1);
		as+=query(1,1,i);
	}
	printf("%lld\n",as);
}