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

const int maxn=1000000+16;

int n;
int p[maxn];
int d[maxn];
int f[maxn][20];

int lca(int a,int b)
{
	if (d[a]>d[b]) swap(a,b);
	if (d[b]>d[a])
	{
		int e=d[b]-d[a];
		for (int w=0;w<20;w++) if (contain(e,w)) b=f[b][w];
	}
	if (a==b) return a;
	int h=d[a]-1;
	for (int w=19;w>=0;w--) if (contain(h,w))
	{
		int pa=f[a][w];
		int pb=f[b][w];
		if (pa==pb)
			h=two(w)-1;
		else
		{
			h-=two(w);
			a=pa;
			b=pb;
		}
	}
	return f[a][0];
}
int calc(int a,int b)
{
	int c=lca(a,b);
	return d[a]+d[b]-d[c]-d[c];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int q;
	scanf("%d",&q);
	n=4;
	p[0]=-1;
	p[1]=p[2]=p[3]=0;
	for (int i=0;i<q;i++)
	{
		int v;
		scanf("%d",&v);
		p[n++]=v-1;
		p[n++]=v-1;
	}
	d[0]=0;
	for (int i=1;i<n;i++) d[i]=d[p[i]]+1;
	for (int i=1;i<n;i++)
	{
		f[i][0]=p[i];
		for (int w=1;two(w)<=d[i];w++) f[i][w]=f[f[i][w-1]][w-1];
	}
	int ret=2,r1=1,r2=2;
	for (int i=4;i<n;i++)
	{
		int d1=calc(i,r1);
		int d2=calc(i,r2);
		if (d1>=d2 && d1>ret)
			ret=d1,r2=i;
		else if (d2>=d1 && d2>ret)
			ret=d2,r1=i;
		if (i&1) printf("%d\n",ret);
	}
	return 0;
}