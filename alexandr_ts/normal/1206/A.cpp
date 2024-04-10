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
const int N = 1e6 + 10;

int a[N];
int b[N];

void solve() {
	int n;
	cin >> n;
	set<int> sa, sb;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sa.insert(a[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		sb.insert(b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!sa.count(a[i] + b[j]) && !sb.count(a[i] + b[j])) {
				cout << a[i] << " " << b[j];
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);
	cin.tie();
	solve();
}