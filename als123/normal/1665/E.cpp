#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
const int K=31;
int a[N];
struct qq
{
	int l,r;
	int s1,s2;
	vector<int> mn;
}tr[N*2];int num;
vector<int> Merge (vector<int> a,vector<int> b)
{
	vector<int> c;c.clear();
	int siza=a.size(),sizb=b.size();
	int i=0,j=0;
	while (i<siza&&j<sizb)
	{
		if (a[i]<b[j])	c.push_back(a[i++]);
		else			c.push_back(b[j++]);
		if (c.size()>=K) return c;
	}
	while (i<siza)
	{
		c.push_back(a[i++]);
		if (c.size()>=K) return c;
	}
	while (j<sizb)
	{
		c.push_back(b[j++]);
		if (c.size()>=K) return c;
	}
	return c;
}
void bt (int l,int r)
{
	int now=++num;tr[now].mn.clear();
	tr[now].r=r;tr[now].l=l;
	if (l==r) 	{tr[now].mn.push_back(a[l]);return ;}
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	tr[now].mn=Merge(tr[tr[now].s1].mn,tr[tr[now].s2].mn);
	//printf("%d %d\n",l,r);
}
vector<int> query (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)	return tr[now].mn;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) return query(s1,l,r);
	else if (l>mid) return query(s2,l,r);
	else return Merge(query(s1,l,mid),query(s2,mid+1,r));
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int u=1;u<=n;u++) scanf("%d",&a[u]);
		num=0;bt(1,n);
		int q;
		scanf("%d",&q);
		while (q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			vector<int> c=query(1,l,r);
			int ans=c[0]|c[1];
			for (int i=0;i<c.size();i++)
			for (int j=i+1;j<c.size();j++)
			ans=min(ans,c[i]|c[j]);
			printf("%d\n",ans);
		}
	}
	return 0;
}