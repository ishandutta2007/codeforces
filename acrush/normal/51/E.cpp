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

const int maxn=700+5;

int n,m;
bool g[maxn][maxn];
int64 f[6][maxn][maxn];

void dynamic()
{
	memset(f,0,sizeof(f));
	for (int k=0;k<n;k++) f[0][k][k]=1;
	for (int step=0;step<5;step++) for (int i=0;i<n;i++) 
	{
		int64 *p1=f[step][i],*p2=f[step+1][i];
		for (int j=0;j<n;j++) if (p1[j])
			for (int k=0;k<n;k++) if (g[j][k])
				p2[k]+=p1[j];
	}
}
int64 solve0()
{
	int64 R=0;
	for (int k=0;k<n;k++) R+=f[5][k][k];
	return R;
}
int64 solve1()
{
	int64 R=0;
	for (int k=0;k<n;k++) R+=f[2][k][k]*f[3][k][k];
	return R;
}
int64 solve2()
{
	int64 R=0;
	for (int k=0;k<n;k++) R+=f[3][k][k];
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	memset(g,false,sizeof(g));
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		g[a][b]=g[b][a]=true;
	}
	if (n<5)
	{
		printf("0\n");
		return 0;
	}
	dynamic();
	int64 r0=solve0();
	int64 r1=solve1();
	int64 r2=solve2();
	int64 total=r0-r1*5+r2*5;
	total/=10;
	cout<<total<<endl;
	return 0;
}