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

int n;
int a[maxn];
int c_odd;
int c[maxn];

void init1()
{
	c_odd=0;
	memset(c,0,sizeof(c));
}
bool is_ok1()
{
	if (n&1) return c_odd<=1;
	return c_odd<=0;
}
void update(int p,int d)
{
	c_odd-=(c[p]&1);
	c[p]+=d;
	c_odd+=(c[p]&1);
}
int64 count1(int s,int t)
{
	if (s>t) return 0;
	return (int64)(s+1)*(int64)(n-t);
}
int64 count1(int s1,int t1,int s2,int t2)
{
	return count1(s1,t1)+count1(s2,t2)-count1(min(s1,s2),max(t1,t2));
}
int64 solve()
{
	init1();
	for (int i=0;i<n;i++) update(a[i],1);
	if (!is_ok1()) return 0;
	int L=0,R=n-1;
	while (L<R)
	{
		if (a[L]!=a[R]) break;
		update(a[L],-1);
		update(a[R],-1);
		L++,R--;
	}
	if (L>=R) return (int64)n*(int64)(n+1)/2;
	init1();
	for (int i=L;i<=R;i++) update(a[i],1);
	int p=R;
	for (;p>(n+1)/2;p--)
	{
		update(a[p],-1);
		update(a[p],-1);
		if (c[a[p]]<0) break;
		if (!is_ok1()) break;
	}
	init1();
	for (int i=L;i<=R;i++) update(a[i],1);
	int q=L;
	for (;q<n/2-1;q++)
	{
		update(a[q],-1);
		update(a[q],-1);
		if (c[a[q]]<0) break;
		if (!is_ok1()) break;
	}
	int64 ret1=count1(L,p,q,R);
	p=(n-1)/2;
	q=n/2;
	for (;a[p]==a[q];p--,q++);
	init1();
	for (int i=L;i<=p;i++) c[a[i]]++;
	for (int i=q;i<=R;i++) c[a[i]]--;
	int64 ret2=0;
	bool ok=true;
	for (int i=0;i<maxn;i++) if (c[i]) ok=false;
	if (ok) ret2=(int64)(L+1)*(n/2-p);
	int64 ret3=0;
	if (n%2==1)
	{
		init1();
		for (int i=L;i<n/2;i++) c[a[i]]++;
		for (int i=n/2+1;i<=R;i++) c[a[i]]--;
		c[a[n/2]]++;
		int sc=0;
		for (int i=0;i<maxn;i++) sc+=abs(c[i]);
		if (sc<=1) ret3+=(int64)(L+1);
		c[a[n/2]]-=2;
		sc=0;
		for (int i=0;i<maxn;i++) sc+=abs(c[i]);
		if (sc<=1) ret3+=(int64)(L+1);
	}
	return ret1+ret2*2+ret3;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	int64 ret=solve();
	cout<<ret<<endl;
	return 0;
}