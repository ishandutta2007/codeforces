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

int n;
int64 a[maxn],s[maxn];
int64 f[maxn];

int64 solve(int m)
{
	if (f[m]>=0) return f[m];
	int64 &ret=f[m];
	ret=0;
	for (int64 p=0,x=0,d=1;p<n;d*=m,x++)
	{
		int64 e=min((int64)n,p+d);
		ret+=x*(s[e]-s[p]);
		p=e;
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	reverse(a,a+n);
	s[0]=0;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i-1];
	memset(f,255,sizeof(f));
	int nq;
	scanf("%d",&nq);
	for (int i=0;i<nq;i++)
	{
		int k;
		scanf("%d",&k);
		if (i>0) printf(" ");
		printf("%I64d",solve(k));
	}
	printf("\n");
	return 0;
}