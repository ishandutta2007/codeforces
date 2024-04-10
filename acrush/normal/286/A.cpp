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

int p[1<<20];

int main()
{
	int n;
	scanf("%d",&n);
	if (n%4==2 || n%4==3) 
		printf("-1\n");
	else
	{
		for (int i=0;i<n/2;i+=2)
		{
			p[i]=i+1;
			p[i+1]=n-1-i;
			p[n-1-i]=n-2-i;
			p[n-2-i]=i;
		}
		if (n%4==1) p[n/2]=n/2;		
		for (int i=0;i<n;i++)
		{
			if (i>0) printf(" ");
			printf("%d",p[i]+1);
		}
		printf("\n");
	}
	return 0;
}