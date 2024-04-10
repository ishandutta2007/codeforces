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
char s[maxn][10];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		bool ok = false;

		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			int d = strlen(s[i]);

			bool pal = true;

			for (int j = 0; j < d; j++) {
				if (s[i][j] != s[i][d - 1 - j]) {
					pal = false;
				}
			}

			if (pal) {
				ok = true;
			}
		}

		if (ok) {
			printf("YES\n");
			continue;
		}

		set <string> f[4];

		for (int i = 0; i < n; i++) {
			string cur = "";
			int d = strlen(s[i]);
			for (int j = d - 2; j < d; j++) {
				cur.push_back(s[i][j]);
			}

			if (f[2].count(cur) || (d == 2 && f[1].count(cur))) {
				ok = true;
				break;
			}

			if (d == 3 && f[3].count(s[i])) {
				ok = true;
				break;
			}

			string h;

			for (int j = 1; j >= 0; j--) {
				h.push_back(s[i][j]);
			}

			if (d == 2) {
				f[2].insert(h);
			}
			else {
				f[1].insert(h);
			}

			if (d == 3) {
				h.clear();
				for (int j = 2; j >= 0; j--) {
					h.push_back(s[i][j]);
				}
				f[3].insert(h);
			}
		}

		if (ok) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}