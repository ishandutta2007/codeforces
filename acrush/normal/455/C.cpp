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

const int maxn=300000+16;

int n,m,q;
vector<int> g[maxn];
int f[maxn],l[maxn];
int target,longest;

int dfs(int p)
{
	if (p!=target) f[p]=target;
	l[p]=0;
	int d1=0,d2=0;
	for (int i=0;i<SIZE(g[p]);i++)
		if (l[g[p][i]]<0)
		{
			int t=dfs(g[p][i])+1;
			if (t>d1) d2=d1,d1=t;
			else if (t>d2) d2=t;
		}
	checkmax(longest,d1+d2);
	return d1;
}
int getf(int p)
{
	return (f[p]<0)?p:(f[p]=getf(f[p]));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(l,255,sizeof(l));
	memset(f,255,sizeof(f));
	for (int i=0;i<n;i++) if (l[i]<0)
	{
		target=i;
		longest=0;
		dfs(i);
		l[i]=longest;
	}
	for (;q>0;q--)
	{
		int t,a,b;
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d",&a);
			a--;
			a=getf(a);
			printf("%d\n",l[a]);
		}
		else
		{
			scanf("%d%d",&a,&b);
			a--;
			b--;
			a=getf(a);
			b=getf(b);
			if (a!=b)
			{
				f[a]=b;
				checkmax(l[b],max(l[a],(l[b]+1)/2+1+(l[a]+1)/2));
			}
		}
	}
	return 0;
}