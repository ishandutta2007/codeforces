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
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
bool used[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			used[i] = false;
		}

		bool ok = true;

		for (int i = 0; i < n; i++) {
			int x;

			scanf("%d", &x);

			x += i;
			x %= n;
			if (x < 0) {
				x += n;
			}

			if (used[x]) {
				ok = false;
			}

			used[x] = true;
		}

		if (ok) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}