#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int sq = 400;

int seg[4 * maxn];

int get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1, ret = 0;
	if (mid > l)
		ret ^= get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret ^= get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void change (int id, int L, int R, int idx, int x) {
	seg[id] ^= x;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, x);
	else
		change (2 * id + 1, mid, R, idx, x);
}

class query {
	public:
		int left;
		int right;
		int idx;
};		

bool compare (query fi, query se) {
	return fi.right < se.right;
}

query q[maxn];

int par[maxn], a[maxn], ans[maxn];

unordered_map <int, int> last;

int main () {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = par[i - 1] ^ a[i];
	}

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].left >> q[i].right;
		q[i].idx = i;
	}
	sort (q + 1, q + m + 1, compare);
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		if (!last.count (a[i])) {
			change (1, 1, n + 1, i, a[i]);
		}
		else {
			change (1, 1, n + 1, last[a[i]], a[i]);
			change (1, 1, n + 1, i, a[i]);
		}
		last[a[i]] = i;
		while (idx <= m and q[idx].right == i) {
			int l = q[idx].left, r = q[idx].right;
			int x = get (1, 1, n + 1, l, r + 1);
			ans[q[idx].idx] = ((x ^ par[r]) ^ par[l - 1]);
			idx ++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}