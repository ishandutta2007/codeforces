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
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;

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


int n,l,d;
bool dis[2000][2000];
bool b[2000];

bool check(vector<int> &v)
{
	for(int i = 0; i < sz(v); i++){
		for(int j = i + 1; j < sz(v); j++){
			if(dis[v[i]][v[j]]) return false;
		}
	}
	return true;
}

int main()
{
	UnionFind<2000> u;
	cin>>n;
	cin>>l;
	FOR(i,l){
		int a,b; cin>>a>>b;
		u.unite(a-1,b-1);
	}
	cin>>d;
	FOR(i,d){
		int a,b; cin>>a>>b;
		dis[a-1][b-1] = 1;
		dis[b-1][a-1] = 1;
	}

	int ans = 0;

	vector<int> v;
	FOR(i,n){
		if(b[i]) continue;
		v.clear();
		FOR(j,n)
			if(u.same(i,j))
				v.push_back(j);
		FOREACH(it,v) b[*it] = true;
		if(check(v)) ans = max(ans,sz(v));
	}

	cout <<ans<<endl;

	return 0;
}