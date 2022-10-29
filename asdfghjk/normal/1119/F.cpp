#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
const int N=250005;
multiset<int> st[N];
multiset<int>::iterator ddq;
set<int> Adj[N];
set<int>::iterator dzx;
vector<int> del,ins;
int n,i,j,k,x,X,head[N],adj[N*2],nxt[N*2],len[N*2],p[N],cnt,d[N],id[N];
bool v[N];
ll f[N][2],u[N],ans,s[N];
bool cmp(int a,int b)
{
	return d[a]<d[b];
}
void dfs(int x,int dad)
{
	v[x]=true;
	ll sum=0;
	for(set<int>::iterator dzx=Adj[x].begin();dzx!=Adj[x].end();dzx++)
		if(adj[*dzx]!=dad)
		{
			dfs(adj[*dzx],x);
			sum+=f[adj[*dzx]][0];
		}
	cnt=0;
	while(!st[x].empty()&&st[x].size()>d[x]-X)
	{
		s[x]-=*(--st[x].end());
		st[x].erase(--st[x].end());
	}
	ll cirno=s[x];
	del.clear(),ins.clear();
	for(set<int>::iterator dzx=Adj[x].begin();dzx!=Adj[x].end();dzx++)
		if(adj[*dzx]!=dad)
			u[++cnt]=f[adj[*dzx]][1]+len[*dzx]-f[adj[*dzx]][0];
	for(int i=1;i<=cnt;++i)
		if(st[x].size()<d[x]-X)
		{
			s[x]+=u[i];
			st[x].insert(u[i]);
			del.push_back(u[i]);
		}
		else if(u[i]<0)
		{
			if(!st[x].empty()&&*(--st[x].end())>=0)
			{
				s[x]-=*(--st[x].end());
				ins.push_back(*(--st[x].end()));
				st[x].erase(--st[x].end());
			}
			s[x]+=u[i];
			st[x].insert(u[i]);
			del.push_back(u[i]);
		}
		else if(!st[x].empty()&&*(--st[x].end())>u[i])
		{
			s[x]-=*(--st[x].end());
			ins.push_back(*(--st[x].end()));
			st[x].erase(--st[x].end());
			st[x].insert(u[i]);
			del.push_back(u[i]);
			s[x]+=u[i];
		}
	if(st[x].size()>=d[x]-X)
	{
		f[x][0]=sum;
		f[x][0]+=s[x];
		f[x][1]=f[x][0]-(!st[x].empty()&&*(--st[x].end())>0?*(--st[x].end()):0);
	}
	else
	{
		f[x][1]=sum;
		f[x][1]+=s[x];
		f[x][0]=f[x][1]+1000001;
	}
	for(int i=0;i<ins.size();++i)
		st[x].insert(ins[i]);
	for(int i=0;i<del.size();++i)
		st[x].erase(st[x].find(del[i]));
	s[x]=cirno;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		Adj[j].insert(i*2-1);
		Adj[k].insert(i*2);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
		++d[j],++d[k];
	}
	for(i=1;i<=n;++i)
		p[i]=i;
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;++i)
		id[p[i]]=i;
	for(x=0,i=1;x<n;++x)
	{
		X=x;
		while(i<=n&&d[p[i]]<=x)
		{
			for(j=head[p[i]];j;j=nxt[j])
				if(id[adj[j]]>=i)
				{
					st[adj[j]].insert(len[j]);
					s[adj[j]]+=len[j];
					Adj[adj[j]].erase(j&1?j+1:j-1);
				}
			st[p[i]].clear();
			Adj[p[i]].clear();
			++i;
		}
		for(j=i;j<=n;++j)
			v[p[j]]=false;
		ans=0;
		for(j=i;j<=n;++j)
			if(!v[p[j]])
			{
				dfs(p[j],-1);
				ans+=f[p[j]][0];
			}
		printf("%lld ",ans);
	}
	return 0;
}