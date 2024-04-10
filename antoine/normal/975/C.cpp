#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;

int n, q;
ll a[200000];
ll cs[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cs[i] = a[i] + (i ? cs[i - 1] : 0);
	}

	int curr = 0, hp = a[0];
	while (q--) {
		ll k;
		cin >> k;
		int next = upper_bound(cs + curr, cs + n, k + cs[curr] - hp) - cs;
		if (next == n) {
			curr = 0;
			hp = a[0];
		} else {
			hp = hp + cs[next] - cs[curr] - k;
			curr = next;
		}
		cout << n - curr << '\n';
	}
	return 0;
}