#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int l[maxn];
int ans[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	ll s = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d", &l[i]);
		s += l[i];
	}

	if (s < n) {
		cout << -1 << '\n';
		return 0;
	}

	int pos = n - 1;

	for (int i = m - 1; i >= 0; i--) {
		if (pos < 0) {
			cout << -1 << '\n';
			return 0;
		}
		int cur = min(pos, n - l[i]);
		ans[i] = cur;
		pos = cur - 1;
	}

	if (pos != -1) {
		ans[0] = 0;

		for (int i = 1; i < m; i++) {
			if (ans[i] > ans[i - 1] + l[i - 1]) {
				ans[i] = ans[i - 1] + l[i - 1];
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%d ", ans[i] + 1);
	}
}