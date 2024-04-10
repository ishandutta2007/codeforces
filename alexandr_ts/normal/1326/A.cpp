#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
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

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 5e17 + 10;
const int M = 1e6 + 10;
const int N = 2e6 + 10;

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "-1\n";
		return;	
	}
	cout << 2;
	for (int i = 1; i < n; ++i) {
		cout << 3;	
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
	cin >> t;
    while (t--) {
        solve();
    }
}