#include<cstdio>
#include<cstring>
#include<vector>
#define LL long long
using namespace std;
int n,k,l,t=0,edge_t=0,dfn_t=-1;LL ans;
int num[100002],ed[100002],fa[1000002],fail[1000002],la[1000002],dfn[1000002],siz[1000002],cnt[1000002];
char s[1000002],ch[1000002];
int to[1000002][26];
vector<int> vec[1000002];
struct aaa
{
	int to,nx;
}edge[1000002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[1000002];
	inline void modify(int x,int d)
	{
		while(x<=t)sum[x]+=d,x+=lowbit(x);
	}
	inline LL query(int x)
	{
		LL res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),siz[x]+=siz[v];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,now;i<=k;++i)
	{
		scanf("%s",s),l=strlen(s),now=0,cnt[i]=1;
		for(int j=0;j<l;++j)
		{
			if(!to[now][s[j]-'a'])vec[j].push_back(to[now][s[j]-'a']=(++t)),fa[t]=now,ch[t]=s[j];
			now=to[now][s[j]-'a'];
		}
		num[i]=now;
	}
	for(int i=0,now;i<t;++i)
		for(int j=0;j<vec[i].size();++j)
		{
			for(now=fa[vec[i][j]];(now=fail[now]) && !to[now][ch[vec[i][j]]-'a'];);
			if(to[now][ch[vec[i][j]]-'a']==vec[i][j])fail[vec[i][j]]=0;
			else fail[vec[i][j]]=to[now][ch[vec[i][j]]-'a'];
			add_edge(fail[vec[i][j]],vec[i][j]);
		}
	dfs(0);
	for(int i=1;i<=k;++i)S.modify(dfn[num[i]]+siz[num[i]],-1),S.modify(dfn[num[i]],1);
	for(int i=1,now;i<=n;++i)
	{
		scanf("%s",s),l=strlen(s);
		if(s[ed[i-1]]=='?')
		{
			now=ans=0;
			for(int j=1;j<l;++j)
			{
				while(now && !to[now][s[j]-'a'])now=fail[now];
				if(now=to[now][s[j]-'a'])ans+=S.query(dfn[now]);
			}
			printf("%lld\n",ans);
		}
		else
		{
			now=0;
			for(int j=1;j<l;++j)now=now*10+(s[j]^48);
			if(cnt[now]+(s[0]=='+'? 1:-1)>=0 && cnt[now]+(s[0]=='+'? 1:-1)<=1)cnt[now]+=(s[0]=='+'? 1:-1),S.modify(dfn[num[now]]+siz[num[now]],(s[0]=='+'? -1:1)),S.modify(dfn[num[now]],(s[0]=='+'? 1:-1));
		}
	}
	return 0;
}