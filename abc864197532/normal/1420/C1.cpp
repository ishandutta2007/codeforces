#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <string>
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector <int> a(n);
	long long cur1 = 0, cur2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		long long tmp1 = cur2 + a[i], tmp2 = cur1 - a[i];
		cur1 = max(cur1, tmp1);
		cur2 = max(cur2, tmp2);
	}
	cout << max(cur1, cur2) << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}