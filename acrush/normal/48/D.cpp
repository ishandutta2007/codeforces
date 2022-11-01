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

const int maxsize=100000+5;

int n;
vector<int> a[maxsize];
int r[maxsize];

int solve()
{
	int R=0;
	for (int k=maxsize-1;k>=0;k--)
		while (SIZE(a[k]))
		{
			R++;
			for (int i=k;i>=0;i--)
				if (SIZE(a[i])==0)
					return -1;
				else
				{
					r[a[i][SIZE(a[i])-1]]=R;
					a[i].pop_back();
				}
		}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		a[d-1].push_back(i);
	}
	int ret=solve();
	if (ret<0)
		printf("-1\n");
	else
	{
		printf("%d\n",ret);
		for (int i=0;i<n;i++)
		{
			if (i>0) printf(" ");
			printf("%d",r[i]);
		}
		printf("\n");
	}
	return 0;
}