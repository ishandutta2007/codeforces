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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll a[3 * ten(5)];
vector<int> e[ten(5)],re[ten(5)];

const int MAX_V = ten(5);
int n;
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void dfs(int v) {
	used[v] = true;
	for(auto p : e[v]) if(!used[p]){
		dfs(p);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (auto p : re[v]) if (!used[p]) {
		rdfs(p, k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	FOR(v, n) if (!used[v]) dfs(v);
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}


int main() {
	cin >> n;
	FOR(i, n) cin >> a[i];
	int m; cin >> m;
	FOR(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		e[u].push_back(v);
		re[v].push_back(u);
	}

	int types = scc();
	vector<map<ll,int> > vt(types);
	FOR(i, n) vt[cmp[i]][a[i]]++;

	ll a = 0;
	ll b = 1;
	for (auto i : vt) {
		a += i.begin()->first;
		b = b * i.begin()->second % MOD;
	}

	cout << a << " " << b << endl;

	return 0;
}