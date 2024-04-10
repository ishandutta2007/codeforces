#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e5+5;
int n,a[N],p[N];
long long ans;
struct T{int lzy,mn1,nm1,mn2,nm2;}t[N<<2];
inline void pushup(int u)
{
	t[u].mn1=t[u<<1].mn1;t[u].nm1=t[u<<1].nm1;
	t[u].mn2=t[u<<1].mn2;t[u].nm2=t[u<<1].nm2;
	if(t[u<<1|1].mn1<t[u].mn1)t[u].mn2=t[u].mn1,t[u].nm2=t[u].nm1,t[u].mn1=t[u<<1|1].mn1,t[u].nm1=t[u<<1|1].nm1;
	else if(t[u<<1|1].mn1==t[u].mn1)t[u].nm1+=t[u<<1|1].nm1;
	else if(t[u<<1|1].mn1<t[u].mn2)t[u].mn2=t[u<<1|1].mn1,t[u].nm2=t[u<<1|1].nm1;
	else if(t[u<<1|1].mn1==t[u].mn2)t[u].nm2+=t[u<<1|1].nm1;
	if(t[u<<1|1].mn2<t[u].mn1)t[u].mn2=t[u].mn1,t[u].nm2=t[u].nm1,t[u].mn1=t[u<<1|1].mn2,t[u].nm1=t[u<<1|1].nm2;
	else if(t[u<<1|1].mn2==t[u].mn1)t[u].nm1+=t[u<<1|1].nm2;
	else if(t[u<<1|1].mn2<t[u].mn2)t[u].mn2=t[u<<1|1].mn2,t[u].nm2=t[u<<1|1].nm2;
	else if(t[u<<1|1].mn2==t[u].mn2)t[u].nm2+=t[u<<1|1].nm2;
}
inline void pushdown(int u)
{
	t[u<<1].lzy+=t[u].lzy;t[u<<1|1].lzy+=t[u].lzy;
	t[u<<1].mn1+=t[u].lzy;t[u<<1|1].mn1+=t[u].lzy;
	t[u<<1].mn2+=t[u].lzy;t[u<<1|1].mn2+=t[u].lzy;
	t[u].lzy=0;
}
void build(int u,int l,int r)
{
	t[u].mn1=0;t[u].nm1=r-l+1;t[u].mn2=1e9;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}
void modify(int u,int l,int r,int left,int right,int v)
{
	if(left<=l&&right>=r){t[u].mn1+=v;t[u].mn2+=v;t[u].lzy+=v;return;}
	int mid=(l+r)>>1;pushdown(u);
	if(left<=mid)modify(u<<1,l,mid,left,right,v);
	if(right>mid)modify(u<<1|1,mid+1,r,left,right,v);
	pushup(u);
}
int query(int u,int l,int r,int left,int right)
{
	if(left<=l&&right>=r)return (t[u].mn1<=2?t[u].nm1:0)+(t[u].mn2==2?t[u].nm2:0);
	int mid=(l+r)>>1;pushdown(u);
	if(right<=mid)return query(u<<1,l,mid,left,right);
	if(left>mid)return query(u<<1|1,mid+1,r,left,right);
	return query(u<<1,l,mid,left,right)+query(u<<1|1,mid+1,r,left,right);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),a[p[i]]=i;
	build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		int x=p[a[i]-1],y=p[a[i]+1];
		if(x>y)swap(x,y);
		if(x>i)modify(1,1,n,i,x-1,1),modify(1,1,n,y,n,-1);
		else if(y>i)modify(1,1,n,i,y-1,1);
		else modify(1,1,n,i,n,1);
		ans+=query(1,1,n,i,n)-1;
	}
	printf("%I64d\n",ans);
	return 0;
}