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

int query(int x,int y)
{
	printf("? %d %d\n",x+1,y+1);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}

namespace scc {

VI index;
VI low;
VI in_stack;
stack<int> s;
int counter;
vector<VI> components;

void dfs(const vector<VI>& g, int v)
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
		VI component;
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

vector<VI> tarjan(const vector<VI>& g)
{
	int n=SIZE(g);
	index=VI(n,-1);
	low=VI(n);
	in_stack=VI(n,0);
	s=stack<int>();
	components.clear();
	counter=0;
	for (int i=0;i<n;i++) if (index[i]<0) dfs(g,i);
	return components;
}

}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<VI> g(n);
	REP(i,m)
	{
		int a,b;
		cin>>a>>b;
		--a; --b;
		g[a].push_back(b);
	}
	vector<VI> sc=scc::tarjan(g);
	VI idx(n);
	m=SIZE(sc);
	vector<VI> g2(m);
	REP(i,m) for (int x:sc[i]) idx[x]=i;
	REP(i,n) for (int x:g[i]) if (idx[i]!=idx[x]) g2[idx[i]].push_back(idx[x]);
	VI in_deg(m);
	REP(i,m) for (int x:g2[i]) ++in_deg[x];
	VI que;
	REP(i,m) if (in_deg[i]==0) que.push_back(i);
	int key=que[0];
	REP(cl,SIZE(que))
	{
		int other=que[cl];
		if (key==other) continue;
		while (SIZE(sc[key])>0 && SIZE(sc[other])>0)
			if (query(sc[key].back(),sc[other].back()))
				sc[other].pop_back();
			else
				sc[key].pop_back();
		if (SIZE(sc[key])==0) swap(key,other);
		for (int x:g2[other]) if ((--in_deg[x])==0) que.push_back(x);
	}
	printf("! %d\n",sc[key].back()+1);
	fflush(stdout);
	return 0;
}