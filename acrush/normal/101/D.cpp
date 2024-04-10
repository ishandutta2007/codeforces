#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

const int maxn=100000+5;

int n;
int c[maxn];
long double s[maxn],t[maxn];
vector<ipair> g[maxn];

void solve(int p,int prev)
{
	vector<pair<long double,pair<long double,int> > > q;
	c[p]=1;
	t[p]=0;
	s[p]=0;
	for (int i=0;i<SIZE(g[p]);i++)
	{
		int other=g[p][i].first;
		if (other==prev) continue;
		solve(other,p);
		int c0=c[other];
		long double w=g[p][i].second;
		long double t0=t[other]+2*w;
		c[p]+=c0;
		t[p]+=t0;
		s[p]+=s[other]+w*c0;
		q.push_back(MP(t0/c0,MP(t0,c0)));
	}
	sort(q.begin(),q.end());
	for (int sc=c[p]-1,i=0;i<SIZE(q);i++)
	{
		sc-=q[i].second.second;
		s[p]+=q[i].second.first*sc;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n-1;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		a--;
		b--;
		g[a].push_back(MP(b,w));
		g[b].push_back(MP(a,w));
	}
	solve(0,-1);
	printf("%.18lf\n",(double)(s[0]/(long double)(n-1)));
	return 0;
}