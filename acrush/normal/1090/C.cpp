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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	vector<pair<ipair,int>> ret;
	int n,m;
	cin>>n>>m;
	vector<unordered_set<int>> a(n);
	vector<vector<int>> g(m);
	int total=0;
	REP(i,n)
	{
		int c;
		cin>>c;
		REP(j,c) 
		{ 
			int p; 
			cin>>p; --p;
			a[i].insert(p);
		}
		total+=c;
	}
	int c1=total/n;
	int c2=(total+n-1)/n;
	REP(step,3)
	{
		int bound,limit;
		if (step==0)
			bound=c1-1,limit=c2+1;
		else if (step==1)
			bound=c1-1,limit=c2;
		else
			bound=c1,limit=c2+1;
		REP(i,m) g[i].clear();
		REP(i,n) if (SIZE(a[i])>=limit) for (int x:a[i]) g[x].push_back(i);
		set<int> skey;
		skey.clear();
		REP(i,m) if (SIZE(g[i])>0) skey.insert(i);
		REP(i,n)
			for (int key=0;SIZE(a[i])<=bound;key++)
			{
				auto it=skey.lower_bound(key);
				if (it==skey.end()) break;
				key=*it;
				if (a[i].count(key)) continue;
				if (SIZE(g[key])==0) { skey.erase(key); continue; }
				int idx=g[key].back();
				g[key].pop_back();
				if (a[idx].count(key) && SIZE(a[idx])>=limit)
				{
					assert(a[idx].count(key));
					assert(!a[i].count(key));
					a[idx].erase(key);
					a[i].insert(key);
					ret.push_back(MP(MP(idx,i),key));
				}
				else
					--key;
			}
	}
	REP(i,n) assert(SIZE(a[i])==c1 || SIZE(a[i])==c2);
	printf("%d\n",SIZE(ret));
	for (auto w:ret) printf("%d %d %d\n",w.first.first+1,w.first.second+1,w.second+1);
	return 0;
}