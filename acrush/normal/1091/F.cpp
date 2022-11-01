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
	int n;
	while (cin>>n)
	{
		vector<int64> length(n);
		string s;
		REP(i,n) cin>>length[i];
		cin>>s;
		int64 ret=0;
		int64 mp=0;
		bool has_g=false;
		bool has_w=false;
		int64 g0=0;
		int64 g1=0;
		int64 w0=0;
		int64 w1=0;
		REP(i,n)
		{
			int64 d;
			int64 l=length[i]*2;
			auto fly=[&](int64* p) { int64 d=min(mp,l); ret+=d; l-=d; mp-=d; if (p!=nullptr) *p+=d; };
			if (s[i]=='G')
			{
				has_g=true;
				fly(&g1);
				d=min(w1,l/2); ret+=d*2; mp+=d*2; w1-=d;
				fly(&g1);
				d=l/2; ret+=d*5; l-=d; mp+=d; g0+=d;
				fly(&g1);
			}
			else if (s[i]=='W')
			{
				has_w=true;
				fly(&w1);
				d=l/2; ret+=d*3; l-=d; mp+=d; w0+=d;
				fly(&w1);
			}
			else
			{
				fly(nullptr);
				d=min(w1,l/2); ret+=d*2; mp+=d*2; w1-=d;
				fly(nullptr);
				d=min(g1,l/2); ret+=d*4; mp+=d*2; g1-=d;
				fly(nullptr);
				int64 c=(has_w?3:5);
				d=l; ret+=c*d; mp+=d;
				fly(nullptr);
			}
			assert(l<=eps);
			assert(mp<=eps);
		}
		cout<<ret/2<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}