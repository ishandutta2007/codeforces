#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

const int maxn=512;
const int64 MOD=1000000007;

int n;
int64 f[maxn][maxn];

int64 ck(int64 m)
{
	m%=MOD;
	if (m<0) m+=MOD;
	return m;
}
void addto(int64& a,int64 b)
{
	a=ck(a+b);
}
int main()
{
#ifdef _MSC_VER
	//freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	memset(f,0,sizeof(f));
	f[1][0]=1;
	f[1][1]=1;
	for (int k=2;k<=n;k++)
	{
		f[k][0]=1;
		for (int c=1;c<=n;c++)
		{
			int64 s1=0;
			for (int i=0;i<=c;i++) s1=ck(s1+f[k-1][i]*f[k-1][c-i]%MOD*(i*4+1));
			for (int i=0;i<=c-1;i++) s1=ck(s1+f[k-1][i]*f[k-1][c-1-i]);
			int64 s2=0;
			int64 s3=0;
			int64 s4=0;
			for (int i=1;i<=c+1;i++)
			{
				int64 e=f[k-1][i]*f[k-1][c+1-i]%MOD;
				int d=0;
				if (i>=2) d+=i*(i-1);
				if (i<=c) d+=i*(c+1-i);
				s4=ck(s4+e*d);
			}
			f[k][c]=ck(s1+s2*2+s3*2+s4*2);
		}
		//cout<<k<<" "<<f[k][1]<<" "<<f[k][2]<<endl;
	}
	cout<<f[n][1]<<endl;
	return 0;
}