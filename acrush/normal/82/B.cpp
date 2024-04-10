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

int n,k,a[205];
int c[205][205],g[205];
bool visited[205];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	if (n==2)
	{
		int p;
		scanf("%d",&k);
		scanf("%d",&p);
		printf("1 %d\n",p);
		printf("%d",k-1);
		for (int i=0;i<k-1;i++)
		{
			scanf("%d",&p);
			printf(" %d",p);
		}
		printf("\n");
		return 0;
	}
	memset(c,0,sizeof(c));
	memset(g,0,sizeof(g));
	for (int s=0;s<n*(n-1)/2;s++)
	{
		scanf("%d",&k);
		for (int i=0;i<k;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<k;i++)
			g[a[i]]++;
		for (int i=0;i<k;i++)
			for (int j=0;j<k;j++)
				c[a[i]][a[j]]++;
	}
	memset(visited,false,sizeof(visited));
	for (int i=0;i<205;i++)
		if (g[i]>0 && !visited[i])
		{
			k=0;
			for (int j=0;j<205;j++)
				if (!visited[j] && c[i][j]==n-1)
				{
					visited[j]=true;
					a[k++]=j;
				}
			printf("%d",k);
			for (int j=0;j<k;j++)
				printf(" %d",a[j]);
			printf("\n");
		}
	return 0;
}