/*input
5
1 2 3 4 6

6 4 3 2 1
4 6 1 3 2
2 3 1 6 4

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
int pf[MAXN], nxt[MAXN], lastApp[MAXN], N, A[MAXN];
int suffixF[MAXN], prefixCnt[MAXN];

// Segment Tree supports: update maximum of interval, get sum of interval
ll cur_sum[MAXN << 2], cur_min[MAXN << 2], cur_max[MAXN << 2], lazy[MAXN << 2];

void asgn(long long x, int root, int lo, int hi)
{
	cur_min[root] = cur_max[root] = lazy[root] = x;
	cur_sum[root] = (hi - lo + 1) * x;
}

void push(int root, int lo, int hi)
{
	if (lo < hi && lazy[root] >= 0) {
		int mid = (lo + hi) >> 1;
		asgn(lazy[root], root << 1, lo, mid);
		asgn(lazy[root], root << 1 | 1, mid + 1, hi);
	}
	lazy[root] = -1;
}

void pull(int root, int lo, int hi)
{
	if (lo < hi) {
		cur_sum[root] = cur_sum[root << 1] + cur_sum[root << 1 | 1];
		cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
		cur_max[root] = max(cur_max[root << 1], cur_max[root << 1 | 1]);
	}
	lazy[root] = -1;
}

void build(int root = 1, int lo = 1, int hi = N)
{
	if (lo == hi) {
		cur_sum[root] = cur_min[root] = cur_max[root] = suffixF[lo];
		return;
	} else {
		int mid = (lo + hi) >> 1;
		build(root << 1, lo, mid);
		build(root << 1 | 1, mid + 1, hi);
	}
	
	pull(root, lo, hi);
}

void upd(int r, long long x, int root = 1, int lo = 1, int hi = N)
{
	// if (root == 1) cout << "upd " << r << ' ' << x << endl;
	if (r < lo || cur_min[root] >= x) return;
	if (hi <= r && cur_max[root] <= x) {
		asgn(x, root, lo, hi);
		return;
	}

	int mid = (lo + hi) >> 1;
	push(root, lo, hi);
	upd(r, x, root << 1, lo, mid);
	upd(r, x, root << 1 | 1, mid + 1, hi);
	pull(root, lo, hi);
}

long long get(int l, int r, int root = 1, int lo = 1, int hi = N)
{
	if (r < lo || hi < l) return 0;
	if (l <= lo && hi <= r) return cur_sum[root];
	
	push(root, lo, hi);
	int mid = (lo + hi) >> 1;
	
	long long ans = 0;
	ans += get(l, r, root << 1, lo, mid);
	ans += get(l, r, root << 1 | 1, mid + 1, hi);
	return ans;
}

void get_factors(int x, vector<int> &vec)
{
	if (x == 1) {
		vec.push_back(x);
		return;
	}

	int cnt = 0, pr = pf[x];
	for (; pf[x] == pr; ++cnt, x = nxt[x]);
	get_factors(x, vec);
	
	int sz = SZ(vec);
	FOR(i, 0, sz - 1) {
		for (int j = 1, pw = pr; j <= cnt; ++j, pw *= pr) {
			vec.push_back(vec[i] * pw);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// prep
	FOR(i, 2, MAXN - 1) {
		if (!pf[i]) {
			for (int j = i, k = 1; j < MAXN; j += i, ++k) {
				pf[j] = i;
				nxt[j] = k;
			}
		}
	}

	cin >> N;
	FOR(i, 1, N) cin >> A[i];

	vector<int> factors;
	FOR(i, 1, N) {
		factors.clear();
		get_factors(A[i], factors);
		FORA(j, factors) lastApp[j] = i;
	}

	FORB(i, N, 1) {
		suffixF[i] = suffixF[i + 1];

		factors.clear();
		get_factors(A[i], factors);
		FORA(j, factors) {
			if (lastApp[j] > i && suffixF[i] < j) {
				suffixF[i] = j;
			} 
		}

		// cout << "suffixF " << i << ": " << suffixF[i] << endl;
	}

	long long ans = 0;

	// has prefix + has suffix + has both

	ans += accumulate(suffixF + 2, suffixF + 1 + N, 0ll); // has suffix

	build();

	int curF = 0;
	FOR(lef, 1, N) {
		factors.clear();
		get_factors(A[lef], factors);
		FORA(j, factors) {
			++prefixCnt[j];
			if (prefixCnt[j] == 1) {
				upd(lastApp[j], j);
			} else if (prefixCnt[j] == 2) {
				if (curF < j) {
					curF = j;
					upd(N, j);
				}
			}
		}

		if (lef < N) ans += curF; // has prefix
		// cout << "prefixF " << lef << ": " << curF << endl;
		// cout << "get " << lef << ": " << get(lef + 2, N) << endl;
		ans += get(lef + 2, N); // has both
	}

	cout << ans << endl;

	return 0;
}