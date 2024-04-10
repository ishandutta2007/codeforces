#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

const int maxn=(1<<20);
const int maxsize=16000000;

int n;
int a[maxn];
int cnt[maxsize];
int f[maxsize];
int md[maxsize],mc[maxsize];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	memset(f,0,sizeof(f));
	for (int p=2;p<maxsize;p++) if (f[p]==0)
		for (int i=p;i<maxsize;i+=p)
			f[i]=p;
	memset(cnt,0,sizeof(cnt));
	REP(i,maxsize) md[i]=100000000;
	cin>>n;
	REP(i,n) cin>>a[i];	
	REP(i,n)
		for (int m=a[i];m>1;)
		{
			int p=f[m],e=0;
			for (;m%p==0;m/=p) e++;
			++cnt[p];
			if (e<md[p]) md[p]=e,mc[p]=1;
			else if (e==md[p]) mc[p]++;
		}
	int ret=n+1;
	REP(p,maxsize) if (cnt[p]>0)
		if (cnt[p]<n) ckmin(ret,n-cnt[p]);
		else if (mc[p]<n) ckmin(ret,mc[p]);
	if (ret>=n) ret=-1;
	cout<<ret<<endl;
	return 0;
}