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

const int maxn=100000+5;

int n,sg[maxn],xsg[maxn];

int main()
{
	scanf("%d",&n);
	sg[0]=0;
	xsg[0]=0;
	for (int i=1;i<=n;i++)
	{
		set<int> visited;
		for (int j=2;j*(j+1)/2<=i;j++)
			if ((i-j*(j+1)/2)%j==0)
			{
				int k=(i-j*(j+1)/2)/j;
				visited.insert(xsg[k+j]^xsg[k]);
			}
		for (sg[i]=0;visited.find(sg[i])!=visited.end();sg[i]++);
		xsg[i]=xsg[i-1]^sg[i];
	}
	for (int j=2;j*(j+1)/2<=n;j++)
		if ((n-j*(j+1)/2)%j==0)
		{
			int k=(n-j*(j+1)/2)/j;
			int g=xsg[k+j]^xsg[k];
			if (g==0)
			{
				printf("%d\n",j);
				return 0;
			}
		}
	printf("-1\n");
	return 0;
}