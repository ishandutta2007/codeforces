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

ll b[N], a[N], x[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> b[i];
	x[0] = 0;
	a[0] = x[0] + b[0];
	for (int i = 1; i < n; ++i) {
		x[i] = max(x[i - 1], a[i - 1]);	
		a[i] = x[i] + b[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";	
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}