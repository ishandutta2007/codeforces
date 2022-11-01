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

inline int op(int set,int a,int b)
{
	if (CKBIT(set,a)!=CKBIT(set,b)) set^=POW2(a)^POW2(b);
	return set;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m,k;
	while (cin>>n>>m>>k)
	{
		string s1,s2;
		cin>>s1>>s2;
		int set1=0,set2=0;
		REP(i,k) if (s1[i]=='1') set1|=POW2(i);
		REP(i,k) if (s2[i]=='1') set2|=POW2(i);
		VI p1(n),p2(n);
		REP(i,n) { cin>>p1[i]>>p2[i]; --p1[i]; --p2[i]; }
		VI f(POW2(k),k+1);
		VI g(POW2(k),-1);
		VI que;
		auto add=[&](int set,int d,int key) {
			if (d>=f[set]) return;
			f[set]=d;
			g[set]=key;
			que.push_back(set);
		};
		VI ret{k+1};
		vector<VI> pets(n+1,VI(k));
		REP(i,k) pets[n][i]=i;
		for (int i=n-1;i>=0;i--) { pets[i]=pets[i+1]; swap(pets[i][p1[i]],pets[i][p2[i]]); }
		for (int i=n-1;i>=0;i--)
		{
			if (i+m<=n)
			{
				int keyset2=0;
				REP(p,k) if (CKBIT(set2,p)) keyset2|=POW2(pets[i+m][p]);
				que.clear();
				add(keyset2,0,i+m-1);
				REP(cl,SIZE(que))
				{
					int set=que[cl];
					REP(p,k) add(set^POW2(p),f[set]+1,g[set]);
				}
			}
			int keyset1=0;
			REP(p,k) if (CKBIT(set1,p)) keyset1|=POW2(pets[i][p]);
			ret=min(ret,VI{f[keyset1],i,g[keyset1]});
		}
		printf("%d\n%d %d\n",k-ret[0],ret[1]+1,ret[2]+1);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}