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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int sq = 750;

int n;

inline int block (int x) { return x / sq; }

ll lazy[sq], a[maxn];

unordered_map <ll, int> mp[sq];

int Max (int x) {
	for (int i = block (n - 1); i >= 0; i--) {
		if (mp[i].count (x - lazy[i])) {
			for (int j = min (n, (i + 1) * sq) - 1; j >= i * sq; j--) {
				if (a[j] == x - lazy[i]) {
					return j;
				}
			}
		}
	}
	return -2;
}

int Min (int x) {
	for (int i = 0; i <= block (n - 1); i++) {
		if (mp[i].count (x - lazy[i])) {
			for (int j = i * sq; j < n and j < (i + 1) * sq; j++) {
				if (a[j] == x - lazy[i]) {
					return j;
				}
			}
		}
	}
	return -1;
}

void change (int l, int r, int x) {
	for (int i = l; i <= r and block (i) == block (l); i++) {
		mp[block(i)][a[i]] --;
		if (mp[block(i)][a[i]] == 0)
			mp[block(i)].erase (a[i]);
		a[i] += x;
		mp[block(i)][a[i]] ++;
	}
	for (int i = block(l) + 1; i < block (r); i++)
		lazy[i] += x;

	if (block(r) != block(l)) {
		for (int i = r; block (i) == block (r); i--) {
			mp[block(i)][a[i]] --;
			if (mp[block(i)][a[i]] == 0)
				mp[block(i)].erase (a[i]);
			a[i] += x;
			mp[block(i)][a[i]] ++;
		}
	}
}

int main() {	
	ios_base::sync_with_stdio (false);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[block(i)][a[i]] ++;
	}

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l --, r --;
			change (l, r, x);
		}
		else {
			int y;
			cin >> y;
			cout << Max (y) - Min (y) << '\n';
		}
	}
}