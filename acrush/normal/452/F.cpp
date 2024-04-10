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

const int maxn=1<<20;

int n;
int a[maxn];
int64 p[maxn],sp[maxn];
int64 seed;
int64 w1[maxn],w2[maxn];

int64 f(int m) { return p[maxn/2+m]; }

void solvep(int step)
{
	if (step==0) seed=3137;
	else seed=rand()%10000+2;
	p[0]=1;
	for (int i=1;i<maxn;i++) p[i]=p[i-1]*seed;
}
void update(int64 s[],int p,int64 d)
{
	p++;
	for (;p<=n;p=(p|(p-1))+1) s[p]+=d;
}
int64 sum(int64 s[],int p)
{
	p++;
	int64 r=0;
	for (;p>0;p&=(p-1)) r+=s[p];
	return r;
}
int64 sum(int64 s[],int a,int b)
{
	return sum(s,b)-sum(s,a-1);
}
bool solve(int step)
{
	solvep(step);
	memset(w1,0,sizeof(w1));
	memset(w2,0,sizeof(w2));
	for (int k=0;k<n;k++)
	{
		if (a[k]>0 && a[k]<n-1)
		{
			int w=min(a[k],n-1-a[k]);
			int64 t1,t2;
			t1=sum(w1,a[k]+1,a[k]+w);
			t2=sum(w2,n-1-a[k]+1,n-1-a[k]+w);
			if (t1*f(n-1-a[k])!=t2*f(a[k])) return true;
			t1=sum(w1,a[k]-w,a[k]-1);
			t2=sum(w2,n-1-a[k]-w,n-1-a[k]-1);
			if (t1*f(n-1-a[k]-w)!=t2*f(a[k]-w)) return true;
		}
		update(w1,a[k],f(a[k]));
		update(w2,n-1-a[k],f(n-1-a[k]));
	}
	return false;

}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) a[i]--;
	for (int i=0;i<5;i++) if (solve(i)) { printf("YES\n"); return 0; }
	printf("NO\n");
	return 0;
}