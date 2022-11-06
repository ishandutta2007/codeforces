#include<bits/stdc++.h>
using namespace std;
const int N=150010;
#define pb push_back
int n,q,ban,fa[N],len[N],id[N],cnt[N][26],sum[N],f[N][26];
vector<int>E[N],G[N];char c[N];
void dfs(int x)
{
	int sz=G[x].size();
	for(int i=0;i<sz;i++)
	{
		int y=G[x][i];dfs(y);
		if(len[x]&&len[x]!=len[y]+1){while(q--)puts("Fou");exit(0);}
		len[x]=len[y]+1;id[x]=id[y];
	}
	if(sz!=1||!x)
	{
		id[x]=x;
		for(int i=0;i<sz;i++){int y=G[x][i];fa[id[y]]=x;E[x].pb(id[y]);}
	}
}
inline void upd(int x,int c,int w)
{
	cnt[x][c]+=w;
	for(int t=fa[x];~t;t=fa[t])
	{
		ban-=sum[t]>len[t];sum[t]-=f[t][c];f[t][c]=0;
		for(int i=0;i<E[t].size();i++){int y=E[t][i];f[t][c]=max(f[t][c],f[y][c]+cnt[y][c]);}
		sum[t]+=f[t][c];ban+=sum[t]>len[t];
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2,u;i<=n;i++){scanf("%d %c",&u,&c[i]);G[u].pb(i);}
	G[0].pb(1);dfs(0);len[0]--;fa[0]=-1;
	for(int i=2;i<=n;i++)if(c[i]!='?')upd(id[i],c[i]-'a',1);
	while(q--)
	{
		int x;char t;scanf("%d %c",&x,&t);
		if(c[x]!='?')upd(id[x],c[x]-'a',-1);
		c[x]=t;if(c[x]!='?')upd(id[x],c[x]-'a',1);
		if(ban){puts("Fou");continue;}
		int ans=0;for(int i=0;i<26;i++)ans+=(i+1)*(f[0][i]+len[0]-sum[0]);
		printf("Shi %d\n",ans);
	}
	return 0;
}