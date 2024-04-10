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

const int maxn=(1<<20);

int n;
int a[maxn];
vector<int> g[maxn];
int64 s1[maxn];
int64 s2[maxn];

void update_s(int64 s[],int x,int64 d)
{
	for (;x<=n;x=(x|(x-1))+1) s[x]+=d;
}
int64 get_s(int64 s[],int x)
{
	int64 r=0;
	for (;x>0;x&=(x-1)) r+=s[x];
	return r;
}
void update(int s,int t,int64 c1,int c2)
{
	if (s>t) return;
	++s;
	++t;
	update_s(s1,s,c1);
	update_s(s2,s,c2);
	update_s(s1,t+1,-c1);
	update_s(s2,t+1,-c2);
	//FOR(i,s,t+1) s1[i]+=c1,s2[i]+=c2;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	FOR(i,1,n+1) cin>>a[i];
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	FOR(i,1,n+1)
	{
		if (a[i]<=i)
		{
			update(0,n-i,1,i-a[i]);
			update(n-i+1,n+a[i]-i,-1,a[i]-i+n);
			update(n+a[i]-i+1,n-1,1,i-n-a[i]);
		}
		else
		{
			update(0,a[i]-i,-1,a[i]-i);
			update(a[i]-i+1,n-i,1,i-a[i]);
			update(n-i+1,n-1,-1,a[i]-i+n);
		}
	}
	int64 r1=(1LL<<60);
	int64 r2=0;
	REP(i,n)
	{
		int64 t=get_s(s1,i+1)*i+get_s(s2,i+1);
		if (t<r1) r1=t,r2=i;
	}
	cout<<r1<<" "<<r2<<endl;
	return 0;
}