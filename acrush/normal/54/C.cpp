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

const int maxn=1000+5;

int n,m;
double p[maxn];
double f[maxn];

int64 solve(int64 n)
{
	if (n==0) return 0;
	int64 p=1,R=0;
	while (p<=n)
	{
		R+=min(n,2*p-1)-p+1;
		if (p>n/10) break;
		p*=10;
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int64 a,b;
		cin>>a>>b;
		p[i]=(double)(solve(b)-solve(a-1))/(double)(b-a+1);
	}
	cin>>m;
	memset(f,0,sizeof(f));
	f[0]=1;
	for (int k=0;k<n;k++)
	{
		double key=p[k];
		for (int i=n;i>=0;i--)
		{
			f[i]*=(1-key);
			if (i>0) f[i]+=f[i-1]*key;
		}
	}
	double R=0;
	for (int i=0;i<=n;i++)
		if (i*100>=n*m)
			R+=f[i];
	printf("%.18lf\n",R);
	return 0;
}