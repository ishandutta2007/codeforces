#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
pii v[maxn];
pii buf[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i].first);
			v[i].second = 1;
		}

		int nn = n;

		for (int it = 0; it < nn - 1; it++) {
			sort(v, v + n);

			int pos = 0;
			for (int i = 1; i < n; i++) {
				if (v[i].first == v[pos].first) {
					v[pos].second += v[i].second;
				}
				else {
					pos++;
					v[pos] = v[i];
				}
			}
			n = pos + 1;
			pos = 0;
			for (int i = 0; i < n; i++) {
				if (v[i].second > 1) {
					buf[pos++] = mp(0, v[i].second - 1);
				}

				if (i) {
					buf[pos++] = mp(v[i].first - v[i - 1].first, 1);
				}
			}

			for (int i = 0; i < pos; i++) {
				v[i] = buf[i];
			}

			n = pos;
		}

		printf("%d\n", v[0].first);
	}
	return 0;
}