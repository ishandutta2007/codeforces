#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=128;

const int maxnode=20000+5;
const int maxedge=100000+5;
const int oo=100000000;

int node,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],Q[maxnode],work[maxnode];

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
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,next[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,next[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	for (int i=0;i<node;i++) dist[i]=-1;
	dist[src]=0;
	int sizeQ=0;
	Q[sizeQ++]=src;
	for (int cl=0;cl<sizeQ;cl++)
		for (int k=Q[cl],i=head[k];i>=0;i=next[i])
			if (flow[i]<capa[i] && dist[point[i]]<0)
			{
				dist[point[i]]=dist[k]+1;
				Q[sizeQ++]=point[i];
			}
	return dist[dest]>=0;
}
int dinic_dfs(int x,int exp)
{
	if (x==dest) return exp;
	int res=0;
	for (int &i=work[x];i>=0;i=next[i])
	{
		int v=point[i],tmp;
		if (flow[i]<capa[i] && dist[v]==dist[x]+1 && (tmp=dinic_dfs(v,min(exp,capa[i]-flow[i])))>0)
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

int n,m;
int a[maxn];
int e1[maxn],e2[maxn];
set<int> S;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d%d",&e1[i],&e2[i]);
	for (int i=0;i<m;i++) e1[i]--,e2[i]--;
	for (int i=0;i<m;i++) if (e2[i]&1) swap(e1[i],e2[i]);
	for (int i=0;i<n;i++)
	{
		int key=a[i];
		for (int k=2;key>1;)
		{
			if (key%k==0)
			{
				S.insert(k);
				for (;key%k==0;key/=k);
			}
			if (k==2) k++; else k+=2;
			if (k*k>key) k=key;
		}
	}
	int ret=0;
	for (set<int>::iterator it=S.begin();it!=S.end();++it)
	{
		int key=*it;
		init(n+2,n,n+1);
		for (int i=0;i<n;i++)
		{
			int c=0;
			for (int w=a[i];w%key==0;w/=key) c++;
			if (i&1)
				addedge(src,i,c,0);
			else
				addedge(i,dest,c,0);
		}
		for (int i=0;i<m;i++) addedge(e1[i],e2[i],100000,0);
		ret+=dinic_flow();
	}
	printf("%d\n",ret);
	return 0;
}