/*input
8 1
5 1 8 3 6 4 7 2 
1 8

10 10
6 1 3 2 5 8 4 10 7 9
1 8
1 10
1 2
1 4
2 4
5 8
4 10
4 7
8 10
5 9

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

const int MAXN = 1000007;

ll A[MAXN << 2], B[MAXN << 2], LA[MAXN << 2], LB[MAXN << 2];
void push(int rt, int lo, int hi) {
	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;

	A[lc] += LA[rt] * (md - lo + 1);
	B[lc] += LB[rt] * (md - lo + 1);
	LA[lc] += LA[rt], LB[lc] += LB[rt];

	A[rc] += LA[rt] * (hi - md);
	B[rc] += LB[rt] * (hi - md);
	LA[rc] += LA[rt], LB[rc] += LB[rt];

	LA[rt] = 0, LB[rt] = 0;
}
void pull(int rt, int lo, int hi) {
	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;
	A[rt] = A[lc] + A[rc], B[rt] = B[lc] + B[rc];
}
void modify(int rt, int lo, int hi, int l, int r, ll a, ll b) {
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) {
		A[rt] += a * (hi - lo + 1);
		B[rt] += b * (hi - lo + 1);
		LA[rt] += a;
		LB[rt] += b;
		return;
	}
	// cout << rt << ' ' << lo << ' ' << hi << ' ' << l << ' ' << r << endl;

	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;
	push(rt, lo, hi);
	modify(lc, lo, md, l, r, a, b);
	modify(rc, md + 1, hi, l, r, a, b);
	pull(rt, lo, hi);
}

ll get(int rt, int lo, int hi, int l, int r, int x) {
	if (hi < l || r < lo) return 0;
	if (l <= lo && hi <= r) return A[rt] * x + B[rt];

	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;
	push(rt, lo, hi);
	return get(lc, lo, md, l, r, x) + get(rc, md + 1, hi, l, r, x);
}

int N, Q, P[MAXN], IP[MAXN];
ll ans[MAXN];
vector<int> divList[MAXN];
vector<tuple<int, int, int, int>> updates[MAXN];
vector<tuple<int, int, int, int>> queries[MAXN];
set<int> used;

void add_rect(int lx, int rx, int ly, int ry) {
	// cout << "add " << lx << ' ' << rx << ' ' << ly << ' ' << ry << endl;
	updates[lx].emplace_back(ly, ry, 1, -(lx - 1));
	updates[rx].emplace_back(ly, ry, -1, rx);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i * i <= N; ++i) {
		for (int j = i * i; j <= N; j += i) divList[j].push_back(i);
	}
	used.insert(0), used.insert(N + 1);

	FOR(i, 1, N) cin >> P[i], IP[P[i]] = i;
	FORB(x, N, 1) {

		// cout << x << ":" << endl;;
		int mid = IP[x];
		
		used.insert(mid);
		auto it = used.find(mid);
		int lef = (*prev(it)) + 1, rig = (*next(it)) - 1;

		vector<int> vec = {mid};
		for (int y : divList[x]) {
			if (y == x / y) continue;
			if (IP[y] < lef || IP[y] > rig) continue;
			if (IP[x / y] < lef || IP[x / y] > rig) continue;
			// cout << y << ' ' << x / y << endl;
			vec.push_back(IP[y]), vec.push_back(IP[x / y]);
		}
		sort(ALL(vec)), vec.erase(unique(ALL(vec)), vec.end());

		int last = rig + 1;
		for (int l = SZ(vec) - 1; l >= 0; --l) {
			int a = P[vec[l]], b = x / a;
			if (a == b) continue;
			if (IP[b] < vec[l]) continue;
			// cout << a << ' ' << b << endl;
			int r = max(IP[b], mid);
			if (r >= last) continue;
			add_rect(lef, min(vec[l], mid), r, last - 1);
			last = r;
		}
	}

	FOR(q, 1, Q) {
		int l, r; cin >> l >> r;
		queries[l - 1].emplace_back(l, r, q, -1);
		queries[r    ].emplace_back(l, r, q, +1);
	}

	FOR(x, 0, N) {
		for (auto [l, r, a, b] : updates[x]) modify(1, 1, N, l, r, a, b);
		// cout << "X = " << x << endl;
		for (auto [l, r, i, s] : queries[x]) ans[i] += get(1, 1, N, l, r, x) * s;
	}
	FOR(q, 1, Q) cout << ans[q] << '\n';

	return 0;
}