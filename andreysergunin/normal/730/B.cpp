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
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int INF = 2e9;

const int MAXN = 11000;

bool query(int x, int y) {
	cout << "? " << x + 1 << ' ' << y + 1 << endl;
	char c;
	cin >> c;
	return (c == '<');
}

int main() {
	// freopen("input.txt", "r", stdin);

	int tests;
	cin >> tests;
	for (int t = 0; t < tests; ++t) {
		int n;
		cin >> n;

		if (n == 1) {
			cout << "! 1 1" << endl; 
			continue;
		}

		vector<int> a, b;
		for (int i = 0; i < n / 2; ++i) {
			if (query(2 * i, 2 * i + 1)) {
				a.push_back(2 * i);
				b.push_back(2 * i + 1);	
			}
			else {
				a.push_back(2 * i + 1);
				b.push_back(2 * i);	
			}
		}

		if (n & 1) {
			if (query(a[0], n - 1))
				b.push_back(n - 1);
			else 
				a.push_back(n - 1);
		}

		int mn = a[0], mx = b[0];
		for (int i = 1; i < sz(a); ++i) {
			if (!query(mn, a[i]))
				mn = a[i];
		}

		for (int i = 1; i < sz(b); ++i) {
			if (query(mx, b[i]))
				mx = b[i];
		}

		cout << "! " << mn + 1 << " " << mx + 1 << endl;
	}
}