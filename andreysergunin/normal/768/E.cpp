#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());


map< pair<int, vector<bool>>, int > mp;

int solve(int n, vector<bool> &a) {
	if (mp.count({n, a}))
		return mp[{n, a}];

	vector<int> arr;
	for (int i = 1; i <= n; ++i) {
		if (!a[i]) {
			a[i] = 1;
			arr.push_back(solve(n - i, a));
			a[i] = 0;
		}
	}
	sort(all(arr));
	int m = unique(all(arr)) - arr.begin();
	for (int i = 0; i < m; ++i) {
		if (arr[i] != i) {
			mp[{n, a}] = i;
			return i;
		}
	}
	mp[{n, a}] = m;
	return m;
}

vector<int> f = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};


int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// vector<int> dp(61);

	// for (int i = 1; i <= 60; ++i) {
	// 	vector<bool> a(61);
	// 	dp[i] = solve(i, a);
	// 	cout << i << " " << dp[i] << endl;
	// }


	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		x ^= f[s];
	}

	cout << (x == 0 ? "YES" : "NO") << endl;
}