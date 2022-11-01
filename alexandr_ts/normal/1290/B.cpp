#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <tuple>
#include <sstream>
#include <numeric>
#include <chrono>
#include <utility>
#include <functional>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;

const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1e3 + 10;
const int N = 2e5 + 10;
const int A = 26;

int a[N];
int sum[N][A + 1];

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	fill(sum[0], sum[0] + A, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < A; ++j) {
			sum[i + 1][j] = sum[i][j];
		}
		sum[i + 1][s[i] - 'a']++;
	}


	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == r) {
			cout << "Yes\n";
			continue;
		}

		if (s[l] != s[r]) {
			cout << "Yes\n";
			continue;
		}

		int cnt = 0;
		for (int i = 0; i < A; ++i) {
			cnt += !!(sum[r + 1][i] - sum[l][i]);
		}
		if (cnt > 2) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);

	int t = 1;
	while (t--) {
		solve();
	}
}