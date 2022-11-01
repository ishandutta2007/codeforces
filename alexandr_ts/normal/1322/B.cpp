#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <sstream>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int M = 24;
const int N = 1e6 + 10;

int a[N];
int bits[N];
vector<int> b[M + 1];

int solveTL(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans ^= (a[i] + a[j]);
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;

	for (int j = 0; j <= M; ++j) {
		b[j].resize((1 << j), 0);
	}

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j <= M; ++j) {
			if (a[i] & (1 << j)) {
				bits[j]++;
			}
			++b[j][a[i] & ((1 << j) - 1)];
		}
	}

	//cout << solveTL(n) << endl;

	for (int j = 0; j <= M; ++j) {
		b[j].push_back(0);
		for (int i = (int)b[j].size() - 2; i >= 0; i--) {
			b[j][i] += b[j][i + 1];
		}
	}

	int ans = 0;
	for (int j = 0; j <= M; ++j) {
		int cur = (bits[j] % 2 * (n - bits[j])) % 2;
		
		ll add = 0;
		
		for (int i = 0; i < (1 << j); ++i) {
			int pos = (1 << j) - i;
			ll val = (ll)b[j][i] - b[j][i + 1];
			if (pos <= i) {
				pos = i + 1;
				add += val * (val - 1) / 2 % 2;
			}
			add += val * b[j][pos] % 2;
		}

		cur = (cur + add % 2) % 2;
		ans += cur * (1 << j);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("a.in", "r", stdin);

	int t = 1;
	while (t--) {
		solve();
	}

}