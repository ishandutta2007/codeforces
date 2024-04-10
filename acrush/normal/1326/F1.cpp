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
	int n;
	while (cin>>n)
	{
		vector<VI> g(n,VI(n));
		REP(i,n)
		{
			string s;
			cin>>s;
			REP(j,n) g[i][j]=(s[j]-'0');
		}
		VI cb(two(n));
		FOR(i,1,two(n)) cb[i]=cb[i/2]+i%2;
		vector<int64> ret(two(n-1));
		REP(p,n)
		{
			VI a;
			REP(i,n) if (i!=p) a.push_back(i);
			REP(set,two(n-1))
				if (cb[set]==(n-1)/2)
				{
					if (p==0)
					{
						if (n%2==1 && !contain(set,0)) continue;
					}
					else
					{
						if (!contain(set,0)) continue;
					}
					VI b1,b2;
					REP(i,n-1) 
						if (contain(set,i)) b1.push_back(a[i]);
						else b2.push_back(a[i]);
					auto solve=[&](int s,VI a,int rev) -> VI {
						int n=SIZE(a);
						VI p(n);
						REP(i,n) p[i]=i;
						VI ret(two(n));
						do{
							int w=0,l=s;
							REP(i,n)
							{
								int z=a[p[i]];
								if (g[l][z]) w|=two(rev?n-1-i:i);
								l=z;
							}
							++ret[w];
						} while (next_permutation(ALL(p)));
						return ret;
					};
					VI e1=solve(p,b1,1);
					VI e2=solve(p,b2,0);
					REP(i,SIZE(e1)) REP(j,SIZE(e2)) ret[i+j*SIZE(e1)]+=(int64)e1[i]*e2[j];
				}
		}
		auto saved_ret=ret;
		REP(set,SIZE(ret))
		{
			int new_set=0;
			REP(i,n-1) if (contain(set,i)) new_set|=two(n-2-i);
			ret[new_set]+=saved_ret[set];
		}

		REP(i,SIZE(ret)) printf("%lld ",ret[i]);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}