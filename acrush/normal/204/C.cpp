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

const int maxn=1000000+5;

int n;
char a[maxn],b[maxn];
double s1[maxn],s2[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("C.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	double R=0;
	double S=0;
	for (int D=0;D<=n-1;D++) S+=(double)(n-D)*(double)(n-D);
	for (int step=0;step<2;step++)
	{
		for (char key='A';key<='Z';key++)
		{
			s1[0]=s2[0]=0;
			for (int i=1;i<=n;i++)
				if (a[i]==key)
				{
					s1[i]=s1[i-1]+1;
					s2[i]=s2[i-1]+i;
				}
				else
					s1[i]=s1[i-1],s2[i]=s2[i-1];
			for (int i=1;i<=n;i++) if (b[i]==key) R+=(double)i*((double)(n+1)*(s1[n]-s1[i])-(s2[n]-s2[i]));
		}
		for (int i=1;i<=n;i++) swap(a[i],b[i]);
	}
	for (int i=1;i<=n;i++) if (a[i]==b[i]) R+=(double)i*(n+1-i);
	printf("%.18lf\n",R/S);
	return 0;
}