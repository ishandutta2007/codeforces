#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1000 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int par[maxn], c[maxn];

int getpar (int x) {
	if (par[x] < 0)
		return x;
	return par[x] = getpar (par[x]);
}

void merge (int u, int w) {
	if (par[u] > par[w])
		swap (u, w);
	par[u] += par[w];
	par[w] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i ++)
		cin >> c[i];
	memset (par, -1, sizeof par);
	for (int i = 1; i <= m; i ++) {
		int u, w;
		cin >> u >> w;
		u = getpar(u);
		w = getpar(w);
		if (u != w)
			merge (u, w);
	}
	int mxx = 0, sum = 0;
	ll tot = 0;
	for (int i = 1; i <= k; i ++) {
		int x = -par[getpar (c[i])];
		sum += x;
		mxx = max (mxx, x);
		tot += x * (x - 1) / 2;
	}
	sum = n - sum;
	tot -= mxx * (mxx - 1) / 2;
	mxx += sum;
	tot += mxx * (mxx - 1) / 2;
	cout << tot - m << endl;
	
}