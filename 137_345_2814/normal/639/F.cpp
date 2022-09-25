#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define N 300050
int n,m,q,s[N][2],t[N][2],ct,r[N][2],l[N],ct2,ct3,R,a,b,c;
vector<int> v1,v2,v3;
struct t1{
	int f1[N],f2[N],is[N],fa1[N],dep[N],head[N],cnt;
	int finds1(int x){return f1[x]==x?x:f1[x]=finds1(f1[x]);}
	int finds2(int x){return f2[x]==x?x:f2[x]=finds2(f2[x]);}
	struct edge{int t,next;}ed[N*2];
	void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
	void dfs(int u,int fa){dep[u]=dep[fa]+1;fa1[u]=fa;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
	void un(int i,int j){while(i!=j){if(dep[i]<dep[j])i^=j^=i^=j;f2[i]=fa1[i];i=finds2(fa1[i]);}}
	void pre()
	{
		for(int i=1;i<=n;i++)f1[i]=f2[i]=i;
		for(int i=1;i<=m;i++)if(finds1(s[i][0])!=finds1(s[i][1]))adde(s[i][0],s[i][1]),f1[finds1(s[i][0])]=finds1(s[i][1]),is[i]=1;
		for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
		for(int i=1;i<=m;i++)if(!is[i])un(s[i][0],s[i][1]);
		for(int i=1;i<=n;i++)finds2(i),finds1(i);
		for(int i=1;i<=m;i++)if(f2[s[i][0]]!=f2[s[i][1]])t[++ct][0]=f2[s[i][0]],t[ct][1]=f2[s[i][1]];
	}
}s1;
bool cmp(int i,int j){return l[i]<l[j];}
struct t2{
	int dep[N],head[N],cnt,f[N][21],st[N],rb,ct1;
	vector<int> f2[N];
	map<int,int> id;
	struct edge{int t,next;}ed[N*2];
	void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
	void dfs(int u,int fa){dep[u]=dep[fa]+1;l[u]=++ct1;f[u][0]=fa;for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
	int LCA(int x,int y){if(dep[x]<dep[y])x^=y^=x^=y;for(int i=20;i>=0;i--)if(dep[x]-dep[y]>=(1<<i))x=f[x][i];if(x==y)return x;for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];return f[x][0];}
	void adde2(int a,int b){if(a==b)return;if(!id[a])id[a]=++ct2;if(!id[b])id[b]=++ct2;r[++ct3][0]=id[a];r[ct3][1]=id[b];}
	void build(vector<int> p)
	{
		sort(p.begin(),p.end(),cmp);
		rb=0;
		int s1=p.size();
		for(int i=0;i<s1;i++)
		{
			while(rb&&LCA(st[rb],p[i])!=st[rb])
			{
				int l=LCA(st[rb],p[i]);
				if(dep[l]<=dep[st[rb-1]])adde2(st[rb],st[rb-1]),rb--;
				else adde2(l,st[rb]),st[rb]=l;
			}
			st[++rb]=p[i];
		}
		for(int i=1;i<rb;i++)adde2(st[i],st[i+1]);
	}
	void solve(vector<int> r,vector<int> p)
	{
		int sz=r.size(),sz1=p.size();
		ct2=ct3=0;id.clear();
		for(int i=0;i<sz1;i++)if(!id[p[i]])id[p[i]]=++ct2,f2[s1.f1[p[i]]].push_back(p[i]);
		for(int i=0;i<sz;i++)if(!id[r[i]])id[r[i]]=++ct2,f2[s1.f1[r[i]]].push_back(r[i]);
		for(int i=0;i<sz;i++)if(f2[s1.f1[r[i]]].size())build(f2[s1.f1[r[i]]]),f2[s1.f1[r[i]]].clear();
		for(int i=0;i<sz;i+=2)adde2(r[i],r[i+1]);
		for(int i=0;i<sz1;i++)v3.push_back(id[p[i]]);
	}
	void pre()
	{
		for(int i=1;i<=ct;i++)adde(t[i][0],t[i][1]);
		for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
	}
}s2;
struct t3{
	int f1[N],f2[N],is[N],fa1[N],dep[N],head[N],cnt;
	int finds1(int x){return f1[x]==x?x:f1[x]=finds1(f1[x]);}
	int finds2(int x){return f2[x]==x?x:f2[x]=finds2(f2[x]);}
	struct edge{int t,next;}ed[N*2];
	void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
	void dfs(int u,int fa){dep[u]=dep[fa]+1;fa1[u]=fa;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
	void un(int i,int j){i=finds2(i);j=finds2(j);while(i!=j){if(dep[i]<dep[j])i^=j^=i^=j;f2[finds2(i)]=finds2(fa1[i]);i=finds2(fa1[i]);}}
	bool solve(vector<int> fu)
	{
		for(int i=1;i<=ct2;i++)f1[i]=f2[i]=i,head[i]=0,dep[i]=0;cnt=0;
		for(int i=1;i<=ct3;i++)if(finds1(r[i][0])!=finds1(r[i][1]))adde(r[i][0],r[i][1]),f1[finds1(r[i][0])]=finds1(r[i][1]),is[i]=1;
		for(int i=1;i<=ct2;i++)if(!dep[i])dfs(i,0);
		for(int i=1;i<=ct3;i++)if(!is[i])un(r[i][0],r[i][1]);
		for(int i=1;i<=ct3;i++)is[i]=0;
		for(int i=1;i<=ct2;i++)finds2(i);
		int sz1=fu.size();
		for(int i=0;i<sz1-1;i++)if(f2[fu[i]]!=f2[fu[i+1]])return 0;
		return 1;
	}
}s3;
int lsj(int x){return (x+R+n-1)%n+1;}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)scanf("%d%d",&s[i][0],&s[i][1]);
	s1.pre();s2.pre();
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);v1.clear();v2.clear();v3.clear();
		for(int i=1;i<=a;i++)scanf("%d",&c),c=lsj(c),v1.push_back(s1.f2[c]);
		for(int i=1;i<=b*2;i++)scanf("%d",&c),c=lsj(c),v2.push_back(s1.f2[c]);
		s2.solve(v2,v1);int as=s3.solve(v3);
		if(as)printf("YES\n"),R=(R+i)%n;
		else printf("NO\n");
	}
}