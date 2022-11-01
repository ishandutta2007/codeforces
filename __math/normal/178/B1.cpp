#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define all(c) (c).begin(),(c).end()
#define FILL(c,val) memset((c),val,sizeof(c))

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

template<int size>
class UnionFind{
	int par[size];
	int rank[size];
public:
	UnionFind(){ reset(); }

	void reset(){
		FOR(i,size) par[i] = i,rank[i] = 0;
	}

	int find(int x){
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x,int y){
		x = find(x),y = find(y);
		if(x == y) return ;
		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x,int y){return find(x) == find(y);}
};

UnionFind<100000> u;
int n,m,k;
vector<int> v[100000];
vector<int> v2[100000];
bool use[100000];
vector<int> use_num;
stack<int> st;

void Unit(int x)
{
	stack<int> s(st);
	while(s.top() != x){
		u.unite(x,s.top());
		s.pop();
	}
}

void connect(int x)
{
	st.push(x);
	int next =st.top();
	use[next] = true;
	use_num.push_back(next);
	FOREACH(it,v[next]){
		vector<int>::iterator i = find(v[*it].begin(),v[*it].end(),next);
		if(i != v[*it].end())
			v[*it].erase(i);
		if(use[*it]){
			Unit(*it);
		} else {
			connect(*it);
		}
	}
	st.pop();
}

class GT{
public:
	bool operator ()(const Pii& x, const Pii &y)
	{
		return less<int>()(x.second,y.second);
	}
};

int get_len(int l,int s)
{
	memset(use,0,sizeof(use));
	priority_queue<Pii,vector<Pii>,GT> q;
	q.push(Pii(l,0));
	while(!q.empty()){
		Pii next = q.top(); q.pop();
		if(use[next.first])
			continue;
		if(next.first == s)
			return next.second;
		use[next.first] = true;
		FOREACH(it,v2[next.first]){
			if(!use[(*it)]){
				int len = next.second;
				if(!u.same(next.first,*it))
					len++;
				q.push(Pii(*it,len));
			}
		}
	}

	return -1;
}

int main(){
	iostream::sync_with_stdio(false);

	cin>>n>>m;
	FOR(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b); v[b].push_back(a);
		v2[a].push_back(b); v2[b].push_back(a);
	}
	connect(0);

	cin>>k;
	FOR(i,k){
		int s,l;
		cin>>s>>l; s--,l--;
		int ans = get_len(s,l);
		cout << ans << endl;
	}

	return 0;
}