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

int n;
double p[105];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<=n;i++) scanf("%lf",&p[i]);
	double R=0;
	for (int i=0;i<=n/2;i++) checkmax(R,p[i]);
	for (int i=0;i<=n;i++) for (int j=i+1;j<=n;j++)
	{
		double a1=1,b1=1,c1=-1;
		double a2=2*i,b2=2*j,c2=-n;
		double t=a1*b2-a2*b1;
		double x=+(b1*c2-b2*c1)/t;
		double y=-(a1*c2-a2*c1)/t;
		if (x>=0 && y>=0)
			checkmax(R,x*p[i]+y*p[j]);
	}
	printf("%.18lf\n",R);
	return 0;
}