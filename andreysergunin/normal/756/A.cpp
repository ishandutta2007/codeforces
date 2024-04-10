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
	vector<int> p(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	vector<int> used(n);
	int cycles = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;

		++cycles;
		int j = i;
		for (; !used[j]; j = p[j])
			used[j] = 1;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += b[i];
	sum %= 2;

	int ans = 0;
	if (!(sum & 1))
		ans = 1;

	if (cycles != 1)
		ans += cycles;

	cout << ans << endl;

	return 0;
}