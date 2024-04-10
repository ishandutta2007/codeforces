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
#include <iomanip>

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
int ps[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			v[i]--;
			ps[v[i]] = i;
		}

		int l = 0;
		int r = n - 1;

		bool ok = true;

		while (l != n) {
			int w = ps[l];

			for (int i = w; i <= r; i++) {
				if (v[i] - i != v[w] - w) {
					ok = false;
					break;
				}
			}

			if (ok) {
				l += r - w + 1;
				r = w - 1;
			}
			else {
				break;
			}
		}

		if (ok) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}