#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		vector<int64> c(16);		
		REP(i,n)
		{
			int x0,y0;
			cin>>x0>>y0;
			x0%=4;
			y0%=4;
			++c[x0*4+y0];
		}
		VVI g(16,VI(16));
		REP(i,16) REP(j,16) g[i][j]=g[j][i]=gcd(abs(i/4-j/4),abs(i%4-j%4))/2;
		int64 ret=0;
		REP(i,16) if (c[i]) FOR(j,i,16) if (c[j]) FOR(k,j,16) if (c[k])
			if ((g[i][j]+g[j][k]+g[k][i])%2==0)
				if (i==j && j==k)
					ret+=c[i]*(c[i]-1)*(c[i]-2)/6;
				else if (i==j)
					ret+=c[k]*c[i]*(c[i]-1)/2;
				else if (j==k)
					ret+=c[i]*c[j]*(c[j]-1)/2;
				else
					ret+=c[i]*c[j]*c[k];
		printf("%lld\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}