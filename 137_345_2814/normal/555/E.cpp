#include<cstdio>
using namespace std;
#define N 200050
int head[N],cnt,fa[N],f[N][20],n,m,q,h[N][2],ct,fa2[N],cnt2,head2[N],dep[N],fg[N][2],tp,a,b,t[N][2],is[N];
struct edge{int t,next;}ed[N*2],ed2[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void adde2(int f,int t){ed2[++cnt2]=(edge){t,head2[f]};head2[f]=cnt2;ed2[++cnt2]=(edge){f,head2[t]};head2[t]=cnt2;}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
int finds2(int x){return fa2[x]==x?x:fa2[x]=finds2(fa2[x]);}
void dfs1(int u,int fa){f[u][0]=fa;dep[u]=dep[fa]+1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs1(ed[i].t,u);}
void dfs2(int u,int fa){f[u][0]=fa;dep[u]=dep[fa]+1;for(int i=1;i<=18;i++)f[u][i]=f[f[u][i-1]][i-1];for(int i=head2[u];i;i=ed2[i].next)if(ed2[i].t!=fa)dfs2(ed2[i].t,u);}
int LCA(int x,int y){
if(dep[x]<dep[y])x^=y^=x^=y;
for(int i=18;i>=0;i--)if(dep[x]-dep[y]>=(1<<i))x=f[x][i];
if(x==y)return x;
for(int i=18;i>=0;i--)if(f[x][i]!=f[y][i])
x=f[x][i],y=f[y][i];return f[x][0];}
void un(int x,int y){while(finds2(x)!=finds2(y)){if(dep[x]<dep[y])x^=y^=x^=y;fa2[x]=f[x][0];x=finds2(x);}}
void dfs3(int u,int fa){for(int i=head2[u];i;i=ed2[i].next)if(ed2[i].t!=fa)dfs3(ed2[i].t,u),fg[u][0]+=fg[ed2[i].t][0],fg[u][1]+=fg[ed2[i].t][1];if(fg[u][0]&&fg[u][1])tp=1;}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)fa[i]=i,fa2[i]=i;
	for(int i=1;i<=m;i++){scanf("%d%d",&a,&b);t[i][0]=a,t[i][1]=b;if(finds(a)==finds(b))h[++ct][0]=a,h[ct][1]=b;else fa[finds(a)]=finds(b),adde(a,b);}
	dfs1(1,0);for(int i=1;i<=ct;i++)un(h[i][0],h[i][1]);
	for(int i=1;i<=m;i++)if(finds2(t[i][0])!=finds2(t[i][1]))adde2(finds2(t[i][0]),finds2(t[i][1]));
	for(int i=1;i<=n;i++)dep[i]=0;
	for(int i=1;i<=n;i++)if(finds2(i)==i&&!dep[i])
	is[i]=1,dfs2(i,0);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(finds(a)!=finds(b)){printf("No\n");return 0;}
		a=finds2(a);b=finds2(b);
		int l=LCA(a,b);
		fg[a][0]++,fg[l][0]--;fg[b][1]++;fg[l][1]--;
	}
	for(int i=1;i<=n;i++)if(is[i])dfs3(i,0);
	printf("%s\n",tp?"No":"Yes");
}