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

int n;
vector<vector<int>> ret;

void add(int a,int b,int c)
{
	vector<int> p;
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	ret.push_back(p);
}
void add(int a,int b,int c,int d)
{
	vector<int> p;
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	p.push_back(d);
	ret.push_back(p);
}

void solve()
{
	if (n%2==1)
	{
		add(0,1,2);
		add(0,1,2);
		for (int i=3;i<n;i+=2)
		{
			int a=i;
			int b=i+1;
			for (int j=0;j<i-1;j+=2)
			{
				add(j,a,j+1,b);
				add(j,a,j+1,b);
			}
			add(i-1,a,b);
			add(i-1,a,b);
		}
	}
	else
	{
		add(0,1,2);
		add(0,1,3);
		add(1,2,3);
		add(0,2,3);
		for (int i=4;i<n;i+=2)
		{
			int a=i;
			int b=i+1;
			for (int j=0;j<i-2;j+=2)
			{
				add(j,a,j+1,b);
				add(j,a,j+1,b);
			}
			add(i-1,a,b);
			add(i-2,a,b);
			add(i-1,a,i-2,b);
		}
	}
}
int main()
{
#ifdef _MSC_VER
	//freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	solve();
	printf("%d\n",SIZE(ret));
	for (auto path:ret) 
	{
		printf("%d",SIZE(path));
		for (int p:path) printf(" %d",p+1);
		printf("\n");
	}
	return 0;
}