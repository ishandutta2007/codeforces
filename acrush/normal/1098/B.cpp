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

int cnt(const string& a,const string& b)
{
	int r=0;
	REP(i,LENGTH(a)) if (a[i]!=b[i]) ++r;
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		vector<string> a(n);
		REP(i,n) cin>>a[i];
		int ret=n*m+1;
		vector<string> r;
		char p[5]="AGCT";
		do{
			int cb=0;
			vector<string> b;
			REP(i,n)
			{
				string s1,s2;
				REP(j,m) s1+=p[(i%2)*2+j%2];
				REP(j,m) s2+=p[(i%2)*2+(j+1)%2];
				int e1=cnt(s1,a[i]);
				int e2=cnt(s2,a[i]);
				b.push_back((e1<e2)?s1:s2);
				cb+=min(e1,e2);
			}
			if (cb<ret) ret=cb,r=b;
			cb=0;
			b=vector<string>(n,string(m,' '));
			REP(i,m)
			{
				string s1,s2,g;
				REP(j,n) s1+=p[(i%2)*2+j%2];
				REP(j,n) s2+=p[(i%2)*2+(j+1)%2];
				REP(j,n) g+=a[j][i];
				int e1=cnt(s1,g);
				int e2=cnt(s2,g);
				REP(j,n) b[j][i]=((e1<e2)?s1:s2)[j];
				cb+=min(e1,e2);
			}
			if (cb<ret) ret=cb,r=b;
		} while (next_permutation(p,p+4));
		REP(i,n) printf("%s\n",r[i].c_str());
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}