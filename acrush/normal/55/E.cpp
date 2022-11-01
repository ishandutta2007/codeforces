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

const int maxn=100000+5;

#define next(x) (((x)==n-1)?0:((x)+1))

int n,x[maxn],y[maxn];

int cross(int x0,int y0,int x1,int y1,int x2,int y2)
{
	int64 t=(int64)(x1-x0)*(y2-y0)-(int64)(x2-x0)*(y1-y0);
	if (t==0) return 0;
	return (t<0)?-1:1;
}
int64 solve(int x0,int y0)
{
	for (int i=0;i<n;i++) if (cross(x[i],y[i],x[i+1],y[i+1],x0,y0)>0) return 0;
	int64 R=0;
	for (int k=1,i=0;i<n;i++)
	{
		if (k==i) k=next(k);
		for (;cross(x[i],y[i],x[next(k)],y[next(k)],x0,y0)<0;k=next(k));
		int c=(k>i)?(k-i):(k+n-i);
		R+=(int64)c*(c-1)/2;
		c=n-1-c;
		R+=(int64)c*(c-1)/2;
	}
	R/=2;
	return (int64)n*(n-1)*(n-2)/6-R;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		int x0,y0;
		scanf("%d%d",&x0,&y0);
		cout<<solve(x0,y0)<<endl;
	}
	return 0;
}