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
using VI=vector<int64>;

int64 n;
vector<VI> g;
VI s;
VI w;
int64 ret;

int64 C2(int64 n)
{
	return (n<2)?0:n*(n-1);
}
int64 outer(pair<int64,int64> p0,pair<int64,int64> p1,pair<int64,int64> p2)
{
	return (p1.first-p0.first)*(p2.second-p0.second)-(p2.first-p0.first)*(p1.second-p0.second);
}
void dfs(int p,int prev)
{
	s[p]=1;
	VI c;
	for (int x:g[p]) if (x!=prev) { c.push_back(x); dfs(x,p); s[p]+=s[x]; }

	for (int x:c) 
		ckmin(ret,w[x]+C2(n-s[x]));
	map<int64,int64> tree;
	// for (int x:c) for (int y:c) if (x!=y) ckmin(ret,w[x]+w[y]+C2(n-s[x]-s[y]));
	for (int x:c)
	{
		// for (auto t:tree) ckmin(ret,w[x]+t.second+C2(n-s[x]-t.first));
		if (!tree.empty())
		{
			int64 low=tree.begin()->first,high=(--tree.end())->first;
			auto eval=[&](int64 s0) {
				auto it=tree.upper_bound(s0);
				assert(it!=tree.begin());
				--it;
				return w[x]+it->second+C2(n-s[x]-it->first);
			};
			for (;high-low>2;)
			{
				int64 m1=(low*2+high)/3;
				int64 m2=(low+high*2)/3;
				int64 t1=eval(m1);
				int64 t2=eval(m2);
				ckmin(ret,t1);
				ckmin(ret,t2);
				if (t1<t2)
					high=m2;
				else
					low=m1;
			}
			for (int i=low;i<=high;i++) ckmin(ret,eval(i));
		}

		auto it=tree.find(s[x]);
		if (it!=tree.end())
		{
			if (w[x]>=it->second) continue;
			it->second=w[x];
		}
		else
			it=tree.insert(MP(s[x],w[x])).first;
		if (it!=tree.begin() && it!=(--tree.end()))
		{
			auto it1=it; --it1;
			auto it2=it; ++it2;
			if (outer(*it1,*it,*it2)<=0)
			{
				tree.erase(it);
				continue;
			}
		}
		while (1)
		{
			it=tree.find(s[x]);
			if (it==tree.begin()) break;
			auto it1=it; --it1;
			if (it1==tree.begin()) break;
			auto it2=it1; --it2;
			if (outer(*it2,*it1,*it)>0) break; 
			tree.erase(it1);
		}
		while (1)
		{
			it=tree.find(s[x]);
			auto it1=it; ++it1;
			if (it1==tree.end()) break;
			auto it2=it1; ++it2;
			if (it2==tree.end()) break;
			if (outer(*it,*it1,*it2)>0) break; 
			tree.erase(it1);
		}
	}

	w[p]=C2(s[p]);
	for (int x:g[p]) if (x!=prev) ckmin(w[p],w[x]+C2(s[p]-s[x]));
}
int main()
{
#ifdef _MSC_VER
	// freopen("input.txt","r",stdin);
	freopen("big.txt","r",stdin);
	int hcode=0;
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		g=vector<VI>(n);
		REP(i,n-1)
		{
			int a,b;
			cin>>a>>b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ret=(1LL<<60);
		s=VI(n);
		w=VI(n);
		dfs(0,-1);
		ret/=2;
		int64 c1=ret;
		int64 c2=n*(n-1)/2-c1;
		ret=c1+c2*2;
		cout<<ret<<endl;
#ifdef _MSC_VER
		//hcode=hcode*3137+ret;
#else
		break;
#endif
	}
#ifdef _MSC_VER
	//printf("hcode = %d\n",hcode);
#endif
	return 0;
}