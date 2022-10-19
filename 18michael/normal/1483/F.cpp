#include<bits/stdc++.h>
using namespace std;
int n,now,to_t=0,p,dfn_t=0,ans=0,st_t,mn;
int fail[1000002],c[1000002],dfn[1000002],num[1000002],st[1000002],fa[1000002],cnt[1000002],siz[1000002],len[1000002];
int to[1000002][26];
char s[1000002];
vector<int> vec1;
vector<int> vec[1000002],son[1000002];
queue<int> q;
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[1000002];
	inline void modify(int x,int d)
	{
		while(x<=to_t+1)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline void dfs(int x)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=0,v;i<son[x].size();++i)dfs(v=son[x][i]),siz[x]+=siz[v];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,l;i<=n;++i)
	{
		scanf("%s",s),l=strlen(s),now=0;
		for(int j=0;j<l;++j)
		{
			if(!to[now][s[j]-='a'])c[to[now][s[j]]=(++to_t)]=s[j],fa[to_t]=now,len[to_t]=j;
			vec[i].push_back(now=to[now][s[j]]);
		}
		num[now]=i;
	}
	for(int i=0;i<26;++i)if(to[0][i])for(int j=0;j<26;++j)if(to[to[0][i]][j])q.push(to[to[0][i]][j]);
	for(;q.size();)
	{
		p=q.front(),q.pop();
		for(now=fail[fa[p]];now && !to[now][c[p]];now=fail[now]);
		if(to[now][c[p]])fail[p]=to[now][c[p]];
		for(int i=0;i<26;++i)if(to[p][i])q.push(to[p][i]);
	}
	for(int i=1;i<=to_t;++i)son[fail[i]].push_back(i);
	dfs(0);
	for(int i=1;i<=n;++i)
	{
		vec1.clear(),mn=vec[i].size();
		for(int j=vec[i].size()-1;~j;--j)
		{
			S.modify(dfn[vec[i][j]],1),st_t=0;
			for(now=(j+1==vec[i].size()? fail[vec[i][j]]:vec[i][j]);now && !num[now];now=fail[now])st[++st_t]=now;
			if(num[now] && j-len[now]<mn)
			{
				if(!cnt[now])vec1.push_back(now);
				++cnt[now],mn=j-len[now];
			}
			for(int k=1;k<=st_t;++k)fail[st[k]]=now;
		}
		for(int j=0;j<vec1.size();++j)ans+=(S.query(dfn[vec1[j]]+siz[vec1[j]]-1)-S.query(dfn[vec1[j]]-1)==cnt[vec1[j]]),cnt[vec1[j]]=0;
		for(int j=0;j<vec[i].size();++j)S.modify(dfn[vec[i][j]],-1);
	}
	return 0&printf("%d",ans);
}