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

const int MAXN=18;

int n;
vector<VI> g;
vector<int64> ret;
VI cb;
VI pset[32];
int64 f[two(MAXN)][MAXN];

void dfs(int current,VI& segs)
{
	if (current==n)
	{
		int64 cnt=0;
		REP(i,n) cnt+=f[two(n)-1][i];
		if (cnt==0) return;
		VI p=segs;
		reverse(ALL(p));
		do{
			int set=0,s=0;
			for (int l:p) set|=((two(l-1)-1)<<s),s+=l;
			ret[set]+=cnt;
		} while (next_permutation(ALL(p)));
		return;
	}
	if (!segs.empty() && (SIZE(segs)==1 || segs[SIZE(segs)-1]+1<=segs[SIZE(segs)-2]))
	{
		for (int set:pset[current+1]) memset(f[set],0,sizeof(f[set]));
		for (int set:pset[current]) REP(i,n)
		{
			int64 t=f[set][i];
			if (!t) continue;
			REP(j,n) if (!contain(set,j) && g[i][j]) f[set|two(j)][j]+=t;
		}
		++segs[SIZE(segs)-1];
		dfs(current+1,segs);
		--segs[SIZE(segs)-1];
	}
	for (int set:pset[current+1]) memset(f[set],0,sizeof(f[set]));
	for (int set:pset[current]) 
	{
		int64 s=0;
		REP(i,n) s+=f[set][i];
		if (s) REP(j,n) if (!contain(set,j)) f[set|two(j)][j]+=s;
	}
	segs.push_back(1);
	dfs(current+1,segs);
	segs.pop_back();
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		cb=VI(two(n));
		FOR(set,1,two(n)) cb[set]=cb[set/2]+set%2;
		REP(i,n+1) pset[i].clear();
		REP(set,two(n)) pset[cb[set]].push_back(set);
		g=vector<VI>(n,VI(n));
		REP(i,n)
		{
			string s;
			cin>>s;
			REP(j,n) g[i][j]=(s[j]-'0');
		}
		REP(i,n) g[i][i]=0;
		ret=vector<int64>(two(n-1));
		VI segs;
		memset(f[0],0,sizeof(f[0]));
		f[0][0]=1;
		dfs(0,segs);
		REP(k,n-1) for (int set=two(n-1)-1;set>=0;set--) if (!contain(set,k)) ret[set]-=ret[set|two(k)];
		REP(i,SIZE(ret)) printf("%lld ",ret[i]);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}