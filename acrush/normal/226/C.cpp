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

int64 MOD;
int64 a[2][2];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int64 L,R,C;
	cin>>MOD>>L>>R>>C;
	L--;
	int64 d;
	for (d=(R-L)/(C-1)+1;d>0;d--)
	{
		if (R/d-L/d>=C) break;
		checkmin(d,R/(R/d+1)+1);
	}
	a[0][0]=0;
	a[0][1]=a[1][0]=a[1][1]=1;
	int64 b[2];
	b[0]=0;b[1]=1%MOD;
	for (d--;d>0;d/=2)
	{
		if (d&1)
		{
			int64 c0=(b[0]*a[0][0]+b[1]*a[0][1])%MOD;
			int64 c1=(b[0]*a[1][0]+b[1]*a[1][1])%MOD;			
			b[0]=c0;
			b[1]=c1;
		}
		int64 t[2][2];
		memset(t,0,sizeof(t));
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++)
			t[i][j]=(t[i][j]+a[i][k]*a[k][j])%MOD;
		memcpy(a,t,sizeof(a));
	}
	cout<<b[1]%MOD<<endl;
	return 0;
}