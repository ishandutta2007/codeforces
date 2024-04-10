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

int getf(VI& f,int p)
{
	return (f[p]<0)?p:(f[p]=getf(f,f[p]));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n;
		cin>>n;
		VI next(n);
		REP(i,n) cin>>next[i];
		VI f(n+2,-1);
		vector<VI> g(n);
		for (int i=n-1;i>=0;i--) if (next[i]>=0)
		{
			int k=next[i]-1;
			if (k<n) g[i].push_back(k);
			for (int j=getf(f,i+1);j<k;j=getf(f,j))
			{
				g[j].push_back(i);
				f[j]=j+1;
			}
		}
		VI d(n);
		REP(x,n) for (int y:g[x]) ++d[y];
		VI q;
		REP(x,n) if (d[x]==0) q.push_back(x);
		REP(cl,SIZE(q)) for (int x:g[q[cl]]) if ((--d[x])==0) q.push_back(x);
		if (SIZE(q)==n)
		{
			VI r(n);
			REP(i,n) r[q[i]]=i;
			REP(i,n) { if (i>0) printf(" "); printf("%d",r[i]+1); }
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}