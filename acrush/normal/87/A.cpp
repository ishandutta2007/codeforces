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
	int64 a,b,ca=0,cb=0;
	cin>>a>>b;
	for (int64 s=0;s<a*b;)
	{
		int64 sa=(s/a+1)*a;
		int64 sb=(s/b+1)*b;
		if (sa<sb) 
			ca+=sa-s,s=sa;
		else if (sb<sa)
			cb+=sb-s,s=sb;
		else 
		{
			if (a>b) ca+=sa-s;
			else cb+=sb-s;
			s=sa;
		}
	}
	if (ca>cb)
		printf("Dasha\n");
	else if (cb>ca)
		printf("Masha\n");
	else
		printf("Equal\n");
	return 0;
}