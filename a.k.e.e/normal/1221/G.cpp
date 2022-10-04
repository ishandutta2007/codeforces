#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=45,SANS=20;
 
int n,G[MAXN][MAXN],cnt,lone;
bool vis[MAXN];
void dfs1(int u)
{
	vis[u]=1;
	enum(i,1,n)if(G[u][i] && !vis[i])dfs1(i);
}
int col[MAXN];
bool dfs2(int u)
{
	enum(i,1,n)
	{
		if(!G[u][i])continue;
		if(!col[i])
		{
			col[i]=3-col[u];
			if(!dfs2(i))return 0;
		}
		else if(col[i]==col[u])return 0;
	}
	return 1;
}

int f[1<<20|1],g[1<<20|1];
void work(int l,int r)
{
	enum(i,0,(1<<(r-l+1))-1)
	{
		g[i]=1;
		enum(j,l,r)
			if(i&(1<<(j-l)))
				enum(k,j+1,r)
					if((i&(1<<(k-l))) && G[j][k])g[i]=0;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n);readint(E);
	if(E<=2)return 0*printf("0\n");
	while(E--)
	{
		readint(u);readint(v);
		G[u][v]=G[v][u]=1;
	}
	ll ans=0;
	enum(i,1,n)
	{
		bool flag=1;
		enum(j,1,n)if(G[i][j])flag=0;
		lone+=flag;
		if(!vis[i]){dfs1(i);++cnt;}
	}
	bool bin=1;
	enum(i,1,n)
	if(!col[i])
	{
		col[i]=1;
		if(!dfs2(i)){bin=0;break;}
	}
	ans=(1ll<<n)-(1ll<<cnt)+(1ll<<(lone+1))+(bin?(1ll<<cnt):0);
	//cerr<<cnt<<" "<<lone<<" "<<bin<<endl;
	
	ll res=0;
	if(n<=SANS)
	{
		work(1,n);
		enum(i,0,(1<<n)-1)
			if(g[i])++res;
	}
	else
	{
		enum(i,0,(1<<SANS)-1)
		{
			enum(j,1,SANS)
			{
				if(!(i&(1<<(j-1))))continue;
				enum(k,j+1,SANS)
					if((i&(1<<(k-1))) && G[j][k])
						{f[i]=-1;break;}
				if(f[i]<0)break;
			}
			if(f[i]<0)continue;
			int u=0;
			enum(j,1,SANS)
				if(i&(1<<(j-1)))
					enum(k,SANS+1,n)
						if(G[j][k])u|=(1<<(k-SANS-1));
			f[i]=u^((1<<(n-SANS))-1);
		}
//enum(i,0,(1<<SANS)-1)cerr<<i<<":"<<f[i]<<" ";cerr<<endl;
		work(SANS+1,n);
//enum(i,0,(1<<SANS)-1)cerr<<i<<":"<<g[i]<<" ";cerr<<endl;
		enum(i,1,n-SANS)
			enum(j,0,(1<<(n-SANS))-1)
				if(j&(1<<(i-1)))
					g[j]+=g[j^(1<<(i-1))];
//enum(i,0,(1<<SANS)-1)cerr<<i<<":"<<g[i]<<" ";cerr<<endl;
		enum(i,0,(1<<SANS)-1)
			if(f[i]>=0)res+=g[f[i]];
	}
	printf("%lld\n",ans-2*res);
	return 0;
}