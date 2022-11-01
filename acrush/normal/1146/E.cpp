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

const int maxsize=100000+16;

void update(vector<int>& s,int i,int delta)
{
	for (;i<SIZE(s);i=(i|(i-1))+1) s[i]+=delta;
}
int getsum(const vector<int>& s,int i)
{
	int r=0;
	for (;i>0;i&=(i-1)) r+=s[i];
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,nq;
	while (cin>>n>>nq)
	{
		vector<int> a(n);
		REP(i,n) cin>>a[i];
		vector<int> b;
		REP(i,nq)
		{
			string s;
			int key;
			cin>>s>>key;
			if (s=="<")
				b.push_back(key-1);
			else
			{
				b.push_back(key);
				b.push_back(maxsize-1);
			}
		}
		int m=SIZE(b);

		vector<ipair> sorted_by_abs_b;
		REP(i,m) sorted_by_abs_b.push_back(MP(b[i]>=0?b[i]+1:-b[i],i));
		sort(ALL(sorted_by_abs_b));
		vector<int> max_pos(m+1);
		max_pos[0]=-1;
		REP(i,m) max_pos[i+1]=max(max_pos[i],sorted_by_abs_b[i].second);
		int abs_b_at=m-1;

		vector<ipair> sorted_by_b;
		REP(i,m) sorted_by_b.push_back(MP(b[i],i));
		sort(ALL(sorted_by_b));
		int pb=SIZE(sorted_by_b)-1;
		vector<int> sb(m+1);

		vector<int> results(maxsize*2-1);
		for (int abs_d=maxsize-1;abs_d>=0;abs_d--) for (int op=-1;op<=1;op+=2)
		{
			int d=abs_d*op;
			for (;abs_b_at>=0 && sorted_by_abs_b[abs_b_at].first>abs_d;--abs_b_at);
			int pos=max_pos[abs_b_at+1];
			int& ret=results[d+maxsize-1];
			if (pos<0)
				ret=d;
			else
				ret=abs_d;
			for (;pb>=0 && sorted_by_b[pb].first>=abs_d;pb--)
				update(sb,sorted_by_b[pb].second+1,1);
			int cnt=getsum(sb,m)-getsum(sb,pos);
			if (cnt%2) ret=-ret;
			// FOR(i,pos+1,m) if (b[i]>=abs_d) ret=-ret;
			if (abs_d==0) ret=0;
		}
		REP(i,n)
		{
			if (i>0) printf(" ");
			printf("%d",results[a[i]+maxsize-1]);
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}