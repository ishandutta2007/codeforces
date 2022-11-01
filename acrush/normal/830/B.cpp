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

const int maxn=200000+16;

int n;
int a[maxn];
map<int,vector<int>> s;
int w[maxn];

void updatew(int i,int d)
{
	for (;i<=n;i=(i|(i-1))+1) w[i]+=d;
}
int getw(int i)
{
	int r=0;
	for (;i>0;i&=(i-1)) r+=w[i];
	return r;
}
int get_distance(int s,int t)
{
	if (s<=t) return getw(t+1)-getw(s);
	return get_distance(s,n-1)+get_distance(0,t);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) s[a[i]].push_back(i);
	memset(w,0,sizeof(w));
	REP(i,n) updatew(i+1,1);
	int64 ret=0;
	int pos=0;
	while (!s.empty())
	{
		auto w=s.begin()->second;
		s.erase(s.begin());
		auto it=lower_bound(w.begin(),w.end(),pos);
		int next_pos;
		if (it==w.begin())
			next_pos=w.back();
		else
			next_pos=*(--it);
		ret+=get_distance(pos,next_pos);
		pos=(next_pos+1)%n;
		for (int p:w) updatew(p+1,-1);
	}
	cout<<ret<<endl;
	return 0;
}