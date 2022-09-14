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
	// freopen("output.txt", "w", stdout);


	int n;
	cin >> n;
	set<int> tm;
	map<int, int> mp;

	vector<int> t(n);

	vector<int> ans(n + 1);

	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		tm.insert(t[i]);
		mp[t[i]] = i;

		ans[i + 1] = ans[i] + 20;

		int k;
		k = mp[*tm.lower_bound(t[i] - 89)];
		ans[i + 1] = min(ans[i + 1], ans[k] + 50);

		k = mp[*tm.lower_bound(t[i] - 1439)];
		ans[i + 1] = min(ans[i + 1], ans[k] + 120);
		cout << ans[i + 1] - ans[i] << endl;
	}
	return 0;
}