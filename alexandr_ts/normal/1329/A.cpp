#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
 
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

struct S {
	int l, i, p;
} a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a[i].l;	
		sum += a[i].l;
		a[i].i = i;
	}
	if (sum < n) {
		cout << -1;
		return;	
	}

	for (int i = 0; i < m; ++i) {
		a[i].p = i + 1;	
		if (a[i].p + a[i].l > n + 1) {
			cout << -1;
			return;	
		}
	}
	a[m - 1].p = 1 + n - a[m - 1].l;
	for (int i = m - 2; i >= 0; --i) {
		if (a[i].p + a[i].l >= a[i + 1].p) break;
		a[i].p = a[i + 1].p - a[i].l;	
	}
	for (int i = 0; i < m; ++i) {
		cout << a[i].p << " ";
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