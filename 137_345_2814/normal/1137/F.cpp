#include<cstdio>
#include<algorithm>
using namespace std;
#define N 400500
int tr[N],f[N],sz[N],cl[N],ch[N][2],l[N],n,m,s[N],ct,a,b,head[N],cnt;
struct edge{int t,next;}ed[N*2];
void adde(int x,int y){ed[++cnt]=(edge){y,head[x]};head[x]=cnt;ed[++cnt]=(edge){x,head[y]};head[y]=cnt;}
char str[N];
void ad(int x,int k){if(!x)return;for(int i=x;i<=n+m;i+=i&-i)tr[i]+=k;}
int qu(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=tr[i];return ans;}
bool nroot(int x){return ch[f[x]][0]==x||ch[f[x]][1]==x;}
void pushup(int x){sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
void pushdown(int x){if(l[x])swap(ch[x][0],ch[x][1]),l[ch[x][0]]^=1,l[ch[x][1]]^=1,l[x]=0;}
void rotate(int x)
{
	int a=f[x],b=f[a],tmp=ch[a][1]==x;
	if(nroot(a))ch[b][ch[b][1]==a]=x;f[x]=b;
	f[ch[x][!tmp]]=a;ch[a][tmp]=ch[x][!tmp];
	f[a]=x;ch[x][!tmp]=a;
	pushup(a);pushup(x);
}
void splay(int x)
{
	int st=x,rb=0,x2=x;
	while(nroot(st))s[++rb]=st,st=f[st];
	int c=cl[st];cl[st]=0;
	pushdown(st);while(rb)pushdown(s[rb--]);
	while(nroot(x))
	{
		int a=f[x],b=f[a];
		if(nroot(a))rotate((ch[a][1]==x)^(ch[b][1]==a)?a:x);
		rotate(x);
	}
	cl[x2]=c;
}
void access(int x,int id)
{
	int tmp=0,x2=x;
//	splay(x);ad(cl[x],-sz[x]);
	while(x)
	{
		splay(x);
		if(tmp)ad(cl[tmp],-sz[tmp]),ad(cl[x],sz[tmp]);
		cl[tmp]=0;
		cl[ch[x][1]]=cl[x];
		ch[x][1]=tmp;
		pushup(x);
		tmp=x;x=f[x];
	}
	splay(x2);ad(cl[x2],-sz[x2]);ad(id,sz[x2]);cl[x2]=id;
}
void makeroot(int x,int id){access(x,id);l[x]^=1;}
int query(int x){splay(x);return qu(cl[x]-1)+sz[ch[x][1]]+1;}
void dfs(int u,int fa){f[u]=fa;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	dfs(1,0);
	for(int i=1;i<=n+m;i++)sz[i]=1;
	for(int i=1;i<=n;i++)
	makeroot(i,++ct);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",str+1,&a);
		if(str[1]=='u')
		makeroot(a,++ct);
		else if(str[1]=='w')printf("%d\n",query(a));
		else scanf("%d",&b),printf("%d\n",query(a)<query(b)?a:b);
	}
}//qwq