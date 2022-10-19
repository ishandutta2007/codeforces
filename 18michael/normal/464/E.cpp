#include<bits/stdc++.h>
#define Mx 100020
#define Mx1 24000000
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,edge_t=0,s,t,S_t=0;
int la[100002],rt[100002],from[100002];
LL pw[100022],pre[100022];
vector<int> vec;
struct aaa
{
	int to,nx,val;
}edge[200002];
struct SegTree
{
	int lson[Mx1+2],rson[Mx1+2],mn[Mx1+2];
	LL Hs[Mx1+2];
	inline int modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return k;
		int k1=(++S_t),mid=((l+r)>>1);
		if(l>=l1 && r<=r1)return d? (Hs[k1]=(pre[r]-(l? pre[l-1]:0)+mod)%mod,mn[k1]=1,k1):(--S_t,0);
		lson[k1]=lson[k],rson[k1]=rson[k];
		if(l1<=mid)lson[k1]=modify(lson[k],l,mid,l1,r1,d);
		if(r1>mid)rson[k1]=modify(rson[k],mid+1,r,l1,r1,d);
		return Hs[k1]=(Hs[lson[k1]]+Hs[rson[k1]])%mod,mn[k1]=min(mn[lson[k1]],mn[rson[k1]]),k1;
	}
	inline int find(int k,int l,int r,int x)
	{
		if(l==r)return Hs[k]? Mx+1:l;
		int mid=((l+r)>>1),res=Mx+1;
		if(x<=mid && !mn[lson[k]])res=find(lson[k],l,mid,x);
		if(res>Mx)res=find(rson[k],mid+1,r,x);
		return res;
	}
	inline void add(int &k,int x)
	{
		int t=find(k,0,Mx,x);
		k=modify(k=modify(k,0,Mx,x,t-1,0),0,Mx,t,t,1);
	}
	inline bool cmp(int k,int k1,int l,int r)
	{
		if(l==r)return Hs[k]<Hs[k1];
		int mid=((l+r)>>1);
		if(Hs[rson[k]]^Hs[rson[k1]])return cmp(rson[k],rson[k1],mid+1,r);
		return cmp(lson[k],lson[k1],l,mid);
	}
}S;
typedef pair<int,int> P;
P p;
struct cmp
{
	inline bool operator () (P a,P b) const
	{
		return S.cmp(b.second,a.second,0,Mx);
	}
};
priority_queue<P,vector<P>,cmp> pq;
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
int main()
{
	scanf("%d%d",&n,&m),pw[0]=pre[0]=1;
	for(int i=1;i<=Mx;++i)pre[i]=(pre[i-1]+(pw[i]=(pw[i-1]<<1)%mod))%mod;
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	S.add(rt[0]=0,Mx-1);
	for(int i=1;i<=n;++i)rt[i]=rt[0];
	scanf("%d%d",&s,&t),pq.push(P(s,rt[s]=(++S_t)));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(rt[p.first]^p.second)continue;
		for(int i=la[p.first],v,x;i;i=edge[i].nx)
		{
			S.add(x=rt[p.first],edge[i].val);
			if(S.cmp(x,rt[v=edge[i].to],0,Mx))pq.push(P(v,rt[v]=x)),from[v]=p.first;
		}
	}
	if(!S.cmp(rt[t],rt[0],0,Mx))puts("-1");
	else
	{
		printf("%lld\n",S.Hs[rt[t]]);
		while(t^s)vec.push_back(t),t=from[t];
		vec.push_back(s),printf("%d\n",vec.size());
		while(!vec.empty())printf("%d ",vec.back()),vec.pop_back();
	}
	return 0;
}