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

const int64 MOD=1000000007;
const int maxsize=400000+16;

int n;
int a[maxsize],t[maxsize];
int p[maxsize],inv_p[maxsize];

int mul(int a,int b)
{
	return (int64)a*b%MOD;
}
int fast_power(int p,int e)
{
	int r=1;
	for (;e>0;e/=2)
	{
		if (e&1) r=mul(r,p);
		p=mul(p,p);
	}
	return r;
}
int inverse(int x)
{
	return fast_power(x,MOD-2);
}
int choose(int n,int m)
{
	return mul(p[n],mul(inv_p[m],inv_p[n-m]));
}
int add(int a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
	return a;
}
int del(int a,int b)
{
	a-=b;
	if (a<0) a+=MOD;
	return a;
}
int main()
{
#ifdef _MSC_VER
	//freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	p[0]=1;
	FOR(i,1,maxsize) p[i]=mul(p[i-1],i);
	REP(i,maxsize) inv_p[i]=inverse(p[i]);
	cin>>n;
	REP(i,n) cin>>a[i];
	if (n==1)
	{
		printf("%d\n",a[0]);
		return 0;
	}
	if (n>1 && n%2==1)
	{
		REP(i,n) t[i]=a[i];
		--n;
		REP(i,n) a[i]=((i&1)?del(t[i],t[i+1]):add(t[i],t[i+1]));
	}
	int ret=0;
	for (int i=0;i<n;i+=2) ret=add(ret,mul(a[i],choose(n/2-1,i/2)));
	int ret2=0;
	for (int i=1;i<n;i+=2) ret2=add(ret2,mul(a[i],choose(n/2-1,i/2)));
	if (n%4==2)
		ret=add(ret,ret2);
	else
		ret=del(ret,ret2);
	printf("%d\n",ret);
	return 0;
}