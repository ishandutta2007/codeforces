#include<bits/stdc++.h>
#define sq 316
#define bs 233
#define LL long long
using namespace std;
int n,q,to_t,now,p;
LL res;
int Ed[100002],bl[100002],st[100002],ed[100002],fa[100002],fail[100002],cnt[100002],l[100002],r[100002],k[100002],sum[100002];
LL Hs[100002],ans[100002];
int to[100002][26];
char s[100002],c[100002];
queue<int> Q;
vector<int> vec[100002],vec1[100002],vec2[100002],vecto[100002];
unordered_map<LL,int> mp;
typedef pair<int,int> P;
vector<P> Vec;
inline int newnode()
{
	return ++to_t,fail[to_t]=cnt[to_t]=0,vec[to_t].clear(),vecto[to_t].clear(),to_t;
}
inline void dfs(int x)
{
	for(int i=0,v;i<vec[x].size();++i)cnt[v=vec[x][i]]+=cnt[x],dfs(v);
}
inline void dfs1(int x)
{
	for(int i=0,v;i<vec[x].size();++i)dfs1(v=vec[x][i]),cnt[x]+=cnt[v];
}
inline void getfail()
{
	for(int i=0;i<26;++i)if(to[0][i])for(int j=0;j<26;++j)if(to[to[0][i]][j])Q.push(to[to[0][i]][j]);
	for(;!Q.empty();)
	{
		p=Q.front(),Q.pop();
		for(now=fail[fa[p]];now && !to[now][c[p]];now=fail[now]);
		if(to[now][c[p]])now=to[now][c[p]];
		fail[p]=now;
		for(int i=0;i<vecto[p].size();++i)Q.push(to[p][vecto[p][i]]);
	}
	for(int i=1;i<=to_t;++i)vec[fail[i]].push_back(i);
}
inline void maintain(int x)
{
	for(to_t=-1,to_t=newnode();Vec.size();Vec.pop_back())to[Vec.back().first][Vec.back().second]=0;
	for(int i=st[x];i<=ed[x];++i)
	{
		now=0;
		for(int j=Ed[i-1];j<Ed[i];++j)
		{
			if(!to[now][s[j]-'a'])fa[to[now][s[j]-'a']=newnode()]=now,vecto[now].push_back(c[to_t]=s[j]-'a'),Vec.push_back(P(now,s[j]-'a'));
			now=to[now][s[j]-'a'];
		}
		++cnt[now];
	}
	getfail(),dfs(0);
	for(int i=1;i<=n;++i)
	{
		now=sum[i]=0;
		for(int j=Ed[i-1];j<Ed[i];++j)
		{
			for(;now && !to[now][s[j]-'a'];now=fail[now]);
			sum[i]+=cnt[now=to[now][s[j]-'a']];
		}
	}
	for(int i=0;i<vec2[x].size();++i)ans[vec2[x][i]]+=sum[k[vec2[x][i]]];
}
inline void solve(int x)
{
	for(to_t=-1,to_t=newnode();Vec.size();Vec.pop_back())to[Vec.back().first][Vec.back().second]=0;
	for(int i=1;i<=n;++i)
	{
		now=0;
		for(int j=Ed[i-1];j<Ed[i];++j)
		{
			if(!to[now][s[j]-'a'])fa[to[now][s[j]-'a']=newnode()]=now,vecto[now].push_back(c[to_t]=s[j]-'a'),Vec.push_back(P(now,s[j]-'a'));
			cnt[now=to[now][s[j]-'a']]+=(i==x);
		}
	}
	getfail(),dfs1(0),cnt[0]=0;
	for(int i=1;i<=n;++i)
	{
		now=0;
		for(int j=Ed[i-1];j<Ed[i];++j)now=to[now][s[j]-'a'];
		sum[i]=cnt[now];
	}
	for(int i=0;i<vec1[x].size();++i)
	{
		for(int j=st[bl[l[vec1[x][i]]]];j<l[vec1[x][i]];++j)ans[vec1[x][i]]-=sum[j];
		for(int j=st[bl[r[vec1[x][i]]]];j<=r[vec1[x][i]];++j)ans[vec1[x][i]]+=sum[j];
	}
}
inline void solve1(int x)
{
	mp.clear();
	for(int i=Ed[x-1];i<Ed[x];++i)
	{
		res=0;
		for(int j=i;j<Ed[x];++j)++mp[res=res*bs+s[j]];
	}
	for(int i=0;i<vec1[x].size();++i)
	{
		for(int j=st[bl[l[vec1[x][i]]]];j<l[vec1[x][i]];++j)ans[vec1[x][i]]-=mp[Hs[j]];
		for(int j=st[bl[r[vec1[x][i]]]];j<=r[vec1[x][i]];++j)ans[vec1[x][i]]+=mp[Hs[j]];
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+Ed[i-1]),Ed[i]=strlen(s+Ed[i-1])+Ed[i-1],bl[i]=(i-1)/sq+1;
		for(int j=Ed[i-1];j<Ed[i];++j)Hs[i]=Hs[i]*bs+s[j];
	}
	for(int i=1;i<=bl[n];++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&l[i],&r[i],&k[i]),vec1[k[i]].push_back(i);
		for(int j=bl[l[i]];j<bl[r[i]];++j)vec2[j].push_back(i);
	}
	for(int i=1;i<=bl[n];++i)maintain(i);
	for(int i=1;i<=n;++i)if(Ed[i]-Ed[i-1]>sq)solve(i);else solve1(i);
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}