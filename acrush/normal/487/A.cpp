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

int h1,a1,d1;
int h2,a2,d2;
int xh,xa,xd;

int solve(int a1,int d1,int a2,int d2,int h2)
{
	if (a1<=d2) return -1;
	int w=(h2+(a1-d2)-1)/(a1-d2);
	return w*max(0,a2-d1);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&h1,&a1,&d1);
	scanf("%d%d%d",&h2,&a2,&d2);
	scanf("%d%d%d",&xh,&xa,&xd);
	int ret=1000000000;
	for (int ca=0;ca<=200;ca++)
		for (int cd=0;cd<=101;cd++)
		{
			int t=solve(a1+ca,d1+cd,a2,d2,h2);
			if (t<0) continue;
			int ch=max(0,t-h1+1);
			checkmin(ret,ca*xa+cd*xd+ch*xh);
		}
	printf("%d\n",ret);
	return 0;
}