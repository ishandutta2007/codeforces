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

bool utest=false;//true;

vector<int64> w;
int cnt;
void init(int n,int range)
{
	w.resize(n);
	REP(i,n) w[i]=rand()%range;
	REP(i,n) printf("%d ",(int)w[i]); printf("\n");
	cnt=0;
}

void answer(vector<int64> a)
{
	if (utest)
	{
		printf("cnt = %d / %d\n",cnt,4*SIZE(w));
		if (a!=w) 
		{
			printf("WA\n"); exit(0); 
		}
		printf("passed\n");
	}
	else
	{
		printf("!");
		for (int64 p:a) printf(" %d",(int)p);
		printf("\n");
		fflush(stdout);
	}
}
int64 query(int x,int y,int z)
{
	assert(x!=y && x!=z && y!=z);
	if (utest)
	{
		++cnt;
		int64 a[3];
		a[0]=w[x];
		a[1]=w[y];
		a[2]=w[z];
		sort(a,a+3);
		return a[0]+a[2];
	}
	else
	{
		printf("? %d %d %d\n",x+1,y+1,z+1);
		fflush(stdout);
		int r;
		scanf("%d",&r);
		return r;
	}
}

int countbit(int set) { return set?(1+countbit(set&(set-1))):0; }

using VI=vector<int>;

VI ck(VI a)
{
	sort(ALL(a));
	return a;
}

void solve(int p[],vector<int64>& r)
{
	sort(p,p+5);
	map<VI,int64> mp;
	REP(set,two(5)) 
	{
		VI e;
		REP(i,5) if (contain(set,i)) e.push_back(p[i]);
		if (SIZE(e)==3) mp[ck(e)]=query(e[0],e[1],e[2]);
	}
	do{
		int64 s02=mp[ck({p[0],p[1],p[2]})];
		int64 s04=mp[ck({p[0],p[2],p[4]})];
		int64 s24=mp[ck({p[2],p[3],p[4]})];
		r[p[0]]=(s02+s04+s24)/2-s24;
		r[p[2]]=(s02+s04+s24)/2-s04;
		r[p[4]]=(s02+s04+s24)/2-s02;
		r[p[1]]=mp[ck({p[1],p[2],p[4]})]-r[p[4]];
		r[p[3]]=mp[ck({p[0],p[2],p[3]})]-r[p[0]];
		bool ok=true;
		REP(i,4) if (r[p[i]]>r[p[i+1]]) ok=false;
		for (auto w:mp)
		{
			int64 z[3];
			REP(i,3) z[i]=r[w.first[i]];
			sort(z,z+3);
			if (z[0]+z[2]!=w.second) { ok=false; break; }
		}
		if (ok) break;
	} while (next_permutation(p,p+5)!=0);
}

int main()
{
#ifdef _MSC_VER
	// freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	if (utest) init(n,10);
	vector<int64> r(n);
	int p[5];
	for (int i=0;i<n;i+=5)
	{
		if (i+4<n)
			REP(k,5) p[k]=i+k;
		else
			REP(k,5) p[k]=n-1-k;
		solve(p,r);
	}
	answer(r);
	return 0;
}