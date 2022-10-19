/*input
3
5
2 1 1 2 2
6
1 2 1 1 3 2
9
3 1 2 2 1 6 6 3 3

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

const int MAXN = 3e5 + 7;
int a[MAXN], n, comp[MAXN], sz[MAXN];
unordered_map<int, int> mp[MAXN];

ll solve()
{
	cin >> n;
	FOR(i, 0, n) mp[i].clear();
	FOR(i, 0, n) sz[i] = 0;

	sz[comp[0] = 0] = 1;
	FOR(i, 1, n) {
		cin >> a[i];
		unordered_map<int, int>::iterator it;
		if ((it = mp[comp[i - 1]].find(a[i])) == mp[comp[i - 1]].end()) {
			mp[comp[i] = i][a[i]] = i - 1;
		} else {
			mp[comp[i] = comp[it->second]][a[i]] = i - 1;
		}
		// cout << i << ' ' << comp[i] << endl;
		++sz[comp[i]];
		// cout << j << ' ';
	}
	// cout << endl;

	ll ans = 0;
	FOR(i, 0, n) ans += 1ll * sz[i] * (sz[i] - 1) / 2;
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q; cin >> q;
	while (q--) cout << solve() << '\n';

	return 0;
}