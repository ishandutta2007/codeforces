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
const unsigned int MODULO = 1000000007;
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

bool used[100];

int main(){
	int n,m; cin>>n>>m;

	UnionFind uf;
	uf.reset(m);

	int lan_zero = 0;

	FOR(i,n){
		int k ; cin>>k;
		if(k == 0){
			lan_zero++;
		}
		static int ax[100];
		FOR(j,k){
			int a; cin>>a; a--;
			used[a] = true;
			ax[j] = a;
		}
		FOR(j,k-1){
			uf.unite(ax[j],ax[j+1]);
		}
	}

	int unused = 0;
	FOR(i,m) if(!used[i]) unused++;

	int add = uf.size() - unused - 1;
	add = max(0,add);
	int ans = add + lan_zero;

	cout << ans << endl;

	return 0;
}