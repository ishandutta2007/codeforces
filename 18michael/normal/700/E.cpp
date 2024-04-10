#include<bits/stdc++.h>
using namespace std;
int n,tot=1,las=1,S_t=0,ans=0;
int rt[400002],dp[400002],to[400002];
char s[200002];
vector<int> vec[400002];
struct aaa
{
	int fa,len;
	int to[26];
}a[400002];
struct SegTree
{
	int lson[16000002],rson[16000002];
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)
		{
			if(!lson[k])lson[k]=(++S_t);
			modify(lson[k],l,mid,x);
		}
		else
		{
			if(!rson[k])rson[k]=(++S_t);
			modify(rson[k],mid+1,r,x);
		}
	}
	inline int merge(int k,int k1,int l,int r)
	{
		if(!k || !k1)return (k|k1);
		if(l==r)return k;
		int mid=((l+r)>>1),k2=(++S_t);
		lson[k2]=merge(lson[k],lson[k1],l,mid),rson[k2]=merge(rson[k],rson[k1],mid+1,r);
		return k2;
	}
	inline int find(int k,int l,int r)
	{
		if(l==r)return l;
		int mid=((l+r)>>1);
		if(lson[k])return find(lson[k],l,mid);
		return find(rson[k],mid+1,r);
	}
	inline bool query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return 0;
		if(l>=l1 && r<=r1)return 1;
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return (query(lson[k],l,mid,l1,mid)|query(rson[k],mid+1,r,mid+1,r1));
	}
}S;
inline void add(int c,int x)
{
	int p=las,np=(++tot),q,nq;
	las=np,a[np].len=a[p].len+1,S.modify(rt[np]=(++S_t),1,n,x);
	while(p && !a[p].to[c])a[p].to[c]=np,p=a[p].fa;
	if(!p)a[np].fa=1;
	else
	{
		q=a[p].to[c];
		if(a[q].len==a[p].len+1)a[np].fa=q;
		else
		{
			a[nq=(++tot)]=a[q],a[nq].len=a[p].len+1,a[np].fa=a[q].fa=nq;
			while(p && a[p].to[c]==q)a[p].to[c]=nq,p=a[p].fa;
		}
	}
}
inline void dfs(int x)
{
	dp[x]=1;
	for(int i=0,v;i<vec[x].size();++i)dfs(v=vec[x][i]),rt[x]=S.merge(rt[x],rt[v],1,n);
}
inline void dfs1(int x)
{
	to[x]=a[x].fa;
	for(int i=0,v;i<vec[x].size();++i)dfs1(v=vec[x][i]),dp[x]=max(dp[x],dp[v]),to[x]=(a[to[x]].len<a[to[v]].len? to[x]:to[v]);
	for(int t;to[x];to[x]=a[to[x]].fa)
	{
		t=S.find(rt[x],1,n);
		if(S.query(rt[to[x]],1,n,t-a[x].len+a[to[x]].len,t-1))break;
	}
	dp[to[x]]=max(dp[to[x]],dp[x]+1);
	if(x^1)ans=max(ans,dp[x]);
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)add(s[i]-'a',i);
	for(int i=2;i<=tot;++i)vec[a[i].fa].push_back(i);
	dfs(1),dfs1(1),printf("%d",ans);
	return 0;
}