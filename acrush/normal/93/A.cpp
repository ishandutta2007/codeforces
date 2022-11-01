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

int solve(int n,int width,int s,int t)
{
	s--;
	t--;
	if (s/width==t/width) return 1;
	if (s%width==0 && ((t+1)%width==0 || t==n-1)) return 1;
	if (s%width==0) return 2;
	if ((t+1)%width==0 || t==n-1) return 2;
	if (s%width==t%width+1) return 2;
	if (s/width+1==t/width) return 2;
	return 3;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int n,width,s,t;
	scanf("%d%d%d%d",&n,&width,&s,&t);
	int ret=solve(n,width,s,t);
	printf("%d\n",ret);
	return 0;
}