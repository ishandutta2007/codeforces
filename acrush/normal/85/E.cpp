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

const int maxn=5000+5;
const int MODE=1000000007;

int n;
int x[maxn],y[maxn];
int minx,maxx,miny,maxy;

bool checkIt(int s,int x0,int y0)
{
	int minx=+100000000;
	int maxx=-100000000;
	int miny=+100000000;
	int maxy=-100000000;
	for (int i=0;i<n;i++)
		if (x[i]>=x0 && x[i]<=x0+s && y[i]>=y0 && y[i]<=y0+s)
			;
		else
		{
			checkmin(minx,x[i]);
			checkmax(maxx,x[i]);
			checkmin(miny,y[i]);
			checkmax(maxy,y[i]);
		}
	return maxx-minx<=s && maxy-miny<=s;
}
bool checkIt(int s)
{
	return checkIt(s,minx,miny) || checkIt(s,minx,maxy-s) || 
		   checkIt(s,maxx-s,miny) || checkIt(s,maxx-s,maxy-s);
}
int64 solve(int s)
{
	if (maxx-minx<=s && maxy-miny<=s)
	{
		int64 r=1;
		for (int i=0;i<n;i++)
			r=(r*2)%MODE;
		return r;
	}
	if (maxx-minx<=s)
	{
		for (int i=0;i<n;i++)
			swap(x[i],y[i]);
		swap(minx,miny);
		swap(maxx,maxy);
	}
	int64 R=0;
	for (int t=0;t<2;t++)
	{
		if (maxy-miny<=s && t==1)
			continue;
		int x1=minx;
		int y1=(t==0)?miny:(maxy-s);
		int x2=maxx-s;
		int y2=(t==0)?(maxy-s):miny;
		int64 S=1;
		for (int i=0;i<n;i++)
		{
			int g=0;
			if (x[i]>=x1 && x[i]<=x1+s && y[i]>=y1 && y[i]<=y1+s)
				g|=1;
			if (x[i]>=x2 && x[i]<=x2+s && y[i]>=y2 && y[i]<=y2+s)
				g|=2;
			if (g==0)
			{
				S=0;
				break;
			}
			if (g==3)
				S=(S*2)%MODE;
		}
		R=(R+S)%MODE;
	}
	return (R*2)%MODE;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		int a,b;
		scanf("%d%d",&a,&b);
		x[i]=a+b;
		y[i]=a-b;
	}
	minx=maxx=x[0];
	miny=maxy=y[0];
	for (int i=1;i<n;i++)
	{
		checkmin(minx,x[i]);
		checkmax(maxx,x[i]);
		checkmin(miny,y[i]);
		checkmax(maxy,y[i]);
	}
	int H=-1,T=1000000;
	for (;H+1<T;)
	{
		int M=H+(T-H)/2;
		if (checkIt(M))
			T=M;
		else
			H=M;
	}
	printf("%d\n",T);
	int64 R=solve(T);
	printf("%d\n",(int)(R%MODE));
	return 0;
}