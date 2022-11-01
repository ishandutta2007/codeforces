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

int main()
{
	int n;
	int a[512];
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (;a[0]>0;a[0]--) printf("PRL");
	for (int i=0;i<n-1;i++) printf("R");
	for (;a[n-1]>0;a[n-1]--) printf("PLR");
	int p=n-1,dx=-1;
	while (1)
	{
		bool ok=true;
		for (int i=0;i<n;i++) if (a[i]>0) ok=false;
		if (ok) break;
		if (a[p]>0) { a[p]--; printf("P"); }
		if (dx==-1 && p==0 || dx==1 && p==n-1) dx=-dx;
		p+=dx;
		if (dx<0) printf("L");
		else printf("R");
	}
	printf("\n");
	return 0;
}