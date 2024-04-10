/*input
3
6
1 5 4 3 2 6
5 3 1 4 6 2
6
3 5 4 6 2 1
3 6 4 5 2 1
1
1
1

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
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code
const int MAXN = 100007;
int a[MAXN], b[MAXN], c[MAXN];
bool vis[MAXN];

void solve() {
	int n; cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n) c[a[i]] = b[i];

	int nodd = 0;
	FOR(i, 1, n) vis[i] = 0;
	FOR(i, 1, n) if (!vis[i]) {
		int x = 0;
		for (int j = i; !vis[j]; ++x) vis[j] = 1, j = c[j];
		nodd += (x & 1);
	}
	assert(n % 2 == nodd % 2);

	ll ans = 0;
	while (n > nodd) {
		ans += n - 1;
		n -= 2;
	}
	cout << ans * 2 << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}