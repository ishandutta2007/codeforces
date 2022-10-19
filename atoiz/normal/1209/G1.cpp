/*input
5 0
3 7 3 7 3


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

const int MAXN = 200007;
int N, A[MAXN], cnt[MAXN], Q;
#define ends ends_
pii ends[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	vi vals;
	FOR(i, 0, N - 1) {
		cin >> A[i];
		if (!cnt[A[i]]) {
			vals.push_back(A[i]);
			ends[A[i]] = pii(i, i);
		}
		++cnt[A[i]];
		ends[A[i]].fi = min(ends[A[i]].fi, i);
		ends[A[i]].se = max(ends[A[i]].se, i);
	}

	sort(ALL(vals), [&](int i, int j) { return ends[i].fi < ends[j].fi; });

	vector<pii> vec;
	FORA(id, vals) {
		if (vec.empty() || ends[id].fi > vec.back().fi) {
			vec.emplace_back(ends[id].se, cnt[id]);
		} else {
			vec.back().fi = max(vec.back().fi, ends[id].se);
			vec.back().se = max(vec.back().se, cnt[id]);
		}
	}

	int ans = N;
	FORA(i, vec) ans -= i.se;
	cout << ans << endl;

	return 0;
}