#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=205;

int k,n;
char str[MAXN];
int b[MAXN],a[MAXN],res[MAXN],col[MAXN],tmp[MAXN][MAXN];
vector<int> G[MAXN<<1|1];
inline void addEdge(int u,int v){G[u].pb(v);}
bool dfs(int u)
{
	if(col[u>>1]==((u&1)^1))return 0;
	if(col[u>>1]==(u&1))return 1;
	col[u>>1]=(u&1);
	for(auto v:G[u])if(!dfs(v))return 0;
	return 1;
}
bool vis[MAXN][2];
void search(int i,bool flag)
{
	if(i>n)
	{
		for(int i=1;i<=n;++i)putchar(res[i]+'a');
		exit(0);
	}
	if(vis[i][flag])return;
	vis[i][flag]=1;
	for(int j=(flag?0:a[i]);j<k;++j)
	{
		memcpy(tmp[i],col,sizeof(col));
		if(dfs(i*2+b[j]))
		{
			res[i]=j;
			search(i+1,flag || j>a[i]);
		}
		memcpy(col,tmp[i],sizeof(col));
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;char x[2],y[2];
	scanf("%s",str);
	k=strlen(str);
	for(int i=0;i<k;++i)b[i]=(str[i]=='V');
	readint(n),readint(E);
	while(E--)
	{
		readint(u);scanf("%s",x);readint(v);scanf("%s",y);
		int xx=(x[0]=='V'),yy=(y[0]=='V');
		G[u*2+xx].pb(v*2+yy);G[v*2+1-yy].pb(u*2+1-xx);
	}
	scanf("%s",str+1);
	for(int i=1;i<=n;++i)a[i]=str[i]-'a';
	memset(col,-1,sizeof(col));
	search(1,0);
	printf("-1\n");
	return 0;
}