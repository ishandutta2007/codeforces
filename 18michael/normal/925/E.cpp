#include<bits/stdc++.h>
#define Mx 16
#define inf 0x3f3f3f3f
using namespace std;
int n,n2,m,sq,dfn_t=0,edge_t=0,st_t,ans=0;
int t[100002],q[100002],la[100002],dfn[100002],dep[100002],id[100002],st[100002],num[100002],vec2_t[100002],Fa[100002],laz[100002];
bool col[100002];
int fa[100002][18];
vector<int> vec[200002];
typedef pair<int,int> P;
vector<P> vec2[100002];
struct aaa
{
	int to,nx;
}edge[200002];
inline bool cmp(int x,int y)
{
	return dfn[q[x]]<dfn[q[y]]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	if(!num[x])num[x]=x;
	if(!num[y])num[y]=y;
	Fa[y]=x;
}
inline void dfs(int x,int f)
{
	dfn[x]=(++dfn_t),dep[x]=dep[f]+1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m),sq=1200,n2=(n<<1);
	for(int i=2;i<=n;++i)scanf("%d",&fa[i][0]),add_edge(fa[i][0],i);
	for(int i=1;i<=Mx;++i)for(int j=1;j<=n;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs(1,0);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]),t[i]+=n;
	for(int i=1;i<=m;++i)scanf("%d",&q[i]),q[i]=abs(q[i]),id[i]=i;
	for(int i=1,ed;i<=m;i+=sq)
	{
		ed=min(i+sq-1,m),sort(id+i,id+ed+1,cmp),st[st_t=1]=1;
		for(int j=1;j<=n;++j)num[j]=laz[j]=0,vec2[j].clear();
		for(int j=0;j<=n2;++j)vec[j].clear();
		for(int j=i,x;j<=ed;++j)
		{
			if(q[id[j]]==st[st_t])continue;
			for(x=LCA(q[id[j]],st[st_t]);st_t>1 && dep[st[st_t-1]]>=dep[x];--st_t)add_e(st[st_t-1],st[st_t]);
			if(x!=st[st_t])add_e(x,st[st_t]),st[st_t]=x;
			st[++st_t]=q[id[j]];
		}
		for(int j=1;j<st_t;++j)add_e(st[j],st[j+1]);
		for(int j=1,k;j<=n;++j)if(num[j]==j)for(k=fa[j][0];k && !num[k];k=fa[k][0])num[k]=j;
		for(int j=1;j<=n;++j)if(num[j] && num[j]!=j && !col[j])vec[t[j]].push_back(j);
		for(int j=0;j<=n2;++j)
			for(int k=0;k<vec[j].size();++k)
			{
				if(vec2[num[vec[j][k]]].size() && vec2[num[vec[j][k]]].back().first==j)++vec2[num[vec[j][k]]].back().second;
				else vec2[num[vec[j][k]]].push_back(P(j,1));
			}
		for(int j=1;j<=n;++j)for(vec2_t[j]=0;vec2_t[j]<vec2[j].size() && vec2[j][vec2_t[j]].first<n;++vec2_t[j]);
		for(int j=i,o;j<=ed;++j)
		{
			o=(col[q[j]]? 1:-1);
			for(int k=q[j];k;k=Fa[k])
			{
				for(ans-=(!col[k] && t[k]<n),t[k]+=o,ans+=(!col[k] && t[k]<n),laz[k]+=o;vec2_t[k]<vec2[k].size() && vec2[k][vec2_t[k]].first+laz[k]<n;ans+=vec2[k][vec2_t[k]].second,++vec2_t[k]);
				for(;vec2_t[k]>0 && vec2[k][vec2_t[k]-1].first+laz[k]>=n;ans-=vec2[k][--vec2_t[k]].second);
			}
			ans-=(!col[q[j]] && t[q[j]]<n),col[q[j]]^=1,ans+=(!col[q[j]] && t[q[j]]<n),printf("%d ",ans);
		}
		for(int j=1;j<=n;++j)if(num[j]==j)for(int k=fa[j][0];k && num[k]!=k;k=fa[k][0])t[k]+=laz[j];
	}
	return 0;
}