#include<cstdio>
#include<vector>
using namespace std;
int n,n1,dfn_t,ans,Test_num;
int dfn[300002],siz[300002];
vector<int> sona[300002],sonb[300002];
struct aaa
{
	int val,laz;
}arr[1200002];
inline void dfs(int x,int f)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=0,v;i<sonb[x].size();++i)
		if((v=sonb[x][i])!=f)
			dfs(v,x),siz[x]+=siz[v];
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void modify(int k,int l,int r,int l1,int r1,int d)
{
	if(l>=l1 && r<=r1){arr[k].laz+=d;return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	arr[ls].laz+=arr[k].laz,arr[rs].laz+=arr[k].laz,arr[k].val+=arr[k].laz*(r-l+1)+d*(r1-l1+1),arr[k].laz=0;
	if(r1<=mid)modify(ls,l,mid,l1,r1,d);
	else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
	else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
}
inline int query(int k,int l,int r,int x)
{
	if(l==r)return arr[k].val+arr[k].laz;
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	arr[ls].laz+=arr[k].laz,arr[rs].laz+=arr[k].laz,arr[k].val+=arr[k].laz*(r-l+1),arr[k].laz=0;
	if(x<=mid)return query(ls,l,mid,x);
	return query(rs,mid+1,r,x);
}
inline void dfs1(int x,int f,int res)
{
	int t=query(1,1,n,dfn[x]);
	if(t)modify(1,1,n,dfn[t],dfn[t]+siz[t]-1,-t),--res;
	modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,x),ans=max(ans,++res);
	for(int i=0,v;i<sona[x].size();++i)
		if((v=sona[x][i])!=f)
			dfs1(v,x,res);
	modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,-x);
	if(t)modify(1,1,n,dfn[t],dfn[t]+siz[t]-1,t);
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n),n1=(n<<2),dfn_t=ans=0;
		for(int i=1;i<=n1;++i)arr[i].val=arr[i].laz=0;
		for(int i=1;i<=n;++i)sona[i].clear(),sonb[i].clear();
		for(int i=2,x;i<=n;++i)scanf("%d",&x),sona[x].push_back(i);
		for(int i=2,x;i<=n;++i)scanf("%d",&x),sonb[x].push_back(i);
		dfs(1,0),dfs1(1,0,0),printf("%d\n",ans);
	}
	return 0;
}