#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=755,M=1e7+5;
int n,tt,cc,ch[M][2],fail[M],ed[M],G[N][N],mat[N*2],vis[N*2];
string s[N];vi e[N*2];queue<int>Q;
int dfs(int x)
{
	for(int y:e[x])
	{
		if(vis[y]==cc)continue;
		vis[y]=cc;
		if(!mat[y]||dfs(mat[y]))
		{
			mat[x]=y;mat[y]=x;
			return 1;
		}
	}
	return 0;
}
void dfs2(int x)
{
	vis[x]=cc;
	for(int y:e[x])
	{
		if(mat[y]&&vis[y]!=cc)vis[y]=cc,dfs2(mat[y]);
	}
}
int main()
{
	n=rd();
	rep(i,1,n)
	{
		cin>>s[i];int l=s[i].size(),x=0;
		rep0(j,0,l)
		{
			int c=s[i][j]-'a';
			if(!ch[x][c])ch[x][c]=++tt;
			x=ch[x][c];
		}
		ed[x]=i;
	}
	rep(i,0,1)if(ch[0][i])Q.push(ch[0][i]);
	while(!Q.empty())
	{
		int x=Q.front(),p=fail[x];Q.pop();
		rep(i,0,1)
		{
			if(ch[x][i])fail[ch[x][i]]=ch[p][i],Q.push(ch[x][i]);
			else ch[x][i]=ch[p][i];
		}
		if(!ed[x])ed[x]=ed[fail[x]];
	}
	rep(i,1,n)
	{
		int l=s[i].size(),x=0;
		rep0(j,0,l)
		{
			int c=s[i][j]-'a';x=ch[x][c];
			if(j==l-1)G[i][ed[fail[x]]]=1;
			else G[i][ed[x]]=1;
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)G[i][j]|=G[i][k]&G[k][j];
	rep(i,1,n)rep(j,1,n)if(G[i][j])e[i].pb(j+n),e[j+n].pb(i);
	int ans=n;
	rep(i,1,n)if(!mat[i])cc++,ans-=dfs(i);
	printf("%d\n",ans);cc++;
	rep(i,1,n)if(!mat[i])dfs2(i);
	rep(i,1,n)if(vis[i]==cc&&vis[n+i]!=cc)printf("%d ",i);
	puts("");return 0;
}