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

const int maxc=200+5;
const int maxn=maxc*maxc;

int a,b,m;
int ca,ga[maxc],ha[maxc];
int cb,gb[maxc],hb[maxc];
int n,id[maxc][maxc];
vector<int> g[maxn],rg[maxn];
int q[maxn],d[maxn],sizeq,h[maxn];

bool DFS(int v)
{
	d[v]=1;
	for (int i=SIZE(g[v])-1;i>=0;i--)
	{
		int other=g[v][i];
		if (d[other]==1) return true;
		if (d[other]==0 && DFS(other)) return true;
	}
	d[v]=2;
	return false;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&a,&b,&m);
	scanf("%d",&ca);
	for (int i=1;i<=ca;i++) scanf("%d%d",&ga[i],&ha[i]);
	scanf("%d",&cb);
	for (int i=1;i<=cb;i++) scanf("%d%d",&gb[i],&hb[i]);
	n=0;
	for (int i=0;i<=m;i++) for (int j=0;i+j<=m;j++) id[i][j]=(n++);
	for (int i=0;i<=m;i++) for (int j=0;i+j<=m;j++)
	{
		int s=id[i][j];
		for (int k=1;k<=ca;k++) if (i>=k)
		{
			int a=i-k+ga[k];
			int b=j+ha[k];
			if (a+b<=m) g[s].push_back(id[a][b]);
			g[s].push_back(n);
		}
		for (int k=1;k<=cb;k++) if (j>=k)
		{
			int a=i+gb[k];
			int b=j-k+hb[k];
			if (a+b<=m) g[s].push_back(id[a][b]);
			else g[s].push_back(n);
		}
	}
	n++;
	for (int i=0;i<n;i++) for (int j=SIZE(g[i])-1;j>=0;j--) rg[g[i][j]].push_back(i);
	int src=id[a][b];
	memset(d,255,sizeof(d));
	sizeq=0;
	d[0]=0;
	q[sizeq++]=0;
	for (int cl=0;cl<sizeq;cl++) for (int key=q[cl],i=SIZE(rg[key])-1;i>=0;i--)
	{
		int other=rg[key][i];
		if (d[other]<0) d[other]=d[key]+1,q[sizeq++]=other;
	}
	if (d[src]>=0)
	{
		printf("Ivan\n");
		printf("%d\n",d[src]);
		return 0;
	}
	memset(d,0,sizeof(d));
	if (DFS(src))
		printf("Draw\n");
	else
	{
		memset(d,0,sizeof(d));
		for (int i=0;i<n;i++) d[i]=SIZE(g[i]);
		sizeq=0;
		for (int i=0;i<n;i++) if (d[i]==0)
		{
			q[sizeq++]=i;
			h[i]=(i==n-1)?0:-1000000;
		}
		for (int cl=0;cl<sizeq;cl++) for (int key=q[cl],i=SIZE(rg[key])-1;i>=0;i--)
		{
			int other=rg[key][i];
			if ((--d[other])==0)
			{
				q[sizeq++]=other;
				h[other]=-1000000;
				for (int j=SIZE(g[other])-1;j>=0;j--) checkmax(h[other],h[g[other][j]]+1);
			}
		}
		printf("Zmey\n");
		printf("%d\n",h[src]);
	}
	return 0;
}