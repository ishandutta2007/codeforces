#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans[N],v[N],sum[N<<2];
struct st{int v,p;}a[N];
struct qr{int k,p,i;}q[N];
bool cmp1(st a,st b){return a.v>b.v||(a.v==b.v&&a.p<b.p);}
bool cmp2(qr a,qr b){return a.k<b.k;}
void up(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
void upd(int x,int l,int r,int p)
{
	sum[x]++;if(l==r)return;int mid=l+r>>1;
	if(p<=mid)upd(x<<1,l,mid,p);else upd(x<<1|1,mid+1,r,p);
}
int qry(int x,int l,int r,int p)
{
	if(l==r)return v[l];int mid=l+r>>1;
	return p<=sum[x<<1]?qry(x<<1,l,mid,p):qry(x<<1|1,mid+1,r,p-sum[x<<1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&v[i]);a[i].v=v[i];a[i].p=i;}
	sort(a+1,a+n+1,cmp1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].k,&q[i].p),q[i].i=i;
	sort(q+1,q+m+1,cmp2);
	for(int i=1,x=0;i<=m;i++)
	{
		while(x<q[i].k){x++;upd(1,1,n,a[x].p);}
		ans[q[i].i]=qry(1,1,n,q[i].p);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}