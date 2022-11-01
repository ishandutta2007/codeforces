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

const int maxsize=1000+5;

int n,m,c,a[maxsize],b[maxsize];

double S1(int n)
{
	return n*(n+1)/2;
}
double calc1(int n,int p)
{
	return S1(p)+S1(n-1-p);
}
double calc2(int n,int a[],int m)
{
	double R=0;
	for (int i=0;i<n;i++) if (a[i]>=0)
	{
		R+=a[i]*(m-1-a[i]);
		bool g1=true,g2=true;
		for (int j=i+1;j<n && a[j]>=0;j++)
		{
			if (a[j]<a[j-1]) g1=false;
			if (a[j]>a[j-1]) g2=false;
			if (g1) R+=a[i]*(m-1-a[j]);
			if (g2) R+=(m-1-a[i])*a[j];
		}
	}
	return R*4;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	memset(a,255,sizeof(a));
	memset(b,255,sizeof(b));
	c=0;
	double r1=0,r2=0;
	for (int i=0;i<n;i++)
	{
		char s[1024];
		scanf("%s",s);
		for (int j=0;j<m;j++) 
			if (s[j]=='X') 
			{
				a[i]=j;
				b[j]=i;
				c++;
				r1+=n*calc1(m,j)+m*calc1(n,i);
			}
			else
				r2+=n*calc1(m,j)+m*calc1(n,i);
	}
	double r3=0;
	for (int i=0;i<n;i++) if (a[i]>=0)
		for (int j=0;j<n;j++) if (a[j]>=0)
			r3+=abs(i-j)+abs(a[i]-a[j]);
	double r4=calc2(n,a,m);
	double r5=calc2(m,b,n);
	double result=r2-r1+r3+r4+r5;
	c=n*m-c;
	printf("%.18lf\n",result/c/c);
	return 0;
}