#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

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


using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

class UnionFind{
	int n;
	vector<int> par;
	vector<int> rank;
public:
	UnionFind(){ }
	UnionFind(int size){ reset(size); }

	void reset(int size){
		n = size;
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
		n--;
	}

	bool same(int x,int y){return find(x) == find(y);}

	int size() {return n;}
};

int main(){
	int n,m; cin>>n>>m;
	UnionFind uf(n);
	FOR(i,m){
		int x,y; cin>>x>>y; x--;y--;
		uf.unite(x,y);
	}

	map<int,vector<int> > mp;
	FOR(i,n) mp[uf.find(i)].push_back(i);
	vector<vector<int> > combi[4];
	for(map<int,vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it){
		if(sz(it->second) > 3){
			puts("-1");
			return 0;
		}
		combi[sz(it->second)].push_back(it->second);
	}

	vector<vector<int> > ans;
	if(sz(combi[2]) > sz(combi[1]) || (sz(combi[1]) - sz(combi[2])) % 3 != 0){
		puts("-1");
		return 0;
	}
	FOR(i,sz(combi[3])){
		ans.push_back(combi[3][i]);
	}
	FOR(i,sz(combi[2])){
		ans.push_back(combi[2][i]);
		ans.back().push_back(combi[1][i][0]);
	}

	for(int i = sz(combi[2]); i < sz(combi[1]); i += 3){
		ans.push_back(vector<int>());
		ans.back().push_back(combi[1][i][0]);
		ans.back().push_back(combi[1][i+1][0]);
		ans.back().push_back(combi[1][i+2][0]);
	}

	FOR(i,sz(ans)){
		printf("%d %d %d\n",ans[i][0] + 1,ans[i][1] + 1,ans[i][2] + 1);
	}

	return 0;
}