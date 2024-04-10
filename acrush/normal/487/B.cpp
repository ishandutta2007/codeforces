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

const int maxn=200000+10;
const int INF=100000000;

int n,l,d;
int a[maxn];
int p[maxn];
int f[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&d,&l);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	multiset<int> S;
	for (int k=0,i=0;i<n;i++)
	{
		for (;!S.empty();)
		{
			int v1=*S.begin();
			int v2=*(--S.end());
			if (abs(v1-a[i])<=d && abs(v2-a[i])<=d) break;
			S.erase(S.lower_bound(a[k]));
			k++;
		}
		p[i]=k;
		S.insert(a[i]);
	}
	S.clear();
	f[0]=0;
	for (int k=0,i=1;i<=n;i++)
	{
		if (i-l>=0) S.insert(f[i-l]);
		for (;k<=i-l && k<p[i-1];k++) S.erase(S.lower_bound(f[k]));
		f[i]=(S.empty()?INF:((*S.begin())+1));
	}
	if (f[n]>=INF) f[n]=-1;
	printf("%d\n",f[n]);
	return 0;
}