/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define uint unsigned int

using namespace std;

const int maxn = 110;
int v[maxn][maxn];
int h[maxn];

int n, m;

int go(int cnt) {
	int ans = cnt;
	for (int j = 0; j < m; j++) {
		if (v[0][j] < cnt) {
			return (int)1e9;
		}

		h[j] = v[0][j] - cnt;
		ans += h[j];
	}

	for (int i = 1; i < n; i++) {
		int now = v[i][0] - h[0];

		if (now < 0) {
			return (int)1e9;
		}

		for (int j = 1; j < m; j++) {
			if (v[i][j] - h[j] != now) {
				return (int)1e9;
			}
		}

		ans += now;
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	int best = (int)1e9;
	int f = -1;

	for (int cnt = 0; cnt <= 500; cnt++) {
		int ans = go(cnt);

		if (ans < best) {
			best = ans;
			f = cnt;
		}
	}

	if (best == (int)1e9) {
		cout << -1 << endl;
		return 0;
	}

	cout << best << endl;

	go(f);

	for (int j = 0; j < m; j++) {
		for (int cnt = 0; cnt < h[j]; cnt++) {
			printf("col %d\n", j + 1);
		}
	}

	for (int cnt = 0; cnt < f; cnt++) {
		printf("row 1\n");
	}

	for (int i = 1; i < n; i++) {
		for (int cnt = 0; cnt < v[i][0] - h[0]; cnt++) {
			printf("row %d\n", i + 1);
		}
	}

	return 0;
}