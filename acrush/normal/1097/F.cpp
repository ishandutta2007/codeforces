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

const int maxsize=7100;
const int maxn=200000+16;

using bset=bitset<maxsize>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,nq;
	while (cin>>n>>nq)
	{
		vector<bset> b(maxsize);
		FOR(i,1,maxsize) for (int j=i;j<maxsize;j+=i) b[j].set(i);
		vector<int> c(maxsize);
		c[1]=1;
		FOR(i,2,maxsize)
		{
			int p=2;
			for (;i%p!=0;++p);
			if (i/p%p==0) continue;
			c[i]=c[i/p];
		}
		vector<bset> d(maxsize);
		FOR(i,1,maxsize) for (int j=1;i*j<maxsize;j++) if (c[j]) d[i].set(i*j);
		vector<bset> a(n);
		REP(cl,nq)
		{
			int tp;
			cin>>tp;
			if (tp==1)
			{
				int x,v;
				cin>>x>>v; --x;
				a[x]=b[v];
			}
			else if (tp==2)
			{
				int x,y,z;
				cin>>x>>y>>z; --x; --y; --z;
				a[x]=(a[y]^a[z]);
			}
			else if (tp==3)
			{
				int x,y,z;
				cin>>x>>y>>z; --x; --y; --z;
				a[x]=(a[y]&a[z]);
			}
			else
			{
				int x,v;
				cin>>x>>v; --x;
				printf("%d",(a[x]&d[v]).count()%2);
			}
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}