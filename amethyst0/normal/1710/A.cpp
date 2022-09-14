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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		ll a = 0;
		ll b = 0;
		bool is_all_2_a = true;
		bool is_all_2_b = true;
		for (int i = 0; i < k; i++) {
			int x;
			scanf("%d", &x);
			if (x / n >= 2) {
				a += x / n;
			}
			if (x / m >= 2) {
				b += x / m;
			}
			if (x / n >= 3) {
				is_all_2_a = false;
			}
			if (x / m >= 3) {
				is_all_2_b = false;
			}
		}

		if (a >= m && (m % 2 == 0 || !is_all_2_a)) {
			printf("Yes\n");
			continue;
		}

		if (b >= n && (n % 2 == 0 || !is_all_2_b)) {
			printf("Yes\n");
			continue;
		}

		printf("No\n");
	}
}