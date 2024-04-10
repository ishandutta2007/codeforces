#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

ll v[maxn];
int f[maxn];

int main() {
	int n, m, l;

	cin >> n >> m >> l;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);

		if (v[i] > l) {
			f[i] = 1;

			if (i == 0 || f[i - 1] == 0) {
				ans++;
			}
		}
	}

	while (m--) {
		int tp;

		scanf("%d", &tp);

		if (tp == 0) {
			printf("%d\n", ans);
		}
		else {
			int p, d;

			scanf("%d %d", &p, &d);

			p--;

			if (v[p] <= l) {
				v[p] += d;

				if (v[p] > l) {
					f[p] = 1;
					if (p == 0 || f[p - 1] == 0) {
						ans++;
					}

					if (p != n - 1 && f[p + 1] == 1) {
						ans--;
					}
				}
			}
		}
	}

	//system("pause");
}