#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

namespace scc {

vector<int> index;
vector<int> low;
vector<int> in_stack;
stack<int> s;
int counter;
vector<vector<int>> components;

void dfs(const vector<vector<int>>& g, int v)
{
	index[v] = low[v] = counter++;
	s.push(v);
	in_stack[v] = 1;
	for (int w : g[v]) if (w != v)
		if (index[w] < 0)
		{
			dfs(g, w);
			low[v] = min(low[v], low[w]);
		}
		else if (in_stack[w])
			low[v] = min(low[v], index[w]);
	if (index[v] == low[v])
	{
		vector<int> component;
		int w;
		do{
			w = s.top();
			s.pop();
			in_stack[w] = 0;
			component.push_back(w);
		}while (w != v);
		components.emplace_back(std::move(component));
	}
}

vector<vector<int>> tarjan(const vector<vector<int>>& g)
{
	int n=SIZE(g);
	index=vector<int>(n,-1);
	low=vector<int>(n);
	in_stack=vector<int>(n,0);
	s=stack<int>();
	components.clear();
	counter=0;
	for (int i=0;i<n;i++) if (index[i]<0) dfs(g,i);
	return components;
}

}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m,d;
	while (cin>>n>>m>>d)
	{
		vector<VI> g(n);
		REP(i,m)
		{
			int a,b;
			cin>>a>>b;
			--a; --b;
			g[a].push_back(b);
		}
		vector<string> pattern(n);
		REP(i,n) cin>>pattern[i];

		vector<VI> c=scc::tarjan(g);
		m=SIZE(c);
		VI idx(n);
		REP(i,m) for (int x:c[i]) idx[x]=i;
		vector<VI> g2(m);
		REP(i,n) for (int j:g[i]) if (idx[i]!=idx[j]) g2[idx[i]].push_back(idx[j]);
		VI in_deg(m);
		REP(i,m) for (int j:g2[i]) ++in_deg[j];
		VI que;
		int ret=0;
		REP(i,m) if (in_deg[i]==0) que.push_back(i);
		vector<VI> f(n,VI(d,-1));
		vector<VI> visited(n,VI(d));
		ckmax(f[0][0],0);
		int counter=0;
		VI mark(n);
		int mark_counter=0;
		VI offset(n);
		REP(cl,SIZE(que))
		{
			int c_idx=que[cl];
			for (int x:g2[c_idx]) if ((--in_deg[x])==0) que.push_back(x);
			int key=c[c_idx][0];

			++mark_counter;
			for (int x:c[c_idx]) mark[x]=mark_counter;
			++counter;
			visited[key][0]=counter;
			vector<ipair> que2;
			que2.emplace_back(key,0);
			REP(cl2,SIZE(que2))
			{
				int pt=que2[cl2].first,delta=(que2[cl2].second+1)%d;
				for (int x:g[pt]) 
					if (mark[x]==mark_counter && visited[x][delta]!=counter)
					{
						visited[x][delta]=counter;
						que2.emplace_back(x,delta);
					}
			}
			int l=d;
			FOR(i,1,d) if (visited[key][i]==counter) { l=i; break; }
			for (int x:c[c_idx])
			{
				int delta=0;
				for (;visited[x][delta]!=counter;++delta);
				offset[x]=(l-delta%l)%l;
			}
			VI f2(l,-1);
			for (int x:c[c_idx]) REP(i,d) if (f[x][i]>=0) ckmax(f2[(i+offset[x])%l],f[x][i]);
			for (int x:c[c_idx]) REP(i,l)
			{
				bool ok=false;
				for (int j=i;j<d;j+=l) if (pattern[x][j]=='1') ok=true;
				if (ok)
				{
					int j=(i+offset[x])%l;
					if (f2[j]<0) continue;
					++f2[j];
				}
			}
			REP(delta,l) if (f2[delta]>=0) ckmax(ret,f2[delta]);
			for (int x:c[c_idx]) REP(i,d)
			{
				int j=(i+offset[x])%l;
				if (f2[j]<0) continue;
				for (int y:g[x]) if (idx[x]!=idx[y]) ckmax(f[y][(i+1)%d],f2[j]);
			}
		}
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}