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

vector<ipair> edges;
int cnt_query=0;

int query(const VI& s,const VI& t,int v)
{
	if (SIZE(s)==0 || SIZE(t)==0) return 0;
#ifdef _MSC_VER
	assert(SIZE(s)>0 && SIZE(t)>0);
	cnt_query++;
	int ret=0;
	for (int x:s) for (int y:t) if (v>=min(x,y) && v<=max(x,y)) ++ret;
	return ret;
#endif
	printf("%d\n",SIZE(s));
	for (int z:s) printf("%d ",z+1);
	printf("\n");
	printf("%d\n",SIZE(t));
	for (int z:t) printf("%d ",z+1);
	printf("\n");
	printf("%d\n",v+1);
	fflush(stdout);
	int r;
	cin>>r;
	return r;
}

struct Node
{
	int key;
	vector<int> a;
	vector<Node*> sub_nodes;
};

int find_link(int target,Node* node)
{
	if (node->key<0)
	{
		vector<int> a=node->a;
		random_shuffle(ALL(a));
		for (int x:a)
		{
			vector<int> s;
			for (int y:a) if (x!=y) s.push_back(y);
			if (query({target},s,x)==SIZE(s)) return x;
		}
		return -1;
	}
	int m=SIZE(node->sub_nodes);
	if (m==1)
	{
		if (query({target},node->sub_nodes[0]->a,node->key)==SIZE(node->sub_nodes[0]->a)) return node->key;
		return find_link(target,node->sub_nodes[0]);
	}
	int low,high;
	vector<int> s;
	REP(i,m/2) s.insert(s.end(),ALL(node->sub_nodes[i]->a));
	if (query({target},s,node->key)!=SIZE(s))
		low=0,high=m/2;
	else
	{
		s.clear();
		FOR(i,m/2,m) s.insert(s.end(),ALL(node->sub_nodes[i]->a));
		if (query({target},s,node->key)!=SIZE(s))
			low=m/2,high=m;
		else
			return node->key;
	}
	for (;low+1<high;)
	{
		int mid=(low+high)/2;
		vector<int> s;
		FOR(i,low,mid) s.insert(s.end(),ALL(node->sub_nodes[i]->a));
		if (query({target},s,node->key)==SIZE(s))
			low=mid;
		else
			high=mid;
	}
	return find_link(target,node->sub_nodes[low]);
}

Node* solve(vector<int> a)
{
	random_shuffle(ALL(a));
	Node* node=new Node();
	node->a=a;
	node->key=-1;
	int n=SIZE(a);
	if (n<=1) return node;
	if (n==2)
	{
		edges.emplace_back(a[0],a[1]);
		return node;
	}
	int key=-1,max_c=-1;
	for (int x:a)
	{
		vector<int> s;
		for (int y:a) if (x!=y) s.push_back(y);
		random_shuffle(ALL(s));
		vector<int> s1(s.begin(),s.begin()+SIZE(s)/2),s2(s.begin()+SIZE(s)/2,s.end());
		int c=query(s1,s2,x);
		if (c>max_c) max_c=c,key=x;
	}
	node->key=key;
	vector<int> p;
	vector<vector<int>> d;
	for (int x:a) if (x!=key)
	{
		if (SIZE(p)==0 || query(p,{x},key)==SIZE(p))
		{
			p.push_back(x);
			d.push_back({x});
		}
		else
		{
			int low=0,high=SIZE(p);
			for (;low+1<high;)
			{
				int mid=(low+high)/2;
				vector<int> s(p.begin()+low,p.begin()+mid);
				if (query({x},s,key)==SIZE(s))
					low=mid;
				else
					high=mid;
			}
			d[low].push_back(x);
		}
	}
	REP(i,SIZE(p)) node->sub_nodes.push_back(solve(d[i]));
	REP(i,SIZE(p)) 
	{
		int x=find_link(key,node->sub_nodes[i]);
		edges.emplace_back(key,x);
	}
	return node;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	REP(i,n) a.push_back(i);
	edges.clear();
	solve(a);
	printf("ANSWER\n");
	for (auto e:edges) printf("%d %d\n",e.first+1,e.second+1);
	fflush(stdout);
#ifdef _MSC_VER
	assert(SIZE(edges)==n-1);
	printf("cnt_query = %d\n",cnt_query);
#endif
	return 0;
}