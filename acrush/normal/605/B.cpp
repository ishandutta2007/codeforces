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

const int maxn=200000+5;

int n,m;
int l[maxn],b[maxn];
pair<ipair,int> o[maxn];
ipair r[maxn];

bool solve()
{
	int c=0,p1=0,p2=1;
	vector<ipair> candidates;
	REP(k,m)
	{
		int id=o[k].second;
		if (b[id]==1)
		{ 
			r[id]=MP(c,c+1); 
			c++;
			if (SIZE(candidates)<m) REP(i,c-1) candidates.push_back(MP(i,c));
			continue; 
		}
		if (SIZE(candidates)==0) return false;
		r[id]=candidates.back();
		candidates.pop_back();
	}
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		REP(i,m) cin>>l[i]>>b[i];
		REP(i,m) o[i]=MP(MP(l[i],-b[i]),i);
		sort(o,o+m);
		if (solve())
			REP(i,m) printf("%d %d\n",r[i].first+1,r[i].second+1);
		else
			printf("-1\n");
	}
	return 0;
}