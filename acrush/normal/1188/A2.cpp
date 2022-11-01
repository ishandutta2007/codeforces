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

vector<VI> g;
map<ipair,int> w;
vector<pair<ipair,int>> ret;

ipair make_key(int a,int b)
{
	if (a>b) swap(a,b);
	return MP(a,b);
}
int get_one_leave(int p,int prev)
{
	for (int x:g[p]) if (x!=prev) return get_one_leave(x,p);
	return p;
}
int dfs(int p,int prev,int target,int delta)
{
	if (p==target) return 1;
	for (int x:g[p]) if (x!=prev)
	{
		int z=dfs(x,p,target,delta);
		if (z) 
		{
			w[make_key(p,x)]-=delta;
			return 1;
		}
	}
	return 0;
}
void update(int s,int t,int delta)
{
	if (s>t) swap(s,t);
	if (delta==0) return;
	ret.push_back(MP(MP(s,t),delta));
	// printf("%d %d %d\n",s+1,t+1,delta);
	dfs(s,-1,t,delta);
}
void solve(int a,int b)
{
	// printf("SOLVE %d %d\n",a,b);
	if (SIZE(g[a])>SIZE(g[b])) swap(a,b);
	VI pa,pb;
	for (int x:g[a]) if (x!=b)
	{
		int t=get_one_leave(x,a);
		pa.push_back(t);
		if (SIZE(pa)>=2) break;
	}
	if (SIZE(pa)==0) pa.push_back(a);
	for (int x:g[b]) if (x!=a)
	{
		int t=get_one_leave(x,b);
		pb.push_back(t);
		if (SIZE(pb)>=2) break;
	}
	int z=w[make_key(a,b)];
	if (SIZE(pa)==1 && SIZE(pb)==2)
	{
		update(pa[0],pb[0],z/2);
		update(pa[0],pb[1],z/2);
		update(pb[0],pb[1],-z/2);
	}
	else
	{
		update(pa[0],pb[0],z/2);
		update(pa[1],pb[1],z/2);
		update(pa[0],pa[1],-z/2);
		update(pb[0],pb[1],-z/2);
	}
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
		g=vector<VI>(n);
		w.clear();
		REP(i,n-1)
		{
			int a,b,c;
			cin>>a>>b>>c;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
			w[make_key(a,b)]=c;
		}
		int ok=1;
		REP(i,n) if (SIZE(g[i])==2) ok=0;
		if (ok)
		{
			printf("YES\n");
			if (n==2)
			{
				printf("1\n");
				printf("%d %d %d\n",1,2,w[make_key(0,1)]);
			}
			else
			{
				ret.clear();
				REP(i,n) for (int j:g[i]) if (w[make_key(i,j)]!=0)
					solve(i,j);
				printf("%d\n",SIZE(ret));
				for (auto w:ret)
					printf("%d %d %d\n",w.first.first+1,w.first.second+1,w.second);
			}
		}
		else
			printf("NO\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}