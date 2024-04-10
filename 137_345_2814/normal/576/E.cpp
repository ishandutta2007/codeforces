#include<cstdio>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define N 500500
#define K 52
int fa[K][N],vl[K][N],sz[K][N],n,m,k,q,f[N][2],cl[N],las[N],as[N],a,b,nt[N];
struct modify{int a,b,c,l,r;}s1[N];
struct modify2{int a,b,l,r;};
vector<modify2> s[22][2],t[22];
struct sth{int a,b;};
stack<sth> t1[22];
void cdq(int l,int r,int v,int dep)
{
	int sz1=s[dep][v].size();
	for(int i=0;i<sz1;i++)
	{
		modify2 tp=s[dep][v][i];
		if(tp.l>l||tp.r<r)continue;
		int cl=tp.b,l1=f[tp.a][0],r1=f[tp.a][1],sb=1;
		while(fa[cl][l1]!=l1)sb^=vl[cl][l1],l1=fa[cl][l1];
		while(fa[cl][r1]!=r1)sb^=vl[cl][r1],r1=fa[cl][r1];
		if(sz[cl][l1]<sz[cl][r1])l1^=r1^=l1^=r1;
		if(l1==r1)continue;
		t1[dep].push((sth){cl,r1});
		fa[cl][r1]=l1,sz[cl][l1]+=sz[cl][r1],vl[cl][r1]=sb;
	}
	if(l==r)
	{
		int cl=s1[l].c,l1=f[s1[l].a][0],r1=f[s1[l].a][1],sb=0;
		while(fa[cl][l1]!=l1)sb^=vl[cl][l1],l1=fa[cl][l1];
		while(fa[cl][r1]!=r1)sb^=vl[cl][r1],r1=fa[cl][r1];
		if(!sb&&l1==r1)
		as[l]=0,t[dep].push_back((modify2){s1[l].a,s1[l].b,s1[l].l,s1[l].r}),s1[nt[l]].b=s1[l].b;
		else as[l]=1,t[dep].push_back((modify2){s1[l].a,s1[l].c,s1[l].l,s1[l].r});
		while(!t1[dep].empty())
		{
			sth tp=t1[dep].top();t1[dep].pop();
			sz[tp.a][fa[tp.a][tp.b]]-=sz[tp.a][tp.b];fa[tp.a][tp.b]=tp.b,vl[tp.a][tp.b]=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	s[dep+1][0].clear();
	s[dep+1][1].clear();
	t[dep+1].clear();
	for(int i=0;i<sz1;i++)
	{
		modify2 tp=s[dep][v][i];
		if(tp.l<=l&&tp.r>=r)continue;
		if(tp.l<=mid)s[dep+1][0].push_back(tp);
		if(tp.r>mid)s[dep+1][1].push_back(tp);
	}
	cdq(l,mid,0,dep+1);
	int s1=t[dep+1].size();
	for(int i=0;i<s1;i++)
	{
		modify2 tp=t[dep+1][i];
		s[dep+1][1].push_back(tp);
		if(tp.r>r)t[dep].push_back(tp);
	}
	t[dep+1].clear();
	cdq(mid+1,r,1,dep+1);
	s1=t[dep+1].size();
	for(int i=0;i<s1;i++)
	{
		modify2 tp=t[dep+1][i];
		t[dep].push_back(tp);
	}
	while(!t1[dep].empty())
	{
		sth tp=t1[dep].top();t1[dep].pop();	
		sz[tp.a][fa[tp.a][tp.b]]-=sz[tp.a][tp.b];fa[tp.a][tp.b]=tp.b,vl[tp.a][tp.b]=0;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;i++)scanf("%d%d",&f[i][0],&f[i][1]);
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)fa[i][j]=j,sz[i][j]=1;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		s1[i]=(modify){a,cl[a],b,i,0};s1[las[a]].r=i-1;nt[las[a]]=i;las[a]=i;cl[a]=b;
	}
	for(int i=1;i<=m;i++)s1[las[i]].r=q;
	cdq(1,q,1,0);
	for(int i=1;i<=q;i++)printf("%s\n",as[i]?"YES":"NO");
}