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

vector<int> e[3 * ten(4) + 1];
int to[3 * ten(4) + 1];
bool used[3 * ten(4) + 1];
int n, m;

void visit(int v) {
	int cur_idx = 0;
	used[v] = true;
	FOR(i, n){
		if (cur_idx < sz(e[v]) && i == e[v][cur_idx]) {
			cur_idx++;
			continue;
		}
		if (to[i] != -1) continue;
		to[v] = i;
		visit(i);
		return;
	}
}

bool vaild(int from, int to) {
	auto it = lower_bound(e[from].begin(), e[from].end(),to);
	if (it == e[from].end()) return true;
	else return *it != to;
}

void insert(int v) {
	used[v] = true;
	int start = n;
	while (start != -1) {
		if (vaild(start, v) && vaild(v, to[start])) {
			 to[v] = to[start];
			 to[start] = v;
			 return;
		}
		start = to[start];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, m) {
		int p, q;
		scanf("%d%d", &p, &q);
		p--, q--;
		e[p].push_back(q);
	}
	FOR(i, n) e[i].push_back(i);
	FOR(i, n) sort(e[i].begin(), e[i].end());

	memset(to, -1, sizeof(to));
	visit(n);
	FOR(i, n) if (!used[i]) {
		insert(i);
	}
	vector<int> order;
	int start = n;
	while (start != -1) {
		start = to[start];
		order.push_back(start);
	}

	FOR(i, n) printf("%d%c", order[i] + 1, i == n - 1 ? '\n' : ' ');

	return 0;
}