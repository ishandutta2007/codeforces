#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 110;
int a[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, u, v;
		scanf("%d %d %d", &n, &u, &v);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		bool ok = true;

		for (int i = 0; i < n; i++) {
			if (a[i] != a[0]) {
				ok = false;
			}
		}

		if (ok) {
			printf("%d\n", min(u + v, 2 * v));
			continue;
		}

		ok = true;

		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) > 1) {
				ok = false;
				break;
			}
		}

		if (ok) {
			printf("%d\n", min(u, v));
		}
		else {
			printf("0\n");
		}
	}
}