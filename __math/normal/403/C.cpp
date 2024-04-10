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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


const int MAX_V = 2000;
int n;
int a[2000][2000];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void dfs(int v) {
	used[v] = true;
	FOR(i, n) if(!used[i] && a[v][i]) {
		dfs(i);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	FOR(i, n) if (!used[i] && a[i][v]) {
		rdfs(i,k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	FOR(v, n) if (!used[v]) dfs(v);
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
		if (k > 1) return k;
	}
	return k;
}

int main() {
	scanf("%d",&n);
	FOR(i, n) FOR(j, n) scanf("%d", a[i] + j);

	int K = scc();

	puts(K == 1 ? "YES" : "NO");

	return 0;
}