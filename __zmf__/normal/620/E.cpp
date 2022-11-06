//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+9;
#define int long long
#define mid ((l+r)>>1)
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi,opt,k,L,R,u,ll[N],rr[N];
int tree[N<<2],tag[N<<2],pown[69],a[N];
inline int lc(int x){return x<<1;}
inline int rc(int x){return x<<1|1;}
inline void push_up(int x)
{
	tree[x]=tree[lc(x)]|tree[rc(x)];return ;
}
inline void push_down(int x)
{
	if(!tag[x])return ;
	tag[lc(x)]=tag[rc(x)]=tag[x];
	tree[lc(x)]=tree[rc(x)]=tag[x];
	tag[x]=0;
}
inline void build(int l,int r,int p)
{
	if(l==r)
	{
		tree[p]=a[l];return ;
	}
	build(l,mid,lc(p));
	build(mid+1,r,rc(p));
	push_up(p);
}
inline void update(int l,int r,int p)
{
	if(L<=l&&r<=R)
	{
		tree[p]=tag[p]=k;return ;
	}
	push_down(p);
	if(mid>=L)update(l,mid,lc(p));
	if(mid<R)update(mid+1,r,rc(p));
	push_up(p);
}
inline int query(int l,int r,int p)
{
	int res=0;
	if(L<=l&&r<=R)return tree[p];
	push_down(p);
	if(mid>=L)res|=query(l,mid,lc(p));
	if(mid<R)res|=query(mid+1,r,rc(p));
	push_up(p);
	return res;
}
inline int cntans(int x)
{
	int ans=0;
	for(int i=0;i<=60;i++)
		if((x&pown[i])!=0)ans++;
	return ans;
}
int x,y,id[N],tim,c[N];
vector<int> G[N];
inline void dfs(int u,int fa)
{
	id[u]=++tim;ll[u]=rr[u]=id[u];
	a[id[u]]=pown[c[u]];
	for(int i=0;i<G[u].size();i++)
		if(G[u][i]!=fa)
		{
			dfs(G[u][i],u);rr[u]=max(rr[u],rr[G[u][i]]);
		}
}
signed main()
{
	n=read(),taxi=read();
	pown[0]=1;
	for(int i=1;i<=60;i++)pown[i]=pown[i-1]*2;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();G[x].push_back(y),G[y].push_back(x);
	}dfs(1,0);
	//for(int i=1;i<=n;i++)cout<<id[i]<<" "<<ll[i]<<" "<<rr[i]<<endl;
	build(1,n,1);
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		opt=read();u=read();
		L=ll[u],R=rr[u];
		if(opt==1)
		{
			k=read();k=pown[k];update(1,n,1);
		}
		else
		{
			printf("%d\n",cntans(query(1,n,1)));
		}
		//cout<<opt<<" "<<L<<" "<<R<<"------"<<endl;
	}
	return 0;
}