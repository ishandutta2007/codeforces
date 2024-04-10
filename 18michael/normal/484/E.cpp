#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,l,r,w,t=0,rt_t;
int a[100002],id[100002],rt[100002];
struct aaa
{
	int lson,rson,l,r,mx,len;
}arr[3200002]={};
struct bbb
{
	int l,r,mx,len;
};
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline int build(int l,int r)
{
	if(l==r){arr[++t]=(aaa){0,0,1,1,1,1};return t;}
	int mid=((l+r)>>1),k=(++t),ls=build(l,mid),rs=build(mid+1,r);
	arr[k].lson=ls,arr[k].rson=rs,arr[k].len=r-l+1;
	if(arr[ls].l==arr[ls].len)arr[k].l=arr[ls].l+arr[rs].l;else arr[k].l=arr[ls].l;
	if(arr[rs].r==arr[rs].len)arr[k].r=arr[rs].r+arr[ls].r;else arr[k].r=arr[rs].r;
	arr[k].mx=max(max(arr[ls].mx,arr[rs].mx),arr[ls].r+arr[rs].l);return k;
}
inline int modify(int now,int l,int r,int x)
{
	if(l==r){arr[++t]=(aaa){0,0,0,0,0,1};return t;}
	int mid=((l+r)>>1),k=(++t),ls,rs;
	if(x<=mid)ls=modify(arr[now].lson,l,mid,x),rs=arr[now].rson;
	else ls=arr[now].lson,rs=modify(arr[now].rson,mid+1,r,x);
	arr[k].lson=ls,arr[k].rson=rs,arr[k].len=r-l+1;
	if(arr[ls].l==arr[ls].len)arr[k].l=arr[ls].l+arr[rs].l;else arr[k].l=arr[ls].l;
	if(arr[rs].r==arr[rs].len)arr[k].r=arr[rs].r+arr[ls].r;else arr[k].r=arr[rs].r;
	arr[k].mx=max(max(arr[ls].mx,arr[rs].mx),arr[ls].r+arr[rs].l);return k;
}
inline bbb query(int now,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return (bbb){arr[now].l,arr[now].r,arr[now].mx,r-l+1};
	int mid=((l+r)>>1),ls=arr[now].lson,rs=arr[now].rson;
	if(r1<=mid)return query(ls,l,mid,l1,r1);
	if(l1>mid)return query(rs,mid+1,r,l1,r1);
	bbb le=query(ls,l,mid,l1,mid),ri=query(rs,mid+1,r,mid+1,r1),ans;
	if(le.l==le.len)ans.l=le.l+ri.l;else ans.l=le.l;
	if(ri.r==ri.len)ans.r=ri.r+le.r;else ans.r=ri.r;
	ans.mx=max(max(le.mx,ri.mx),le.r+ri.l),ans.len=r1-l1+1;
	return ans;
}
inline int binary_search()
{
	int le=1,ri=n,mid;
	while(le<=ri)
	{
		mid=((le+ri)>>1);
		if(query(rt[mid],1,n,l,r).mx>=w)le=mid+1;
		else ri=mid-1;
	}
	return ri;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i;
	rt[rt_t=1]=build(1,n),sort(id+1,id+n+1,cmp);
	for(int i=1;i<n;++i)rt[rt_t+1]=modify(rt[rt_t],1,n,id[i]),++rt_t;
	scanf("%d",&m);
	while(m--)scanf("%d%d%d",&l,&r,&w),printf("%d\n",a[id[binary_search()]]);
	return 0;
}