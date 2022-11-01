#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

const int oo=1050000000;
const int maxn=1000+5;

int n,m,src,dest;
int d[maxn][maxn];
int64 e[maxn];
vector<ipair> g[maxn],h[maxn];
int heapsize,heap[maxn],arc[maxn];

void update(int d[],int p,int key)
{
	if (key>=d[p]) return;
	d[p]=key;
	int i=arc[p];
	for (int j=(i-1)>>1;i>0;i=j,j=(i-1)>>1)
		if (key<d[heap[j]])
			arc[heap[i]=heap[j]]=i;
		else
			break;
	arc[heap[i]=p]=i;
}
void heap_down(int i,int d[])
{
	int p=heap[i];
	int key=d[p];
	for (int j=(i<<1)+1;j<heapsize;i=j,j=(i<<1)+1)
	{
		if (j+1<heapsize && d[heap[j+1]]<d[heap[j]]) j++;
		if (d[heap[j]]<key)
			arc[heap[i]=heap[j]]=i;
		else
			break;
	}
	arc[heap[i]=p]=i;
}
void dijkstra(int src,int d[],vector<ipair> g[])
{
	heapsize=n;
	for (int i=0;i<n;i++) heap[i]=i,d[i]=oo,arc[i]=i;
	update(d,src,0);
	while (heapsize>0)
	{
		int pos=heap[0];
		int dst=d[pos];
		heap[0]=heap[--heapsize];
		if (heapsize>0) heap_down(0,d);
		for (int i=SIZE(g[pos])-1;i>=0;i--)
		{
			int new_pos=g[pos][i].first;
			int new_dst=dst+g[pos][i].second;
			update(d,new_pos,new_dst);
		}
	}
}

void dijkstra2(int src,int64 d[],vector<ipair> g[])
{
	for (int i=0;i<n;i++) d[i]=(int64)oo*oo;
	bool visited[maxn];
	for (int i=0;i<n;i++) visited[i]=false;
	d[src]=0;
	while (1)
	{
		int k=-1;
		for (int i=0;i<n;i++) if (!visited[i] && (k<0 || d[i]<d[k])) k=i;
		if (k<0 || d[k]>=(int64)oo*oo) break;
		visited[k]=true;
		for (int i=SIZE(g[k])-1;i>=0;i--)
		{
			int new_pos=g[k][i].first;
			int64 new_dst=d[k]+g[k][i].second;
			if (new_dst<d[new_pos]) d[new_pos]=new_dst;
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&src,&dest);
	src--;
	dest--;
	for (int i=0;i<n;i++) g[i].clear();
	for (int i=0;i<m;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		a--;
		b--;
		g[a].push_back(MP(b,w));
		g[b].push_back(MP(a,w));
	}
	for (int i=0;i<n;i++) dijkstra(i,d[i],g);
	for (int i=0;i<n;i++) h[i].clear();
	for (int i=0;i<n;i++)
	{
		int t,c;
		scanf("%d%d",&t,&c);
		for (int j=0;j<n;j++) if (d[i][j]<=t) h[i].push_back(MP(j,c));
	}
	dijkstra2(src,e,h);
	int64 R=e[dest];
	if (R>=(int64)oo*oo) R=-1;
	cout<<R<<endl;
	return 0;
}