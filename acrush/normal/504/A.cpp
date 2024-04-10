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

const int maxn=100000;

int n;
int d[maxn],s[maxn];
int q[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;i++) cin>>d[i]>>s[i];
	int m=0;
	for (int i=0;i<n;i++) m+=d[i];
	printf("%d\n",m/2);
	int sizeq=0;
	for (int i=0;i<n;i++) if (d[i]==1) q[sizeq++]=i;
	for (int cl=0;cl<sizeq;cl++)
	{
		int k=q[cl];
		if (d[k]!=1) continue;
		int p=s[k];
		printf("%d %d\n",k,p);
		--d[k];
		--d[p];
		s[p]^=k;
		if (d[p]==1) q[sizeq++]=p;
	}
	return 0;
}