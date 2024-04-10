#include<bits/stdc++.h>
#define bs 233
#define LL long long
using namespace std;
int n,q;
int len[100002];
vector<LL> Hs[100002];
char s[100002];
typedef pair<int,int> P;
struct aaa
{
	int mx;
	vector<P> pre,suf;
};
inline int calc(int x,int y,int r)
{
	int l=1,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(Hs[x][mid]==Hs[y][mid])l=mid+1;
		else r=mid-1;
	}
	return r;
}
inline aaa merge(aaa a,aaa b,int l,int mid,int r)
{
	int i=0,j=0,k=calc(mid,mid+1,min(len[mid],len[mid+1]));
	aaa c=(aaa){max(max(a.mx,b.mx),(b.pre[0].second-a.suf[0].second+1)*k),a.pre,b.suf};
	for(;i+1<a.suf.size() && j+1<b.pre.size();)
	{
		if(a.suf[i+1].first>b.pre[j+1].first)k=min(k,a.suf[++i].first);
		else k=min(k,b.pre[++j].first);
		c.mx=max(c.mx,(b.pre[j].second-a.suf[i].second+1)*k);
	}
	for(;i+1<a.suf.size();)k=min(k,a.suf[++i].first),c.mx=max(c.mx,(b.pre[j].second-a.suf[i].second+1)*k);
	for(;j+1<b.pre.size();)k=min(k,b.pre[++j].first),c.mx=max(c.mx,(b.pre[j].second-a.suf[i].second+1)*k);
	for(i=0;i<b.pre.size();++i)
	{
		if((j=calc(l,b.pre[i].second,min(c.pre.back().first,b.pre[i].first)))==c.pre.back().first)c.pre.pop_back();
		c.pre.push_back(P(j,b.pre[i].second));
		if(!j)break;
	}
	for(i=0;i<a.suf.size();++i)
	{
		if((j=calc(r,a.suf[i].second,min(c.suf.back().first,a.suf[i].first)))==c.suf.back().first)c.suf.pop_back();
		c.suf.push_back(P(j,a.suf[i].second));
		if(!j)break;
	}
	return c;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	aaa tmp[400002];
	inline void init(int k,int x)
	{
		tmp[k].mx=len[x],tmp[k].pre.clear(),tmp[k].pre.push_back(P(len[x],x)),tmp[k].suf.clear(),tmp[k].suf.push_back(P(len[x],x));
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)return init(k,l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),tmp[k]=merge(tmp[ls],tmp[rs],l,mid,r);
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return init(k,l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		tmp[k]=merge(tmp[ls],tmp[rs],l,mid,r);
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return tmp[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1),l1,mid,r1);
	}
}S;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1),len[i]=strlen(s+1),Hs[i].clear(),Hs[i].push_back(0);
		for(int j=1;j<=len[i];++j)Hs[i].push_back(Hs[i][j-1]*bs+s[j]);
	}
	S.build(1,1,n);
	for(int o,x,y;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)scanf("%d",&y),printf("%d\n",S.query(1,1,n,x,y).mx);
		else
		{
			scanf("%s",s+1),len[x]=strlen(s+1),Hs[x].clear(),Hs[x].push_back(0);
			for(int i=1;i<=len[x];++i)Hs[x].push_back(Hs[x][i-1]*bs+s[i]);
			S.modify(1,1,n,x);
		}
	}
	return 0;
}