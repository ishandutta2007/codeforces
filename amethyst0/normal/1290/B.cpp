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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)2e5 + 10;
char s[maxn];
int cnt[26][maxn];

int sum(int c, int l, int r) {
	return (l == 0 ? cnt[c][r] : cnt[c][r] - cnt[c][l - 1]);
}

int main() {
	scanf("%s", s);

	int n = 0;
	while (s[n] != 0) {
		n++;
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			for (int j = 0; j < 26; j++) {
				cnt[j][i] = cnt[j][i - 1];
			}
		}

		cnt[s[i] - 'a'][i]++;
	}

	int q;

	cin >> q;

	while (q--) {
		int l, r;

		scanf("%d %d", &l, &r);
		l--;
		r--;

		if (s[l] != s[r] || l == r) {
			printf("Yes\n");
		}
		else {
			int sums = 0;

			for (int c = 0; c < 26; c++) {
				if (sum(c, l, r) != 0) {
					sums++;
				}
			}

			if (sums > 2) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
}