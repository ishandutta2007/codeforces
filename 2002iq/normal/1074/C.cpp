#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define point pair<int,int>
#define x first
#define y second
point arr[300005];
int tree[2][1200005];
map<int,int> m;
void update(int node,int st,int en,int idx,int val,int t)
{
	if (st==en)
	tree[t][node]=min(tree[t][node],val);
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val,t);
		else
		update(2*node+1,mid+1,en,idx,val,t);
		tree[t][node]=min(tree[t][2*node],tree[t][2*node+1]);
	}
}
int query(int node,int st,int en,int l,int r,int t)
{
	if (en<l || st>r || r<l)
	return (1<<28);
	if (l<=st && en<=r)
	return tree[t][node];
	int mid=(st+en)/2;
	return min(query(2*node,st,mid,l,r,t),query(2*node+1,mid+1,en,l,r,t));
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].x,&arr[i].y);
		m[arr[i].y];
	}
	sort(arr,arr+n);
	int cur=0;
	for (auto &p:m)
	p.second=cur++;
	for (int i=0;i<1200005;i++)
	{
		tree[0][i]=(1<<28);
		tree[1][i]=(1<<28);
	}
	int mny=(1<<28),mxy=-(1<<28),ans=0;
	for (int i=0;i<n;i++)
	{
		mny=min(mny,arr[i].y);
		mxy=max(mxy,arr[i].y);
		update(1,0,300000,m[arr[i].y],arr[i].x+arr[i].y,0);
		update(1,0,300000,m[arr[i].y],arr[i].x-arr[i].y,1);
		ans=max(ans,max(mxy-arr[i].y,arr[i].y-mny)+arr[i].x-arr[0].x);
		ans=max(ans,arr[i].x+mxy-query(1,0,300000,0,m[arr[i].y],0));
		ans=max(ans,arr[i].x-mny-query(1,0,300000,m[arr[i].y],300000,1));
	}
	printf("%d",2*ans);
	for (int i=3;i<n;i++)
	printf(" %d",2*(mxy-mny+arr[n-1].x-arr[0].x));
}