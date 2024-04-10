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
#define two(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
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

int MOD;
int m;
vector<int> gen;
int n;
vector<int> a;
int64 cnt[256][64];
unordered_map<int64,vector<int64>> htable;

void prepare()
{
	htable.clear();
	memset(cnt,0,sizeof(cnt));
	cnt[0][0]=1;
	REP(i,250) REP(j,MOD) if (cnt[i][j]) REP(k,m) cnt[i+1][(j+gen[k])%MOD]+=cnt[i][j];
}
inline int64 circular_shift_right(int64 s,int d)
{
	return (s>>d)|((s&(two(d)-1))<<(MOD-d));
}

int64 calc(int64 w,int64 mask)
{
	if (w<0) return 0;
	vector<int64>& wcnt=htable[w];
	if (SIZE(wcnt)==0)
	{
		wcnt=vector<int64>(MOD+1);
		vector<int> digits;
		for (int64 t=w+1;t>0;t/=m) digits.push_back(t%m);
		int s=0;
		REP(i,SIZE(digits)) s+=gen[digits[i]];
		REP(i,SIZE(digits))
		{
			s-=gen[digits[i]];
			REP(d,digits[i]) 
			{
				int s0=s+gen[d];
				REP(w,MOD) wcnt[(s0+w)%MOD]+=cnt[i][w];
			}
		}
		REP(i,MOD) wcnt[MOD]+=wcnt[i];
	}
	if (mask==two(MOD)-1) return wcnt[MOD];
	int64 ret=0;
	REP(i,MOD) if (contain(mask,i)) ret+=wcnt[i];
	assert(ret<=w+1);
	return ret;
}

int64 solve(vector<int64> a,int64 w)
{
	if (w<0) return 0;
	if (SIZE(a)==1) return calc(w,a[0]);
	vector<int64> b;
	int64 ret=0;
	REP(md,m) if (md<=w)
	{
		b.clear();
		bool ok=true;
		REP(i,SIZE(a))
		{
			int at=(i+md)/m;
			int pos=(i+md)%m;
			for (;at>=SIZE(b);b.push_back(two(MOD)-1));
			b[at]&=circular_shift_right(a[i],gen[pos]);
			if (b[at]==0) { ok=false; break; }
		}
		if (ok) ret+=solve(b,(w-md)/m);
	}
	assert(ret<=w+1);
	return ret;
}
int64 solve(int64 w)
{
	if (w<0) return 0;
	vector<int64> mask(n);
	REP(i,n) REP(k,a[i]+1) mask[i]|=two(k);
	return solve(mask,w);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>m>>MOD)
	{
		gen=vector<int>(m);
		REP(i,m) cin>>gen[i];
		cin>>n;
		a=vector<int>(n);
#ifdef _MSC_VER
		if (n>10)
			REP(i,n) a[i]=MOD-1;//()%MOD;
		else
			REP(i,n) cin>>a[i];
#else
		REP(i,n) cin>>a[i];
#endif
		int64 l,r;
		cin>>l>>r; --l; --r;
		prepare();
		int64 ret=solve(r-n+1)-solve(l-1);
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}