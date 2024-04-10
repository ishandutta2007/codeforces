#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <cassert>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, q;
	cin >> n >> q; 

	vector<int> c(n + 1);
	vector<int> d(n + 1, -1);
	vector<int> u(q + 1), v(q + 1);

	int k = 0;

	int ans = 0;
	int s = 0;

	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			++c[x];

			u[s] = x;
			v[s] = i;
			++s;
		}

		if (t == 2) {
			int x;
			scanf("%d", &x);
			ans += c[x];
			c[x] = 0;
			d[x] = i;
		}

		if (t == 3) {
			int l;
			scanf("%d", &l);
			for (int j = k; j < l; ++j) {
				if (d[u[j]] < v[j]) {
					++ans;
					--c[u[j]];
				}
			}
			k = max(l, k);
		}
		printf("%d\n", s - ans);
	}

}