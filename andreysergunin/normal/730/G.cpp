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

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	v.push_back({0, 1});

	for (int i = 0; i < n; ++i) {
		int s, d;
		cin >> s >> d;
		
		bool f = true;
		for (int j = 0; j < sz(v); ++j) {
			if (!(v[j].second <= s || s + d <= v[j].first))
				f = false;
		}

		int ans = INF;
		if (f) {
			ans = s;
		} else {
			for (int j = 0; j < sz(v); ++j) {
				int t = v[j].second;
				bool f = true;
				for (int k = 0; k < sz(v); ++k) {
					if (!(v[k].second <= t ||  t + d <= v[k].first))
						f = false;
				}
				if (f) 
					ans = min(ans, t);
			}
		}

		v.push_back({ans, ans + d});
		cout << ans << " " << ans + d - 1 << endl;
	}
}