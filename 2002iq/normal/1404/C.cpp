#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
vector<pair<int,int> > v[300005];
int a[300005],ans[300005],lazy[1200005];
pair<int,int> stree[1200005];
void build(int node,int st,int en)
{
	if (st==en)
	stree[node]={0,st};
	else
	{
		int mid=(st+en)/2;
		build(2*node,st,mid);
		build(2*node+1,mid+1,en);
		stree[node]=min(stree[2*node],stree[2*node+1]);
	}
}
void push(int node,int st,int en)
{
	stree[node].first+=lazy[node];
	if (st!=en)
	{
		lazy[2*node]+=lazy[node];
		lazy[2*node+1]+=lazy[node];
	}
	lazy[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
	if (l<=st && en<=r)
	lazy[node]+=val;
	push(node,st,en);
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r,val);
	update(2*node+1,mid+1,en,l,r,val);
	stree[node]=min(stree[2*node],stree[2*node+1]);
}
pair<int,int> query(int node,int st,int en,int l,int r)
{
	push(node,st,en);
	if (en<l || st>r || r<l)
	return {1e9,0};
	if (l<=st && en<=r)
	return stree[node];
	int mid=(st+en)/2;
	return min(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back({y,i});
	}
	build(1,1,n);
	tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;
	for (int i=n;i>0;i--)
	{
		if (a[i]==i)
		{
			t.insert(i);
			update(1,1,n,i,i,1e9);
			update(1,1,n,i,n,-1);
			while (1)
			{
				auto p=query(1,1,n,i,n);
				if (p.first>0)
				break;
				t.insert(p.second);
				update(1,1,n,p.second,p.second,1e9);
				update(1,1,n,p.second,n,-1);
			}
		}
		if (a[i]<i)
		update(1,1,n,i,i,i-a[i]);
		else
		update(1,1,n,i,i,1e9);
		for (auto p:v[i-1])
		ans[p.second]=t.order_of_key(n-p.first+1);
	}
	for (int i=0;i<q;i++)
	printf("%d\n",ans[i]);
}