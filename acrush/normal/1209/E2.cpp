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
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n,m;
		cin>>n>>m;
		vector<VI> a(m,VI(n));
		REP(i,n) REP(j,m) cin>>a[j][i];
		VI b(m);
		REP(i,m) REP(j,n) ckmax(b[i],a[i][j]);
		vector<ipair> q(m);
		REP(i,m) q[i]=MP(b[i],i);
		sort(ALL(q));
		reverse(ALL(q));
		if (m>n) { q.resize(n); m=n; }
		VI f(two(n));
		REP(cl,m)
		{
			VI g=a[q[cl].second];
			VI f2=f;
			REP(set,two(n))
			{
				int w=0;
				REP(rot,n)
				{
					int s=0;
					REP(i,n) if (contain(set,i)) s+=g[(i+rot)%n];
					ckmax(w,s);
				}
				int uset=two(n)-1-set;
				for (int subset=uset;;subset=(subset-1)&uset)
				{
					ckmax(f2[set|subset],f[subset]+w);
					if (subset==0) break;
				}
			}
			f.swap(f2);
		}
		printf("%d\n",f.back());
	}
	return 0;
}