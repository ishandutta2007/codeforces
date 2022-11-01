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
	int n,m;
	scanf("%d%d",&n,&m);
	set<ipair> pts;
	for (int x=0;x<4;x++) for (int y=0;x+y<4;y++) if (x<=n && y<=m)
	{
		pts.insert(make_pair(x,y));
		pts.insert(make_pair(n-x,y));
		pts.insert(make_pair(x,m-y));
		pts.insert(make_pair(n-x,m-y));
	}
	int c=0;
	int x[128],y[128];
	for (set<ipair>::iterator it=pts.begin();it!=pts.end();++it)
	{
		x[c]=it->first;
		y[c++]=it->second;
	}
	double d[128][128];
	for (int i=0;i<c;i++) for (int j=0;j<c;j++) d[i][j]=sqrt((double)sqr(x[i]-x[j])+sqr(y[i]-y[j]));
	double r=-1;
	int r1,r2,r3,r4;
	for (int p1=0;p1<c;p1++) for (int p2=0;p2<c;p2++) if (p1!=p2)
		for (int p3=0;p3<c;p3++) if (p1!=p3 && p2!=p3)
			for (int p4=0;p4<c;p4++) if (p1!=p4 && p2!=p4 && p3!=p4)
			{
				double t=d[p1][p2]+d[p2][p3]+d[p3][p4];
				if (t>r) r=t,r1=p1,r2=p2,r3=p3,r4=p4;
			}
	printf("%d %d\n",x[r1],y[r1]);
	printf("%d %d\n",x[r2],y[r2]);
	printf("%d %d\n",x[r3],y[r3]);
	printf("%d %d\n",x[r4],y[r4]);
	return 0;
}