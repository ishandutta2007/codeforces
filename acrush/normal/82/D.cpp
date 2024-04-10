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

const int maxn=1000+5;

int n;
int a[maxn];
int f[maxn][maxn];

int solve(int d,int p)
{
	if (d>=n)
		return a[p];
	if (d==n-1)
		return max(a[p],a[n-1]);
	int &ret=f[d][p];
	if (ret>=0)
		return ret;
	ret=2000000000;
	checkmin(ret,solve(d+2,d+1)+max(a[p],a[d]));
	checkmin(ret,solve(d+2,d)+max(a[p],a[d+1]));
	checkmin(ret,solve(d+2,p)+max(a[d],a[d+1]));
	return ret;
}
void construct(int d,int p)
{
	if (d>=n)
	{
		printf("%d\n",p+1);
		return;
	}
	if (d==n-1)
	{
		printf("%d %d\n",p+1,n);
		return;
	}
	int ret=solve(d,p);
	if (ret==solve(d+2,d+1)+max(a[p],a[d]))
	{
		printf("%d %d\n",p+1,d+1);
		construct(d+2,d+1);
		return;
	}
	if (ret==solve(d+2,d)+max(a[p],a[d+1]))
	{
		printf("%d %d\n",p+1,d+2);
		construct(d+2,d);
		return;
	}
	if (ret==solve(d+2,p)+max(a[d],a[d+1]))
	{
		printf("%d %d\n",d+1,d+2);
		construct(d+2,p);
		return;
	}
	return;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	memset(f,255,sizeof(f));
	int R=solve(1,0);
	printf("%d\n",R);
	construct(1,0);
	return 0;
}