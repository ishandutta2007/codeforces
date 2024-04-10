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

const int maxn=(1<<18);

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string str;
	cin>>str;
	vector<int> s[20];
	vector<int> a(n-1);
	REP(i,n-1) a[i]=(int)(str[i]==str[i+1]);
	REP(k,20)
	{
		s[k].resize(SIZE(a));
		int d=(1<<k);
		REP(i,SIZE(a))
		{
			s[k][i]=a[i];
			if (i>=d) s[k][i]+=s[k][i-d];
		}
	}
	int nq;
	for (cin>>nq;nq>0;nq--)
	{
		int l,r;
		cin>>l>>r;
		++r;
		int ret=0;
		for (int k=0;two(k)<r-l;k++)
		{
			int d=two(k);
			int c0=s[k+1][r-d-1];
			if (l-d-1>=0) c0-=s[k+1][l-d-1]; 
			int s0=(r-l)/(d*2);
			ret+=min(c0,s0-c0);
		}
		printf("%d\n",(ret+1)/2);
	}
	return 0;
}