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

const int maxsize=100+5;

int n,m;
int a[maxsize][maxsize],sx[maxsize],sy[maxsize];
int x[maxsize],y[maxsize];

void show(int n,int x[])
{
	int c=0;
	for (int i=0;i<n;i++) if (x[i]) c++;
	printf("%d",c);
	for (int i=0;i<n;i++) if (x[i]) printf(" %d",i+1);
	printf("\n");
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(sx,0,sizeof(sx));
	memset(sy,0,sizeof(sy));
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) { sx[i]+=a[i][j]; sy[j]+=a[i][j]; }
	while (1)
	{
		bool ok=true;
		for (int i=0;i<n;i++) if (sx[i]<0)
		{
			ok=false;
			sx[i]=-sx[i];
			x[i]^=1;
			for (int j=0;j<m;j++) { a[i][j]=-a[i][j]; sy[j]+=(a[i][j]<<1); }
		}
		for (int j=0;j<m;j++) if (sy[j]<0)
		{
			ok=false;
			sy[j]=-sy[j];
			y[j]^=1;
			for (int i=0;i<n;i++) { a[i][j]=-a[i][j]; sx[i]+=(a[i][j]<<1); }
		}
		if (ok) break;
	}
	show(n,x);
	show(m,y);
	return 0;
}