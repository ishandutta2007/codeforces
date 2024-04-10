#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <ctime>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const ll INF = 5e17 + 10;
const int M = 1e6 + 10;
const int N = 3e5 + 10;

int p[N], q[N];
int p1[N];

int t[4 * N], ad[4 * N];

void push(int v, int tl, int tr) {
	if (!ad[v]) return;
	if (tl != tr) {
		ad[2 * v] += ad[v];
		ad[2 * v + 1] += ad[v];	
	}
	t[v] += ad[v];
	ad[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (tl > r || l > tr) return;
	if (l <= tl && tr <= r) {
		ad[v] += x;
		push(v, tl, tr);
		return;	
	}
	int tm = (tl + tr) / 2;
	add(2 * v, tl, tm, l, r, x);
	add(2 * v + 1, tm + 1, tr, l, r, x);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int getmax(int v, int tl, int tr) {
	push(v, tl, tr);
	return t[v];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];	
		p[i]--;
		p1[p[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> q[i];	
		q[i]--;
	}
	vector<int> ans;
	int ptr = 0;
	for (int x = n - 1; x >= 0; --x) {
		add(1, 0, n - 1, 0, p1[x], 1);
		while (ptr < n && getmax(1, 0, n - 1) > 0) {
			ans.push_back(x);	
			add(1, 0, n - 1, 0, q[ptr], -1);
			ptr++;
		}
	}
	for (auto x: ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}