#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;

vector <int> v[maxn];

int seg[4 * maxn], a[maxn];

void change (int id, int L, int R, int l, int r) {
	if (L == l and R == r) {
		seg[id] ++;
		return;
	}
	int mid = (L + R) / 2;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r);
}

int get (int id, int L, int R, int idx) {
	if (L + 1 == R or seg[id] > 0)
		return seg[id];
	int mid = (L + R) / 2;
	if (mid > idx)
		return get (2 * id + 0, L, mid, idx);
	else
		return get (2 * id + 1, mid, R, idx);
}

int main () {
	ios_base::sync_with_stdio (false);
	int n, q;
	cin >> n >> q;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max (Max, a[i]);
	}
	if (Max == 0) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			cout << q << " ";
		}
		return 0;
	}
	if (Max != q) {
		bool found = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				found = 1;
				a[i] = q;
				break;
			}
		}
		if (!found)
			return cout << "NO" << endl, 0;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) {
			a[i] = a[i - 1];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] == 0) {
			a[i] = a[i + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		v[a[i]].PB (i);
	}
	for (int i = q; i >= 1; i--) {
		if (v[i].empty())
			continue;
		for (auto j : v[i]) {
			if (get (1, 1, n + 1, j) >= 1) {
				return cout << "NO" << endl, 0;
			}
		}
		for (int j = 1; j < v[i].size(); j++) {
			change (1, 1, n + 1, v[i][j - 1], v[i][j]);
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}