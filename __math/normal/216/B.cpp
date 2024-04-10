#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
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
#include <list>
#include <iomanip>
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)


class UnionFind{
	vector<int> par;
	vector<int> rank;
public:
	UnionFind(){ }
	UnionFind(int size){ reset(size); }

	void reset(int size){
		par.resize(size);
		rank.resize(size);
		for(int i = 0; i < size; i++) par[i] = i,rank[i] = 0;
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

int main()
{

	int n,m; cin>>n>>m;
	UnionFind u(n);
	vector<int> c(n);
	FOR(i,m){
		int x,y; cin>>x>>y;
		x--; y--;
		u.unite(x,y);
		c[x]++; c[y]++;
	}

	map<int,vector<int> >mp;
	FOR(i,n){
		mp[u.find(i)].push_back(i);
	}

	int ans = 0;
	for(map<int,vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it){
		vector<int>& v = (*it).second;
		if(v.size() % 2 == 0) continue;
		int h = 0;
		for(int i = 0; i < v.size(); i++){
			h += c[v[i]];
		}
		if(h == v.size() * 2) ans++;
	}

	if((n - ans) % 2 == 1) ans++;
	cout << ans << endl;

	return 0;
}