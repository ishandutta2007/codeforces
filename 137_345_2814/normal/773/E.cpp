#include<cstdio>
#include<algorithm>
using namespace std;
#define N 500050
int n,v[N],t[N],tr[N],ct[N*2];
inline void ad(int x){for(int i=x;i<=n;i+=i&-i)tr[i]++;}
inline int qu(int x){int as=0;for(int i=x;i;i-=i&-i)as+=tr[i];return as;}
inline int Min(int a,int b){return a<b?a:b;}
struct node{int l,r,l1,l2,mn,mx;}e[N*4];
inline void pushdown(int x){if(e[x].l1)e[x<<1].l1+=e[x].l1,e[x<<1].mn+=e[x].l1,e[x<<1|1].l1+=e[x].l1,e[x<<1|1].mn+=e[x].l1,e[x].l1=0;if(e[x].l2)e[x<<1].mx+=e[x].l2,e[x<<1].l2+=e[x].l2,e[x<<1|1].mx+=e[x].l2,e[x<<1|1].l2+=e[x].l2,e[x].l2=0;}
inline void pushup(int x){e[x].mx=Min(e[x<<1].mx,e[x<<1|1].mx);e[x].mn=Min(e[x<<1].mn,e[x<<1|1].mn);}
void build(int x,int l,int r){e[x].l=l;e[x].r=r;e[x].mn=e[x].mx=998244353;if(l==r)return;int mid=(l+r)>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);}
void modify(int x,int a,int p)
{
	if(e[x].l==e[x].r){e[x].mn=p+e[x].l1;e[x].mx=p+e[x].l2;return;}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=a)modify(x<<1,a,p);
	else modify(x<<1|1,a,p);
	pushup(x);
}
int que1(int x)
{
	if(e[x].l==e[x].r)return e[x].mx>0?e[x].l-1:e[x].l;
	pushdown(x);
	if(e[x<<1|1].mx>0)return que1(x<<1);
	else return que1(x<<1|1);
}
int que2(int x,int l,int r)
{
	if(l>r)return 998244353;
	if(e[x].l==l&&r==e[x].r)return e[x].mn;
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return que2(x<<1,l,r);
	else if(mid<l)return que2(x<<1|1,l,r);
	else return Min(que2(x<<1,l,mid),que2(x<<1|1,mid+1,r));
}
void add2(int x,int l,int r)
{
	if(e[x].l==l&&e[x].r==r){e[x].mx++;e[x].l2++;return;}
	int mid=(e[x].l+e[x].r)>>1;
	pushdown(x);
	if(mid>=r)add2(x<<1,l,r);
	else if(mid<l)add2(x<<1|1,l,r);
	else add2(x<<1,l,mid),add2(x<<1|1,mid+1,r);
	pushup(x);
}
void add1(int x,int l,int r)
{
	if(e[x].l==l&&e[x].r==r){e[x].mn++;e[x].l1++;return;}
	int mid=(e[x].l+e[x].r)>>1;
	pushdown(x);
	if(mid>=r)add1(x<<1,l,r);
	else if(mid<l)add1(x<<1|1,l,r);
	else add1(x<<1,l,mid),add1(x<<1|1,mid+1,r);
	pushup(x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),ct[v[i]+500000]++;
	for(int i=1;i<=1e6;i++)ct[i]+=ct[i-1];
	for(int i=1;i<=n;i++)t[i]=ct[v[i]+500000]--;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		modify(1,t[i],v[i]);
		add2(1,t[i],n);
		if(t[i]>1)add1(1,1,t[i]-1);
		ad(t[i]);
		int tp=que1(1);
		printf("%d\n",Min(que2(1,tp+1,n),i-qu(tp)*2));
	}
}