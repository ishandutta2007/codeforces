/*input
11 3
-5 -4 -3 -2 -1 0 1 2 3 4 5
> 2
> -4
< 5

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

const int MAXN = 100001;

int n, q;
int tree[MAXN << 2], mapping[MAXN], A[MAXN];

#define ROOT1 (root << 1)
#define ROOT2 (root << 1 | 1)
#define MID ((lo + hi) >> 1)

void push(int root)
{
	if (tree[root] < 2) tree[ROOT1] = tree[ROOT2] = tree[root];
    else if (tree[root] == 2) tree[ROOT1] ^= 1, tree[ROOT2] ^= 1;
    tree[root] = 3;
}

void update(int root, int lo, int hi, int l, int r, int type)
{
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) {
		if (type < 2) tree[root] = type;
		else tree[root] ^= 1;
		return;
	}

	push(root);
	update(ROOT1, lo, MID, l, r, type);
	update(ROOT2, MID+1, hi, l, r, type);
}

void finish(int root, int lo, int hi)
{
	if (lo == hi) {
		mapping[lo] = tree[root];
		return;
	}
	push(root);
	finish(ROOT1, lo, MID);
	finish(ROOT2, MID+1, hi);
}

int get(int x)
{
	if (mapping[abs(x)] == 0) return -abs(x);
	else if (mapping[abs(x)] == 1) return abs(x);
	else if (mapping[abs(x)] == 2) return -x;
	return x;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	FOR(i, 0, n-1) cin >> A[i];
	fill_n(tree, MAXN << 2, 3);

	FOR(_, 0, q-1) {
		char ch; int x; cin >> ch >> x;
		if (ch == '<') {
			--x;
			if (x >= 0) {
				update(1, 0, MAXN-1, 0, x, 2);
				update(1, 0, MAXN-1, x+1, MAXN-1, 1);
			}
			else update(1, 0, MAXN-1, -x, MAXN-1, 1);
		} else {
			++x;
			if (x <= 0) {
				update(1, 0, MAXN-1, 0, -x, 2);
				update(1, 0, MAXN-1, -x+1, MAXN-1, 0);
			}
			else update(1, 0, MAXN-1, x, MAXN-1, 0);
		}
//		FOR(i, 0, n-1) cout << mapping[MAXN + A[i]] << ' '; cout << endl;
	}

//	cout << "S" << endl;

	finish(1, 0, MAXN-1);

	FOR(i, 0, n-1) cout << get(A[i]) << ' '; cout << endl;
	return 0;
}