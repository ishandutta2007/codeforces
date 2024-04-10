#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=128;
const int M=(1<<20);

template<class T> inline vector<pair<T,int> > factorize(T n)
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}

int n;
unordered_map<int,set<int>> w;
unordered_map<int,int> htable;
int f[M];

int solve(int set)
{
	if (set==0) return 0;
	if (set<M && f[set]>=0) return f[set];
	if (set>=M)
	{
		auto it=htable.find(set);
		if (it!=htable.end()) return it->second;
	}
	unordered_set<int> visited;
	for (int p=0;;p++)
	{
		int s1=(set&((1<<p)-1));
		int s2=(set>>(p+1));
		int w=(s1|s2);
		if (w==set) break;
		visited.insert(solve(w));
	}
	int ret=0;
	for (;visited.count(ret);++ret);
	if (set<M)
		f[set]=ret;
	else
		htable[set]=ret;
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	memset(f,255,sizeof(f));
	while (cin>>n)
	{
		w.clear();
		REP(i,n)
		{
			int p;
			cin>>p;
			auto a=factorize(p);
			for (auto e:a) w[e.first].insert(e.second);
		}
		int ret=0;
		for (auto& e:w)
		{
			int set=0;
			for (int p:e.second) set|=(1<<(p-1));
			ret^=solve(set);
		}
		if (ret==0)
			printf("Arpa\n");
		else
			printf("Mojtaba\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}