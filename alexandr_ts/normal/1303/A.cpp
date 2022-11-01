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
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt = count(s.begin(), s.end(), '0');
		while (!s.empty() && s.back() == '0') {
			cnt--;
			s.pop_back();
		}
		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() == '0') {
			cnt--;
			s.pop_back();
		}
		cout << cnt << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);
	cin.tie();
	solve();
}