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

const int MAXN = 100000;

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		a[i].first *= n;
		a[i].first += n - i;
		a[i].second *= n;
		a[i].second += a[i].first;
	}
	sort(all(a));

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int x = 0;
			if (a[i].second > a[j].first && a[j].second > a[i].second)
				x = max(x, 2);

			if (a[j].second < a[i].first && a[i].second < a[j].second)
				x = max(x, 2);

			if (a[i].second > a[j].first || a[i].first > a[j].second || a[i].second > a[j].second)
				x = max(x, 1);
			ans += x;
		}
	}
	cout << ans << endl;
}