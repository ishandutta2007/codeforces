#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long

const int maxn = (int)2e5 + 10;
int v[maxn];
int g[maxn];

int ans[maxn];

void solve(int l, int r, int s, int d) {
	s += d;
	vector <pii> res;
	vector <int> maxs;

	for (int i = r; i >= l; i--) {
		int x = v[i];

		int cur = 0;

		while (!res.empty() && res.back().first >= x) {
			cur = max(cur, res.back().second);
			cur++;
			res.pop_back();
		}

		res.push_back(mp(x, cur));
		int best = 0;
		if (!maxs.empty()) {
			best = maxs.back();
		}

		best = max(best, cur + (int)res.size());
		maxs.push_back(best);
		ans[s] = max(ans[s], best);
		//if (s == 2) {
			//cout << "!" << x << ' ' << best << endl;
		//}
		s += d;
	}

	int cur = 0;

	s = 0;

	while (!res.empty()) {
		cur = max(cur, res.back().second);
		cur++;
		res.pop_back();
	}

	ans[s] = max(ans[s], cur);
}

int stup(int l, int r) {
	if (l > r) {
		return 0;
	}

	int x = l;

	for (int i = l + 1; i <= r; i++) {
		if (v[i] < v[x]) {
			x = i;
		}
	}

	return max(stup(l, x - 1), stup(x + 1, r)) + 1;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		//v[i] = i + 1;
		v[i]--;
	}

	//random_shuffle(v, v + n);

	//for (int i = n; i < 2 * n; i++) {
	//	v[i] = v[i - n];
	//}

	//pii st = mp(n + 1, -1);

	//for (int j = 0; j < n; j++) {
	//	st = min(st, mp(stup(j, j + n - 1), j));
	//}

	//cout << "!" << st.first << ' ' << st.second << endl;

	int pos = 0;

	for (int i = 1; i < n; i++) {
		if (v[i] == 0) {
			pos = i;
		}
	}

	int ps = 0;

	for (int i = pos; i < n; i++) {
		g[ps++] = v[i];
	}

	for (int i = 0; i < pos; i++) {
		g[ps++] = v[i];
	}

	for (int i = 0; i < n; i++) {
		v[i] = g[i];
	}

	solve(1, n - 1, n, -1);
	reverse(v + 1, v + n);
	solve(1, n - 1, 1, 1);

	pii res = mp(n + 1, 0);

	for (int i = 0; i < n; i++) {
		res = min(res, mp(ans[i], (pos + i) % n));
	}

	cout << res.first + 1 << ' ' << res.second << endl;

	//system("pause");

	return 0;
}