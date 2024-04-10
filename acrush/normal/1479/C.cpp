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

void solve(int l,int r)
{
	int m=r-l+1;
	vector<VI> ret;
	VI w(32);
	w[0]=1;
	FOR(k,1,32)
	{
		int s=0;
		REP(i,k) s+=w[i];
		int p=1;
		ret.push_back({0,k,1});
		for (int i=k-1;i>0;i--)
			if (p+w[i]<=m)
			{
				ret.push_back({i,k,p});
				p+=w[i];
			}
		if (p==m)
		{
			printf("YES\n");
			printf("%d %d\n",k+1,SIZE(ret));
			for (auto x:ret) 
			{
				if (x[0]==0) x[2]+=(l-1);
				printf("%d %d %d\n",x[0]+1,x[1]+1,x[2]);
			}
			break;
		}
		w[k]=p;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int l,r;
	while (cin>>l>>r)
	{
		solve(l,r);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}