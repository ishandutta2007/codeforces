//#pragma comment(linker, "/STACK:1000000000")
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
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
pii v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			v[i] = mp(x, i & 1);
		}

		sort(v, v + n);

		bool ok = true;

		for (int i = 0; i < n; ) {
			int r = i;

			int cnt0 = 0, cnt1 = 0;

			while (r < n && v[i].first == v[r].first) {
				if (r & 1) {
					cnt1++;
				}
				else {
					cnt0++;
				}

				if (v[r].second) {
					cnt1--;
				}
				else {
					cnt0--;
				}
				r++;
			}

			if (cnt0 != 0 || cnt1 != 0) {
				ok = false;
				break;
			}

			i = r;
		}

		if (ok) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}