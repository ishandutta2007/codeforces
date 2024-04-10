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

int64 solve(int64 n)
{
	if (n<=0) return 0;
	int64 R=0;
	for (int d=1;d<=9;d++) if (d<=n) R++;
	for (int d=1;d<=9;d++) for (int L=2;L<=18;L++)
	{
		int64 p10=1;
		for (int i=0;i<L-2;i++) p10*=10;
		int64 H=-1,T=p10;
		for (;H+1<T;)
		{
			int64 M=H+(T-H)/2;
			if (M*10+d*(1+p10*10)<=n) H=M;
			else T=M;
		}
		R+=T;
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("A.in","r",stdin);
#endif
	int64 a,b;
	cin>>a>>b;
	cout<<solve(b)-solve(a-1)<<endl;
	return 0;
}