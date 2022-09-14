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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int v[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		int m = -(int)1e9;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			m = max(m, v[i]);

			int y = m - v[i];

			int cur = 0;

			while (y) {
				cur++;
				y >>= 1;
			}

			ans = max(ans, cur);
		}

		printf("%d\n", ans);
	}
}