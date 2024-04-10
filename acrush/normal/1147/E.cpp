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
using VI=vector<int>;

char str[1<<20];

vector<int> query(const vector<ipair>& a)
{
	if (SIZE(a)==0) return vector<int>{};
	printf("Q %d",SIZE(a));
	for (ipair w:a) printf(" %d %d",w.first+1,w.second+1);
	printf("\n");
	fflush(stdout);
	scanf("%s",str);
	vector<int> ret;
	for (int i=0;i<SIZE(a);i++) ret.push_back(str[i]-'0');
	return ret;
}
int main()
{
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		int n;
		scanf("%d",&n);
		vector<ipair> q1,q2;
		for (int i=0;i+1<n;i+=2) q1.emplace_back(i,i+1);
		for (int i=1;i+1<n;i+=2) q2.emplace_back(i,i+1);
		VI e1=query(q1);
		VI e2=query(q2);
		vector<ipair> segs;
		segs.emplace_back(0,0);
		FOR(i,1,n)
		{
			int same=0;
			if (i%2==1) same=e1[(i-1)/2];
			else same=e2[(i-2)/2];
			if (same)
				segs.back().second=i;
			else
				segs.emplace_back(i,i);
		}
		vector<ipair> q3,q4,q5;
		for (int i=0;i+2<SIZE(segs);i+=3) q3.emplace_back(segs[i].first,segs[i+2].first);
		for (int i=1;i+2<SIZE(segs);i+=3) q4.emplace_back(segs[i].first,segs[i+2].first);
		for (int i=2;i+2<SIZE(segs);i+=3) q5.emplace_back(segs[i].first,segs[i+2].first);
		VI e3=query(q3);
		VI e4=query(q4);
		VI e5=query(q5);
		vector<int> g(max(0,SIZE(segs)-2));
		REP(i,SIZE(e3)) g[i*3]=e3[i];
		REP(i,SIZE(e4)) g[i*3+1]=e4[i];
		REP(i,SIZE(e5)) g[i*3+2]=e5[i];
		vector<int> color(SIZE(segs));
		REP(i,SIZE(segs))
			if (i==0)
				color[i]=0;
			else if (i==1)
				color[i]=1;
			else if (g[i-2])
				color[i]=color[i-2];
			else
				color[i]=3-color[i-1]-color[i-2];
		vector<int> r[3];
		REP(i,SIZE(segs)) FOR(x,segs[i].first,segs[i].second+1) r[color[i]].push_back(x);
		printf("A %d %d %d\n",SIZE(r[0]),SIZE(r[1]),SIZE(r[2]));
		REP(k,3) 		
		{
			REP(i,SIZE(r[k]))
			{
				if (i>0) printf(" ");
				printf("%d",r[k][i]+1);
			}
			printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}