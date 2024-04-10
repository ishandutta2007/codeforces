#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,L,R,l=0,r=1000000000,mid,col_t,head,tail;
int col[100002],siz[100002],mx[100002],tot[100002],G[100002],st[100002];
vector<int> vec1[100002];
typedef pair<int,int> P;
P ans;
P tmp[100002],tmp1[100002];
vector<P> vec[100002];
inline bool cmp(P a,P b)
{
	return siz[a.first]<siz[b.first];
}
inline void add_edge(int x,int y,int z)
{
	vec[x].push_back(P(y,z)),vec[y].push_back(P(x,z));
}
inline void dfs(int x,int f)
{
	siz[x]=1,mx[x]=0;
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i].first)!=f && col[v]==col[x])dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],tot[col[x]]-siz[x]))<mx[G[col[x]]])G[col[x]]=x;
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i].first)!=f && col[v]==col[x])dfs1(v,x);
}
inline void dfs2(int x,int f,int d,int z)
{
	if(z>tmp1[d].first)tmp1[d]=P(z,x);
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i].first)!=f && col[v]==col[x])dfs2(v,x,d+1,z+(vec[x][i].second>=mid? 1:-1));
}
inline void dfs3(int x,int f,int c,int c1)
{
	col[x]=c1;
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i].first)!=f && col[v]==c)dfs3(v,x,c,c1);
}
inline bool solve(int x,int c)
{
	if(!G[c])
	{
		dfs(x,0),tot[c]=siz[x],dfs1(G[c]=x,0),dfs(G[c],0),sort(vec[G[c]].begin(),vec[G[c]].end(),cmp);
		for(int i=0;i<vec[G[c]].size();++i)vec1[c].push_back(siz[vec[G[c]][i].first]);
	}
	tmp[0]=P(0,G[c]);
	for(int i=1;i<=tot[c];++i)tmp[i].first=-inf;
	for(int i=0,v;i<vec[G[c]].size();++i)
		if(col[v=vec[G[c]][i].first]==c)
		{
			for(int j=0;j<=vec1[c][i];++j)tmp1[j].first=-inf;
			dfs2(v,G[c],1,vec[G[c]][i].second>=mid? 1:-1),head=1,tail=0;
			for(int j=0,k=min(R,vec1[c][i]);j<=vec1[c][i];++j)
			{
				for(;k>=max(L-j,0);--k)
				{
					for(;head<=tail && tmp[k].first>=tmp[st[tail]].first;--tail);
					st[++tail]=k;
				}
				for(;head<=tail && st[head]>R-j;++head);
				if(head<=tail && tmp[st[head]].first+tmp1[j].first>=0)
				{
					ans=P(tmp[st[head]].second,tmp1[j].second);
					return 1;
				}
			}
			for(int j=0;j<=vec1[c][i];++j)tmp[j]=max(tmp[j],tmp1[j]);
		}
	for(int i=0,v;i<vec[G[c]].size();++i)if(col[v=vec[G[c]][i].first]==c && (dfs3(v,G[c],c,++col_t),solve(v,col_t)))return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	for(;l<=r;)
	{
		mid=((l+r)>>1),col_t=0;
		for(int i=1;i<=n;++i)col[i]=0;
		if(solve(1,0))l=mid+1;
		else r=mid-1;
	}
	return 0&printf("%d %d",ans.first,ans.second);
}