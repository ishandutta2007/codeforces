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

typedef long long ll;
mt19937 rr(random_device{}());

int main() {
	// freopen("input.txt", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<string> t(m);

	set<string> set_s;

	int d = 0;
	
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		set_s.insert(s[i]);
	}

	for (int i = 0; i < m; ++i) {
		cin >> t[i];
		if (set_s.count(t[i]))
			++d;
	}

	n -= d;
	m -= d;

	for (int i = 0; ; ++i) {
		if (i & 1) {
			if (d > 0) {
				--d;
			} else {
				if (m > 0) {
					--m;
				} else {
					cout << "YES" << endl;
					return 0;
				}
			}
		} else {
			if (d > 0) {
				--d;
			} else {
				if (n > 0) {
					--n;
				} else {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

		
	return 0;
}