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

long double logp[1000000];
long double c[1024][1024];
long double g[1000000];

long double logc(int n,int m)
{
	if (m<0 || m>n) { printf("ERROR\n"); return -1; }
	return logp[n]-logp[n-m]-logp[m];
}
int main()
{
	logp[0]=0;
	for (int i=1;i<1000000;i++) logp[i]=logp[i-1]+log((long double)i);
	memset(c,0,sizeof(c));
	for (int i=0;i<1024;i++) for (int j=0;j<=i;j++) c[i][j]=((j==0)?1:c[i-1][j-1]+c[i-1][j]);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	double ret=0;
	double limit=110*log(10.0);
	g[0]=1;
	for (int d=1;d<=n*n;d++) if (d<=k) g[d]=g[d-1]*(double)(k-d+1)/(double)(m-d+1);
	for (int c1=0;c1<=n;c1++) for (int c2=0;c2<=n;c2++)
	{
		int d=(c1+c2)*n-c1*c2;
		if (d>k) continue;
		long double t=logc(n,c1)+logc(n,c2)+logc(m-d,k-d)-logc(m,k);
		if (t>limit)
		{
			printf("1e99\n");
			return 0;
		}
		long double p=c[n][c1]*c[n][c2]*g[d];
		ret+=p;
	}
	if (ret>1e99)
		printf("1e99\n");
	else
		printf("%.18e\n",ret);
	return 0;
}