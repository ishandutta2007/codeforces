#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bal = 0;
	for (char c : s) {
		if (c == 'x') {
			bal++;
		}
		else {
			bal--;
		}
	}
	cout << abs(bal) / 2 << '\n';
	if (bal > 0) {
		for (char& c : s) {
			if (bal == 0) break;
			if (c == 'x') {
				c = 'X';
				bal -= 2;
			}
		}
	}
	else {
		for (char& c : s) {
			if (bal == 0) break;
			if (c == 'X') {
				c = 'x';
				bal += 2;
			}
		}
	}
	cout << s;
}