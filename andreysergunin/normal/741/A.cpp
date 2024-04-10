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
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> t(n), f(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		--t[i];
		f[t[i]] = 1;
	}

	for (int i = 0; i < n; ++i) {
		if (!f[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> used(n);

	vector<int> cycle;

	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		int cur = i;
		int d = 0;
		while (!used[cur]) {
			used[cur] = 1;
			cur = t[cur];
			++d;
		}
		if (cur != i) {
			cout << -1 << endl;
			return 0;
		}

		cycle.push_back(d);
	}

	sort(all(cycle));
	unique(all(cycle));
	int m = sz(cycle);

	ll g = 1;

	for (int i = 0; i < m; ++i) {
		g = g * ((ll)(cycle[i]) / __gcd(g, (ll)(cycle[i])));
	}

	if (g % 2 == 0)
		g /= 2;
	cout << g << endl;
}