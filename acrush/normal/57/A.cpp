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

int solve(int n,int x,int y)
{
	if (x==0) return y;
	if (y==n) return n+x;
	if (x==n) return n+n+(n-y);
	return n+n+n+(n-x);
}
int main()
{
	int n,x1,y1,x2,y2;
	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	int p1=solve(n,x1,y1);
	int p2=solve(n,x2,y2);
	int d=abs(p1-p2);
	checkmin(d,n*4-d);
	printf("%d\n",d);
	return 0;
}