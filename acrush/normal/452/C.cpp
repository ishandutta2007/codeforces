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

int n,m;
double c[1024][1024];
double f[1024],g[1024];
int c1,c2;
double a1[100000],a2[100000];

int main()
{
	memset(c,0,sizeof(c));
	for (int i=0;i<1024;i++) for (int j=0;j<=i;j++) c[i][j]=((j==0)?1:c[i-1][j-1]+c[i-1][j]);
	scanf("%d%d",&n,&m);
	double ret=0;
	for (int k=0;k<=m && k<=n;k++) if (n*m-m>=n-k)
	{
		c1=c2=0;
		for (int i=n;i>n-k;i--) a1[c1++]=i;
		for (int i=n*m-n;i>n*m-m-n+k;i--) a1[c1++]=i;
		for (int i=n*m;i>n*m-m;i--) a2[c2++]=i;
		double t=c[m][k]*k*k;
		for (int i=0,j=0;i<c1 || j<c2;)
			if (j==c2 || i<c1 && t<1) t*=a1[i++];
			else t/=a2[j++];
		ret+=t;
	}
	printf("%.18lf\n",ret/n);
	return 0;
}