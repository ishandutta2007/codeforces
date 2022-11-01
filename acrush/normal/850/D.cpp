#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=32;
const int maxsize=512;
const int maxsize2=(maxsize+1)*maxsize/2;

int m;
int a[maxn];
int f[maxsize][maxsize2];
vector<int> r;
int best_n;
vector<int> best_r;

void dfs2(int depth,int n,int s);
void dfs(int depth,int n,int s)
{
	if (n>=best_n) return;
	int base=n*(n-1)/2;
	if (n>=maxsize || s<base || s-base>=maxsize2) return;
	if (f[n][s-base]&(1<<depth)) return;
	f[n][s-base]|=(1<<depth);
	if (depth==m-1)
	{
		if (s==n*(n-1)/2) best_n=n,best_r=r;
	}
	else 
		dfs2(depth+1,n,s);
	r.push_back(a[depth]);
	dfs(depth,n+1,s+a[depth]);
	r.pop_back();
}
void dfs2(int depth,int n,int s)
{
	r.push_back(a[depth]);
	dfs(depth,n+1,s+a[depth]);
	r.pop_back();
}

const int maxnode=1000000+5;
const int maxedge=1000000+5;
const int oo=1000000000;

int node,src,dest,nedge;
int head[maxnode],point[maxedge],nextp[maxedge],flow[maxedge],capa[maxedge];
int distp[maxnode],Q[maxnode],work[maxnode];

void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src;
	dest=_dest;
	for (int i=0;i<node;i++) head[i]=-1;
	nedge=0;
}
void addedge(int u,int v,int c1,int c2)
{
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,nextp[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,nextp[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	for (int i=0;i<node;i++) distp[i]=-1;
	distp[src]=0;
	int sizeQ=0;
	Q[sizeQ++]=src;
	for (int cl=0;cl<sizeQ;cl++)
		for (int k=Q[cl],i=head[k];i>=0;i=nextp[i])
			if (flow[i]<capa[i] && distp[point[i]]<0)
			{
				distp[point[i]]=distp[k]+1;
				Q[sizeQ++]=point[i];
			}
	return distp[dest]>=0;
}
int dinic_dfs(int x,int exp)
{
	if (x==dest) return exp;
	int res=0;
	for (int &i=work[x];i>=0;i=nextp[i])
	{
		int v=point[i],tmp;
		if (flow[i]<capa[i] && distp[v]==distp[x]+1 && (tmp=dinic_dfs(v,min(exp,capa[i]-flow[i])))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			res+=tmp;
			exp-=tmp;
			if (exp==0) break;
		}
	}
	return res;
}
int dinic_flow()
{
	int result=0;
	while (dinic_bfs())
	{
		for (int i=0;i<node;i++) work[i]=head[i];
		result+=dinic_dfs(src,oo);
	}
	return result;
}
bool g[maxsize][maxsize];
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>m)
	//for (int seed=0;;seed++)
	{
		//int pp=rand()%10+1; int qq=rand()%pp; srand(seed); m=0; REP(i,31) if (rand()%pp<qq) a[m++]=i; if (m==0) continue;
		REP(i,m) cin>>a[i];
		sort(a,a+m);
		memset(f,0,sizeof(f));
		best_n=100000000;
		r.clear();
		dfs2(0,0,0);
		if (best_n==100000000)
		{
			printf("=(\n");

			REP(i,m) printf("%d ",a[i]); printf("\n");
			exit(0);
		}
		else
		{
			r=best_r;
			int n=SIZE(r);
			printf("%d\n",n);
			init(n+n*n+2,n+n*n,n+n*n+1);
			REP(i,n) addedge(src,i,r[i],0);
			REP(i,n*n) addedge(n+i,dest,1,0);
			REP(i,n) FOR(j,i+1,n)
			{
				addedge(i,n+i*n+j,1,0);
				addedge(j,n+i*n+j,1,0);
			}
			dinic_flow();
			memset(g,false,sizeof(g));
			REP(i,n) FOR(j,i+1,n)
				for (int p=head[n+i*n+j];p>=0;p=nextp[p])
					if (flow[p]<0 && point[p]<n)
					{
						int x=point[p];
						int y=i+j-x;
						g[x][y]=true;
					}
			REP(i,n) REP(j,i) assert(g[i][j]!=g[j][i]);
			REP(i,n)
			{
				int c=0;
				REP(j,n) if (g[i][j]) ++c;
				assert(c==r[i]);
			}
			set<int> s1(ALL(r));
			set<int> s2(a,a+m);
			assert(s1==s2);
			REP(i,n)
			{
				REP(j,n) printf("%c",g[i][j]?'1':'0');
				printf("\n");
			}
		}
	}
	return 0;
}