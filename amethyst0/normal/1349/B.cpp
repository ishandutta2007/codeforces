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

const int maxn = (int)1e5 + 10;
int v[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, k;

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		bool ok = false;

		for (int i = 0; i < n; i++) {
			if (v[i] == k) {
				ok = true;
				break;
			}
		}

		if (!ok) {
			printf("no\n");
			continue;
		}

		ok = false;

		for (int i = 0; i < n - 1; i++) {
			if (v[i] >= k && v[i + 1] >= k) {
				ok = true;
			}
		}

		for (int i = 0; i < n - 2; i++) {
			if (v[i] >= k && v[i + 2] >= k) {
				ok = true;
			}
		}

		if (n == 1 && v[0] == k) {
			printf("yes\n");
			continue;
		}

		if (ok) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}