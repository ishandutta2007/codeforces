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

const int SIZE=2048;
using bset=bitset<SIZE>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		vector<bset> f(two(n));
		f[0][0]=1;
		FOR(set,1,two(n))
		{
			bset& w=f[set];
			REP(i,n) if (contain(set,i)) w|=(f[set^two(i)]<<a[i]);
			for (int i=(SIZE-1)/m;i>0;i--) if (f[set][i*m]) f[set][i]=1;
		}
		if (f[two(n)-1][1])
		{
			int set=two(n)-1;
			int target=1;
			int cnt=0;
			VI c(n);
			for (;set>0;)
			{
				int ok=0;
				REP(i,n) if (contain(set,i))
				{
					for (int k=target,e=0;k<SIZE;k*=m,++e) if (k>=a[i] && f[set^two(i)][k-a[i]]) 
					{
						cnt+=e;
						c[i]=cnt;
						target=k-a[i];
						set^=two(i);
						ok=1;
						break;
					}
					if (ok) break;
				}
				assert(ok);
			}
			printf("YES\n");
			REP(step,n-1)
			{
				int ok=0;
				REP(x,n) FOR(y,x+1,n) if (!ok && c[x]>=0 && c[y]>=0 && c[x]==c[y])
				{
					ok=1;
					printf("%d %d\n",a[x],a[y]);
					c[y]=-1;
					a[x]+=a[y];
					for (;a[x]%m==0;a[x]/=m) --c[x];
				}
				assert(ok);
			}
		}
		else
			printf("NO\n");
#ifndef _MSC_VER
		break;
#endif
		printf("\n");
	}
	return 0;
}