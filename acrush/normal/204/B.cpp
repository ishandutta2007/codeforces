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

int n,a[maxn],b[maxn];
map<int,int> M;

int main()
{
#ifdef _MSC_VER
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	for (int i=0;i<n;i++)
	{
		M[a[i]]++;
		M[b[i]]++;
	}
	int R=n+1;
	for (map<int,int>::iterator it=M.begin();it!=M.end();++it) if (it->second>=(n+1)/2)
	{
		int key=it->first;
		int c=0,d=0;
		for (int i=0;i<n;i++) 
			if (a[i]==key)
				c++;
			else if (b[i]==key)
				d++;
		if (c+d>=(n+1)/2) checkmin(R,max(0,(n+1)/2-c));
	}
	if (R>n) R=-1;
	printf("%d\n",R);
	return 0;
}