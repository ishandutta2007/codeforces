#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define pb push_back

const int NN=100005,N=5000005;

int cnt,len,tim,bel[N],dfn[N],low[N],stk[N];
int f[N],q[N],w[N],du[N],now[NN];
int tot,lnk[N],son[N],nxt[N];
bool bo[N],vis[N];
vector<int>vec[N];
int n,m,day,newn;
char s[NN];

int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int id(int x,int y) {return (x-1)*day+y;}
void add(int x,int y) {tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
void put(int x) {if (bo[x]&&now[(x-1)/day+1]!=cnt) w[now[(x-1)/day+1]=cnt]++;}
void Tarjan(int x)
{
	dfn[x]=low[x]=++tim;vis[stk[++len]=x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	  if (!dfn[son[j]]) Tarjan(son[j]),low[x]=min(low[x],low[son[j]]);
	  else if (vis[son[j]]) low[x]=min(low[x],dfn[son[j]]);
	if (dfn[x]==low[x])
	{
		cnt++;for (int y=stk[len];y!=x;y=stk[--len]) bel[y]=cnt,vis[y]=0,put(y);
		bel[x]=cnt,vis[x]=0,put(x);len--;
	}
}
int main()
{
	n=read(),m=read(),day=read();newn=n*day;
	while (m--) {int x=read(),y=read();rep(i,1,day) add(id(x,i),id(y,i%day+1));}
	rep(i,1,n) {scanf("%s",s+1);rep(j,1,day) bo[id(i,j)]=(s[j]=='1');}
	Tarjan(1);rep(i,1,newn) for (int j=lnk[i];j;j=nxt[j])
	  if (bel[i]!=bel[son[j]]) vec[bel[son[j]]].pb(bel[i]),du[bel[i]]++;
	int hed=0,tal=0;rep(i,1,cnt) if (!du[i]) q[++tal]=i;
	while (hed!=tal)
	{
		int x=q[++hed];f[x]+=w[x];
		for (int sz=vec[x].size(),i=0;i<sz;i++)
		{
			f[vec[x][i]]=max(f[vec[x][i]],f[x]);
			if (!(--du[vec[x][i]])) q[++tal]=vec[x][i];
		}
	}
	printf("%d\n",f[bel[1]]);
	return 0;
}