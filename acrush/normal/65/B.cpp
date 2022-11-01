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

const int L=1000;
const int H=2011;
const int maxn=1000+5;

int n,a[maxn];

int calc(int a,int b)
{
	int c=0;
	for (int i=0;i<4;i++,a/=10,b/=10) if (a%10!=b%10) c++;
	return c;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int key=L;
	for (int i=0;i<n;i++)
	{
		for (;key<=H && calc(key,a[i])>1;key++);
		if (key>H)
		{
			printf("No solution\n");
			return 0;
		}
		a[i]=key;
	}
	for (int i=0;i<n;i++) printf("%d\n",a[i]);
	return 0;
}