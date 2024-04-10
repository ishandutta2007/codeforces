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

int main() {
	// freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);

	for (int i = 0; i < n; ++i)
		cin >> s[i];	

	int k;
	cin >> k;
	--k;
	string res = s[k];
	for (int i = 1; i < m; ++i) {
		cin >> k;
		--k;
		if (sz(s[k]) != sz(res)) {
			cout << "No" << endl;
			return 0; 
		}
		for (int j = 0; j < sz(res); ++j) {
			if (res[j] != s[k][j])
				res[j] = '?';
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (sz(res) != sz(s[i]))
			continue;

		bool f = true;
		for (int j = 0; j < sz(res); ++j) {
			if (res[j] != '?' && res[j] != s[i][j])
				f = false;
		}

		if (f)
			++cnt;
	}

	if (cnt == m) {
		cout << "Yes" << endl;
		cout << res << endl;
	}
	else 
		cout << "No" << endl;
}