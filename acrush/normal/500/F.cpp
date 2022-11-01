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

const int maxm=10000+16;
const int maxb=4096;

int n,p;
vector<ipair> a[maxm];
int *f[maxm];
int *g[maxm];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>p;
	for (int i=0;i<n;i++)
	{
		int c,h,t;
		cin>>c>>h>>t;
		a[t].push_back(MP(c,h));
	}
	if (p==1)
	{
		for (int i=0;i<maxm;i++) if (SIZE(a[i])>0)
		{
			f[i]=new int[maxb];
			memset(f[i],0,maxb*sizeof(int));
			for (int k=0;k<SIZE(a[i]);k++) for (int w=a[i][k].first,x=a[i][k].second,j=maxb-1;j>=w;j--) checkmax(f[i][j],f[i][j-w]+x);
		}
		int nquery;
		for (cin>>nquery;nquery>0;nquery--)
		{
			int t,m;
			cin>>t>>m;
			cout<<f[t][m];
		}
		return 0;
	}
	for (int i=0;i<maxm;i++)
		if (SIZE(a[i])==0)
		{
			if (i>0 && i/p==(i-1)/p)
				f[i]=f[i-1];
			else 
			{
				f[i]=new int[maxb];
				memset(f[i],0,maxb*sizeof(int));
			}
		}
		else
		{
			f[i]=new int[maxb];
			memset(f[i],0,maxb*sizeof(int));
			if (i/p==(i-1)/p) memcpy(f[i],f[i-1],maxb*sizeof(int));
			for (int k=0;k<SIZE(a[i]);k++) for (int w=a[i][k].first,x=a[i][k].second,j=maxb-1;j>=w;j--) checkmax(f[i][j],f[i][j-w]+x);
		}
	for (int i=maxm-1;i>=0;i--)
		if (SIZE(a[i])==0)
		{
			if (i<maxm-1 && i/p==(i+1)/p)
				g[i]=g[i+1];
			else 
			{
				g[i]=new int[maxb];
				memset(g[i],0,maxb*sizeof(int));
			}
		}
		else
		{
			g[i]=new int[maxb];
			memset(g[i],0,maxb*sizeof(int));
			if (i/p==(i+1)/p) memcpy(g[i],g[i+1],maxb*sizeof(int));
			for (int k=0;k<SIZE(a[i]);k++) for (int w=a[i][k].first,x=a[i][k].second,j=maxb-1;j>=w;j--) checkmax(g[i][j],g[i][j-w]+x);
		}
	int nquery;
	for (cin>>nquery;nquery>0;nquery--)
	{
		int t,m;
		cin>>t>>m;
		int s=t-p+1;
		int ret=0;
		if (s<0)
			ret=f[t][m];
		else if (s>=maxm)
			ret=0;
		else 
		{
			if (t>=maxm) t=maxm-1;
			if (s/p==t/p)
				ret=g[s][m];
			else
				for (int i=0;i<=m;i++) checkmax(ret,f[t][i]+g[s][m-i]);
		}
		cout<<ret<<endl;
	}
	return 0;
}