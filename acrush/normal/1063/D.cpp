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

int64 solve0(int n,int c,int d)
{
	int ret=-1;
	int a[32];
	REP(set,1<<n)
	{
		REP(i,n) a[i]=1+(int)(contain(set,i));
		int p=0;
		for (int w=c;w>a[p];p=(p+1)%n) w-=a[p];
		if (p==d)
		{
			int c=0;
			REP(i,n) if (contain(set,i)) ++c;
			ckmax(ret,c);
		}
	}
	return ret;
}
int64 solve1(int64 n,int64 c,int64 d)
{
	int64 ret=-1;
	for (int bit=1;bit<=2;bit++) for (int actual=1;actual<=bit;actual++) if (actual<=c) 
		for (int64 m=n;m<=n+n;m++)
		{
			int64 z=(c-actual)%m;
			if (z<d || z>d+d) continue;
			if (z+bit+(n-d-1)>m || z+bit+(n-d-1)*2<m) continue;
			ckmax(ret,m-n);
		}
	return ret;
}
int64 solve2(int64 n,int64 c,int64 d)
{
	int64 ret=-1;
	for (int bit=1;bit<=2;bit++) for (int actual=1;actual<=bit;actual++) if (actual<=c) 
	{
		if (c-actual>=d && c-actual<=d+d)
			ckmax(ret,c-actual+bit+(n-d-1)*2-n);
		for (int64 cnt=1;cnt<=(c-actual)/n;cnt++)
		{
			int64 t=(c-actual)/cnt;
			int64 s=(c-actual)/(cnt+1)+1;
			ckmax(s,n);
			ckmin(t,n+n);
			if (s>t) continue;
			ckmin(t,(c-actual-d)/cnt);
			ckmax(s,(c-actual-d-d+cnt-1)/cnt);
			if (s>t) continue;
			ckmin(t,(c-actual+bit+2*(n-d-1))/(cnt+1));
			ckmax(s,(c-actual+bit+(n-d-1)+cnt)/(cnt+1));
			if (s>t) continue;
			ckmax(ret,t-n);
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int64 n,k,l,r;
	while (cin>>n>>l>>r>>k)
	{
		int64 d=(r-l+n)%n;
		int64 ret;
		if (n<=1000000)
			ret=solve1(n,k,d);
		else
			ret=solve2(n,k,d);
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}