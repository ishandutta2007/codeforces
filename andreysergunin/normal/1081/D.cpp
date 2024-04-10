#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 100100;

int p[MAXN], w[MAXN];
vector<int> arr[MAXN];
int good[MAXN];

struct Edge {
	int u, v, w;
};

bool operator<(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

int get(int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = get(p[v]);
}

void unite(int u, int v) {
	u = get(u); v = get(v);
	if (u != v) {
		p[u] = v;
		w[v] += w[u];
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");


   	int n, m, k;
   	cin >> n >> m >> k;

   	for (int i = 0; i < k; ++i) {
   		int g;
   		cin >> g;
   		--g;
   		good[g] = 1;
   	} 

   	for (int i = 0; i < n; ++i) {
   		p[i] = i;
   		w[i] = good[i];
   	}

   	vector<Edge> e(m);

   	for (int i = 0; i < m; ++i) {
   		cin >> e[i].u >> e[i].v >> e[i].w;
   		--e[i].u; --e[i].v;
   	}

   	sort(all(e));

   	for (int i = 0; i < m; ++i) {
   		unite(e[i].u, e[i].v);
   		if (w[get(e[i].u)] == k) {
   			for (int j = 0; j < k; ++j) {
   				cout << e[i].w << " ";
   			}
   			cout << endl;
   			return 0;
   		}
   	}

   	assert(false);



}