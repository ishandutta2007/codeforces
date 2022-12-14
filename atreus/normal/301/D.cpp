#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
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
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int n, a[maxn], per[maxn], ans[maxn], fen[maxn];
vector <int> v[maxn];
pair <pair <int, int>, int> p[maxn];

ll get (int x) {
	ll ret = 0;
	for ( ; x > 0; x -= x & -x) 
		ret += fen[x];
	return ret;
}

void upd (int x, int val) {
	for ( ; x <= n; x += x & -x) 
		fen[x] += val;
}

int main() {
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		per[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			int x = per[i], y = per[j];
			if (x < y)
				swap (x, y);
			v[x].PB (y);
			upd (y, 1);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> p[i].F.S >> p[i].F.F;
		p[i].S = i;
	}
	sort (p + 1, p + q + 1);
	int idx = n;
	for (int i = q; i >= 1; i--) {
		int l = p[i].F.S, r = p[i].F.F;
		while (idx > r) {
			for (auto w : v[idx])
				upd (w, -1);
			idx --;
		}
//		cout << idx << " -> " << get(r) << " " << get (l - 1) << endl;
		ans[p[i].S] = get (r) - get (l - 1);
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << " ";
	cout << endl;
}