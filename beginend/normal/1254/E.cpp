#include<bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=500005;
const int MOD=1000000007;

int n,jc[N],fa[N],dep[N],cnt,s1[N],s2[N],f[N];
bool in[N],out[N];
std::vector<int> e[N];
std::vector<pi> con[N];

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for (auto to:e[x])
	{
		if (to==fa[x]) continue;
		fa[to]=x;
		dfs(to);
	}
}

void work(int x,int y)
{
	int t1=0,t2=0;
	while (dep[x]!=dep[y]&&cnt>=0)
		if (dep[x]>dep[y]) s1[++t1]=x,x=fa[x],cnt--;
		else s2[++t2]=y,y=fa[y],cnt--;
	while (x!=y&&cnt>=0) s1[++t1]=x,s2[++t2]=y,x=fa[x],y=fa[y],cnt-=2;
	s1[++t1]=x;
	if (cnt<0) {puts("0");exit(0);}
	while (t2) s1[++t1]=s2[t2--];
	con[s1[1]].pb(mp(0,s1[2]));
	con[s1[t1]].pb(mp(s1[t1-1],n+1));
	for (int i=2;i<t1;i++) con[s1[i]].pb(mp(s1[i-1],s1[i+1]));
}

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}

int calc(int x)
{
	for (auto to:e[x]) in[to]=out[to]=0,f[to]=to;
	out[0]=in[n+1]=0;
	f[0]=0;f[n+1]=n+1;
	int ret=e[x].size();
	for (auto t:con[x])
	{
		int u=t.first,v=t.second;
		if (out[u]||in[v]) return 0;
		out[u]=in[v]=1;ret--;
		if (find(u)==find(v)) return 0;
		f[find(u)]=find(v); 
	}
	if (ret>=0&&find(0)==find(n+1)) return 0;
	if (ret<0) return 1;
	return jc[ret];
}

int main()
{
	scanf("%d",&n);
	jc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	dfs(1);
	cnt=n*2-2;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (!x) continue;
		if (x==i) {puts("0");return 0;}
		work(x,i);
	}
	int ans=1;
	for (int i=1;i<=n;i++) ans=(LL)ans*calc(i)%MOD;
	printf("%d\n",ans);
	return 0;
}