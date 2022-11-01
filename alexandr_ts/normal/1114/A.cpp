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
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	int t;
	t = min(x, a);
	x -= t, a -= t;

	t = min(y, a);
	y -= t, a -= t;

	t = min(y, b);
	y -= t, b -= t;

	t = min(z, a + b + c);
	z -= t;

	if (x == 0 && y == 0 && z == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);
	cin.tie();
	solve();
}