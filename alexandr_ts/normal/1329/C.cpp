#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <cstring>
#include <array>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

const int N = (1 << 20);
int a[N + 10];
bool used[N + 10];

void solve() {
	int n, g;
	cin >> n >> g;
	fill(used, used + (1 << n) + 1, true);
	fill(used, used + (1 << g) - 1, false);
	map<int, int> poses;
	for (int i = 0; i < (1 << n) - 1; ++i) {
		cin >> a[i];	
		poses[a[i]] = i;
	}

	long long ans = 0;
	vector<int> taken(1 << n, 0);
	for (auto [x, pos]: poses) {
		int cur = pos;
		while (true) {
			if (!used[cur] && used[cur * 2 + 1] && used[cur * 2 + 2]) {
				ans += x;
				taken[pos] = true;
				used[cur] = true;
				break;
			}
			if (!cur) break;
			cur = (cur - 1) / 2;
		}
	}
	cout << ans << "\n";
	for (int i = (1 << n) - 2; i >= 0; --i) {
		if (!taken[i]) {
			cout << i + 1 << " ";
		}	
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();	
	}
}