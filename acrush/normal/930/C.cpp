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

vector<int> calc(vector<int> a)
{
	int n=SIZE(a);
	vector<int> r(n);
	vector<int> b;
	b.push_back(0);
	REP(i,n)
	{
		auto it=upper_bound(b.begin(),b.end(),a[i]);
		r[i]=it-b.begin();
		if (it==b.end()) b.push_back(a[i]);
		else b[r[i]]=a[i];
	}
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> d(m);
	REP(i,n)
	{
		int s,t;
		cin>>s>>t;
		--s;
		d[s]++;
		if (t<m) --d[t];
	}
	FOR(i,1,m) d[i]+=d[i-1];
	vector<int> f1=calc(d);
	vector<int> e=d;
	reverse(ALL(e));
	vector<int> f2=calc(e);
	int ret=0;
	REP(i,m) ckmax(ret,f1[i]+f2[m-1-i]-1);
	printf("%d\n",ret);
	return 0;
}