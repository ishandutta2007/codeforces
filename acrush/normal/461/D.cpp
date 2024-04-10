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

const int MOD=1000000007;

#define MUL(a,b) ((int)((int64)(a)*(int64)(b)%(MOD)))

const int maxn=100000+16;

int n,m;
int x[maxn],y[maxn],p[maxn];
int f[maxn],g[maxn];

int getfather(int p)
{
	if (f[p]<0) return p;
	int t=getfather(f[p]);
	g[p]^=g[f[p]];
	return f[p]=t;
}
bool mergef(int a,int b,int d)
{
	int pa=getfather(a);
	int pb=getfather(b);
	if (pa==pb) return (g[a]^g[b])==d;
	f[pa]=pb;
	g[pa]=(g[a]^g[b]^d);
	return true;
}
int solve(int e)
{
	for (int i=0;i<(n-e)+1;i++) f[i]=-1,g[i]=0;
	for (int i=0;i<(n-e);i++) if (!mergef(i,(n-e)-1-i,0)) return 0;
	for (int i=0;i<m;i++) if (abs(x[i]-y[i])%2==e)
	{
		int x0=min(x[i],y[i]),y0=max(x[i],y[i]);
		if (e==0)
		{
			if (x0==y0)
			{
				if (!mergef(x0,n-e,p[i])) return 0;
			}
			else
			{
				if (!mergef((y0-x0)/2-1,(x0+y0)/2,p[i])) return 0;
			}
		}
		else
		{
			if (x0+1==y0)
			{
				if (!mergef(x0,n-e,p[i])) return 0;
			}
			else
			{
				if (!mergef((y0-x0)/2-1,(x0+y0)/2,p[i])) return 0;
			}
		}
	}
	int c=0;
	for (int i=0;i<(n-e)+1;i++) if (f[i]<0) c++;
	int r=1;
	for (int i=0;i<c-1;i++) r=MUL(r,2);
	return r;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) 
	{
		char s[16];
		scanf("%d%d%s",&x[i],&y[i],s);
		x[i]--;
		y[i]--;
		p[i]=(int)(s[0]=='o');
	}
	int r1=solve(0);
	int r2=solve(1);
	int ret=MUL(r1,r2);
	printf("%d\n",ret);
	return 0;
}