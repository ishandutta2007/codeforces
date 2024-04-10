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

const int maxsize=(1<<20);
const int oo=100000000;

int p[maxsize];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	memset(p,255,sizeof(p));
	for (int i=2;i<maxsize;i++) if (p[i]<0) for (int j=i;j<maxsize;j+=i) p[j]=i;
	int cb[256];
	memset(cb,0,sizeof(cb));
	FOR(i,1,256) cb[i]=cb[i/2]+i%2;
	int n;
	while (cin>>n)
	{
		vector<int> a(n);		
		REP(i,n) cin>>a[i];
		a.resize(unique(ALL(a))-a.begin());
		n=SIZE(a);
		vector<int> c(maxsize);
		int ret=oo;
		REP(i,n)
		{
			vector<int> g;
			{
				for (int m=a[i];m>1;)
				{
					int d=p[m];
					g.push_back(d);
					for (;m%d==0;m/=d);
				}
			}
			int m=SIZE(g);
			vector<int> e(1<<m);
			REP(set,1<<m)
			{
				int p=1;
				REP(k,m) if (set&(1<<k)) p*=g[k];
				e[set]=c[p];
			}
			vector<int> z(1<<m);
			FOR(set,1,1<<m) for (int subset=set;subset>0;subset=((subset-1)&set)) z[set]+=((cb[subset]&1)?e[subset]:-e[subset]);
			vector<int> f(1<<m);
			FOR(set,1,1<<m)
				if (z[set]<i)
					f[set]=1;
				else
				{
					f[set]=oo;
					for (int mset=set/2,subset=(set-1)&set;subset>mset;subset=((subset-1)&set)) f[set]=min(f[set],f[subset]+f[set^subset]);
				}
			REP(set,1<<m)
			{
				int p=1;
				REP(i,m) if (set&(1<<i)) p*=g[i];
				++c[p];
			}
			ckmin(ret,f[(1<<m)-1]);
		}
		if (ret>=oo) ret=-2;
		printf("%d\n",ret+1);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}