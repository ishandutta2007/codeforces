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
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

class UnionFind {
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
		for (int i = 0; i < size; i++) par[i] = i, rank[i] = 0;
	}

	int find(int x){
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x), y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		n--;
	}

	bool same(int x, int y){ return find(x) == find(y); }

	int size() { return n; }
};

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	FOR(i, n) cin >> v[i];
	FOR(i, n) v[i]--;
	UnionFind uf(n);
	FOR(i, n){
		string s; cin >> s;
		FOR(j, n) if (s[j] == '1') uf.unite(i, j);
	}
	bool used[300] = {};
	FOR(i, n - 1){
		int ch = -1;
		FOR(j, n){
			if (used[j]) continue;
			int chidx = find(v.begin(), v.end(), j) - v.begin();
			if (uf.same(i,chidx) ) {
				ch = j;
				break;
			}
		}
		used[ch] = true;
		int chidx = find(v.begin(), v.end(), ch) - v.begin();
		swap(v[i], v[chidx]);
	}

	FOR(i, n) printf("%d ", v[i] + 1);
	puts("");
}