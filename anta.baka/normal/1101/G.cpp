#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int y = 0;
	vi basis(30);
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		y ^= x;
		x = y;
		for (int b = 0; b < 30; b++) {
			if (!(x >> b & 1)) continue;
			if (!basis[b]) {
				ans++;
				basis[b] = x;
				break;
			}
			x ^= basis[b];
		}
	}
	cout << (y ? ans : -1);
}