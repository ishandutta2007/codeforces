/*input
5 4
1 2
4 3
1 4
3 4

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 100060;
int dsu[MAXN], sz[MAXN];
void init(int x) { FOR(i, 1, x) dsu[i] = i, sz[i] = 1; }
int root(int x) { return (x == dsu[x] ? x : dsu[x] = root(dsu[x])); }
void join(int x, int y) {
	x = root(x), y = root(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	dsu[y] = x;
	sz[x] += sz[y];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	init(N);
	FOR(i, 0, M - 1) {
		int x, y; cin >> x >> y;
		join(x, y);
	}
	int ans = 0;
	FOR(i, 1, N) if (i == root(i)) ans += sz[i] - 1;
	cout << M - ans << endl;
	return 0;
}