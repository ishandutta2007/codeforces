#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

bool solve(int64 x1,int64 y1,int64 x2,int64 y2,int64 x3,int64 y3)
{
	if (x2==0 && y2==0) return (x1==x3 && y1==y3);
	int64 a1=x2;
	int64 b1=-y2;
	int64 c1=x1-x3;
	int64 a2=y2;
	int64 b2=x2;
	int64 c2=y1-y3;
	int64 t=a1*b2-a2*b1;
	int64 x=+(b1*c2-b2*c1)/t;
	int64 y=-(a1*c2-a2*c1)/t;
	if (a1*x+b1*y+c1==0 && a2*x+b2*y+c2==0) return true;
	return false;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int64 x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x3>>y3>>x2>>y2;
	for (int s=0;s<4;s++)
	{
		if (solve(x1,y1,x2,y2,x3,y3))
		{
			printf("YES\n");
			return 0;
		}
		swap(x1,y1);
		x1=-x1;
	}
	printf("NO\n");
	return 0;
}