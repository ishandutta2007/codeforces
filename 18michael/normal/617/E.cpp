#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
int n,m,k,bl;LL res=0;
int a[100002]={},cnt[2000002]={1},id[100002],block[100002];
LL ans[100002];
struct aaa
{
	int l,r;
}qry[100002];
inline bool cmp(int a,int b)
{
	return block[qry[a].l]==block[qry[b].l]? ((block[qry[a].l]&1)? (qry[a].r<qry[b].r):(qry[a].r>qry[b].r)):(block[qry[a].l]<block[qry[b].l]);
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),bl=max(1,n/sqrt(m));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]^=a[i-1],block[i]=(i-1)/bl;
	for(int i=1;i<=m;++i)scanf("%d%d",&qry[i].l,&qry[i].r),--qry[i].l,id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1,l=0,r=0;i<=m;++i)
	{
		while(r<qry[id[i]].r)++r,res+=cnt[a[r]^k],++cnt[a[r]];
		while(l>qry[id[i]].l)--l,res+=cnt[a[l]^k],++cnt[a[l]];
		while(r>qry[id[i]].r)--cnt[a[r]],res-=cnt[a[r]^k],--r;
		while(l<qry[id[i]].l)--cnt[a[l]],res-=cnt[a[l]^k],++l;
		ans[id[i]]=res;
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}