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

int n;
int a[100000];

void solve(int m,int t)
{
	for (int i=0;i<n;i++)
	{
		if (i>=m) checkmax(a[i],a[i-m]);
		a[i]+=t;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int n1,n2,n3,t1,t2,t3;
	cin>>n>>n1>>n2>>n3>>t1>>t2>>t3;
	for (int i=0;i<n;i++) a[i]=0;
	solve(n1,t1);
	solve(n2,t2);
	solve(n3,t3);
	int r=0;
	for (int i=0;i<n;i++) if (a[i]>r) r=a[i];
	printf("%d\n",r);
	return 0;
}