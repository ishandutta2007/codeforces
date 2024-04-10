#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
const int N=300005;
struct node
{
	int ch[26],fail,w;
}g;
vector<node> vct[2][30];
int m,t,i,num[2],w[2][30],cnt[2],sz[2][30],q[N],bg,ed,head[N],adj[N],nxt[N];
string s,str[2][N];
bool v[N];
void dfs(int id,int cnt,int x,int w)
{
	w+=vct[id][cnt][x].w;
	vct[id][cnt][x].w=w;
	for(int y=head[x];y;y=nxt[y])
		dfs(id,cnt,adj[y],w);
}
void add(int id)
{
	int i,j,k,x,y,z,len;
	str[id][++num[id]]=s;
	for(i=cnt[id],j=1;i>=1;--i)
	{
		if(!v[j+w[id][i]])
			break;
		j+=w[id][i];
		vct[id][i].clear();
	}
	cnt[id]=i+1;
	w[id][cnt[id]]=j;
	sz[id][cnt[id]]=1;
	vct[id][cnt[id]].clear();
	vct[id][cnt[id]].push_back(g);
	for(k=num[id]-j+1;k<=num[id];++k)
	{
		len=str[id][k].size();
		for(x=y=0;x<len;++x)
		{
			z=str[id][k][x]-'a';
			if(!vct[id][cnt[id]][y].ch[z])
			{
				vct[id][cnt[id]][y].ch[z]=sz[id][cnt[id]]++;
				vct[id][cnt[id]].push_back(g);
			}
			y=vct[id][cnt[id]][y].ch[z];
		}
		vct[id][cnt[id]][y].w++;
	}
	bg=1,ed=0;
	for(i=0;i<26;++i)
		if(vct[id][cnt[id]][0].ch[i])
			q[++ed]=vct[id][cnt[id]][0].ch[i];
	while(bg<=ed)
	{
		for(i=0;i<26;++i)
			if(vct[id][cnt[id]][q[bg]].ch[i])
			{
				q[++ed]=vct[id][cnt[id]][q[bg]].ch[i];
				vct[id][cnt[id]][q[ed]].fail=vct[id][cnt[id]][vct[id][cnt[id]][q[bg]].fail].ch[i];
			}
			else
				vct[id][cnt[id]][q[bg]].ch[i]=vct[id][cnt[id]][vct[id][cnt[id]][q[bg]].fail].ch[i];
		++bg;
	}
	for(i=sz[id][cnt[id]]-1;i>=0;--i)
		head[i]=0;
	for(i=sz[id][cnt[id]]-1;i>0;--i)
	{
		adj[i]=i;
		nxt[i]=head[vct[id][cnt[id]][i].fail];
		head[vct[id][cnt[id]][i].fail]=i;
	}
	dfs(id,cnt[id],0,0);
}
long long work(int id)
{
	int i,j,k,len=s.size();
	long long rtn=0;
	for(i=1;i<=cnt[id];++i)
	{
		for(j=k=0;j<len;++j)
		{
			k=vct[id][i][k].ch[s[j]-'a'];
			rtn+=vct[id][i][k].w;
		}
	}
	return rtn;
}
int main()
{
	cin>>m;
	for(i=0;(1<<i)<N;++i)
		v[1<<i]=true;
	while(m--)
	{
		cin>>t>>s;
		if(t==1||t==2)
			add(t-1);
		else
		{
			cout<<work(0)-work(1)<<endl;
			cout.flush();
		}
	}
	return 0;
}