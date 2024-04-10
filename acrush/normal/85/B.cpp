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

const int maxn=100000+5;

int c[3],n;
int64 t[3],a[maxn];
vector<int64> g[3];

void add(int64 &current,int k)
{
	if (SIZE(g[k])>=c[k])
		checkmax(current,g[k][SIZE(g[k])-c[k]]+t[k]);
	g[k].push_back(current);
	current+=t[k];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	for (int i=0;i<3;i++)
		scanf("%d",&c[i]);
	for (int i=0;i<3;i++)
	{
		int tt;
		scanf("%d",&tt);
		t[i]=tt;
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		int tt;
		scanf("%d",&tt);
		a[i]=tt;
	}
	int64 R=0;
	for (int i=0;i<n;i++)
	{
		int64 currenttime=a[i];
		for (int k=0;k<3;k++)
			add(currenttime,k);
		checkmax(R,currenttime-a[i]);
	}
	cout<<R<<endl;
	return 0;
}