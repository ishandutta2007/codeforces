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

int n;
int x[100],y[100];

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

vector<int> vx[1010];
vector<int> vy[1010];


int main()
{
	int n; cin>>n;
	FOR(i,n){
		int x,y;
		cin>>x>>y;
		vx[x].push_back(i);
		vy[y].push_back(i);
	}

	UnionFind u(n);
	FOR(i,1010){
		FOR(j,vx[i].size()) u.unite(vx[i][0],vx[i][j]);
		FOR(j,vy[i].size()) u.unite(vy[i][0],vy[i][j]);
	}

	set<int> s;
	FOR(i,n) s.insert(u.find(i));
	cout << s.size() - 1 << endl;

	return 0;
}