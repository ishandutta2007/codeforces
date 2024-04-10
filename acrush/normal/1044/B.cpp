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

const int maxn=100000;

int n;
vector<int> g[maxn];
bool c[maxn];

int dfs(int p,int prev)
{
	if (c[p]) return p;
	for (int z:g[p]) if (z!=prev)
	{
		int t=dfs(z,p);
		if (t>=0) return t;
	}
	return -1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		cin>>n;
		REP(i,n) g[i].clear();
		REP(i,n-1)
		{
			int a,b;
			cin>>a>>b;
			--a;
			--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int n1,n2;
		REP(i,n) c[i]=false;
		cin>>n1;
		REP(i,n1)
		{
			int p;
			cin>>p;
			--p;
			c[p]=true;
		}
		cin>>n2;
		vector<int> b(n2);
		REP(i,n2) { cin>>b[i]; --b[i]; }
		printf("B %d\n",b[0]+1);
		fflush(stdout);
		int key;
		cin>>key;
		--key;
		int other=dfs(key,-1);
		printf("A %d\n",other+1);
		fflush(stdout);
		int pick;
		cin>>pick;
		--pick;
		bool ok=false;
		REP(i,n2) if (b[i]==pick) ok=true;
		if (ok)
			printf("C %d\n",other+1);
		else
			printf("C -1\n");
		fflush(stdout);
	}
	return 0;
}