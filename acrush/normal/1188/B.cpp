#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

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
using VI=vector<int>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int64 n,p,k;
	while (cin>>n>>p>>k)
	{
		unordered_map<int64,int64> c;
		REP(i,n) 
		{ 
			int x; 
			cin>>x;
			int64 d=x;
			int64 d2=d*d%p; 
			int64 d4=d2*d2%p;
			++c[((d4-d*k)%p+p)%p];
		}
		int64 ret=0;
		for (auto w:c) ret+=w.second*(w.second-1)/2;
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}