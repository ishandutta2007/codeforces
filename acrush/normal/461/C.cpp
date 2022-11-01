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

const int maxn=100000+16;

int n,q;
int s[maxn];
int a[maxn];

void add(int p,int key)
{
	a[p]+=key;
	for (int i=p+1;i<=n;i=(i|(i-1))+1) s[i]+=key;
}
int getsum(int i)
{
	int r=0;
	for (;i>0;i&=(i-1)) r+=s[i];
	return r;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) s[i]=0;
	for (int i=0;i<n;i++) a[i]=0;
	for (int i=0;i<n;i++) add(i,1);
	int src=0,dst=n-1,reversed=0;
	for (;q>0;q--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int p;
			scanf("%d",&p);
			if (reversed) p=dst-src+1-p;
			if (p<=(dst-src+1)/2)
			{
				for (int i=src;i<src+p;i++) add((src+p)*2-1-i,a[i]);
				src+=p;
				reversed=0;
			}
			else
			{
				for (int i=src+p;i<=dst;i++) add((src+p)*2-1-i,a[i]);
				dst=src+p-1;
				reversed=1;
			}
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if (reversed) { a=dst-src+1-a,b=dst-src+1-b; swap(a,b); }
			printf("%d\n",getsum(src+b)-getsum(src+a));
		}
	}
	return 0;
}