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
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=100000+16;
const int MOD=1000000007;

int n;
int a[maxn];
vector<int> g[maxn];
int64 f[maxn][2];
int s[maxn];

void add(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}
void solve(int p,int _f)
{
	s[p]=a[p];
	for (int i=0;i<SIZE(g[p]);i++) if (g[p][i]!=_f) { solve(g[p][i],p); s[p]|=s[g[p][i]]; }
	f[p][0]=f[p][1]=0;
	if (s[p]==0) { f[p][0]=1; return; }
	int64 t0=1,t1=0;
	for (int i=0;i<SIZE(g[p]);i++) if (g[p][i]!=_f)
	{
		int c=g[p][i];
		if (s[c]==0) continue;
		int64 g0=(t0*(f[c][0]+f[c][1]))%MOD;
		int64 g1=(t1*(f[c][0]+f[c][1])+t0*f[c][1])%MOD;
		t0=g0;
		t1=g1;
	}
	if (a[p]==0)
		f[p][0]=(int)t0,f[p][1]=(int)t1;
	else
		f[p][0]=0,f[p][1]=(int)t0;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) { int p; scanf("%d",&p); add(p,i+1);  }
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int sa=0;
	for (int i=0;i<n;i++) sa+=a[i];
	if (sa==0) { printf("0\n"); return 0; }
	solve(0,-1);
	printf("%d\n",f[0][1]);
	return 0;
}