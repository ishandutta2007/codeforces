/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define uint unsigned int
#define pb push_back
#define sz(a) (int)(a.size())

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
int ans[maxn];
vector <int> t[1000];
int len;
char y[maxn];

char c[4] = {'A', 'T', 'G', 'C'};

void change(int it, int pos, int z) {
	if (z == 0) {
		return;
	}

	for ( ; pos < (int)t[it].size(); pos |= pos + 1) {
		t[it][pos] += z;
	}
}

int go(int it, int pos) {
	int ans = 0;

	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[it][pos];
	}

	return ans;
}

int go(int pos, int l, int r) {
	return go(pos, r) - go(pos, l - 1);
}

int main() {
	scanf("%s", s);

	len = strlen(s);

	for (int d = 1; d <= 10; d++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < len; j++) {
				int pos = (10 * i + d - 1) * 10 + j % d;
				t[pos].resize(len / d + 1);

				change(pos, j / d, c[i] != s[j]);
			}
		}
	}

	int q;

	scanf("%d", &q);

	while (q--) {
		int tp;

		scanf("%d", &tp);

		if (tp == 1) {
			int x;
			char f;

			scanf("%d %c", &x, &f);

			x--;

			int g = 0;

			for (int i = 0; i < 4; i++) {
				if (c[i] == f) {
					g = i;
				}
			}

			for (int d = 1; d <= 10; d++) {
				for (int i = 0; i < 4; i++) {
					int pos = (10 * i + d - 1) * 10 + x % d;

					if (s[x] != c[i] && c[g] == c[i]) {
						change(pos, x / d, -1);
					} else if (s[x] == c[i] && c[g] != c[i]) {
						change(pos, x / d, 1);
					}
				}
			}

			s[x] = c[g];
		} else {
			int l, r;

			scanf("%d %d %s", &l, &r, y);

			l--;
			r--;

			int lens = strlen(y);

			int ans = 0;

			for (int i = 0; i < lens; i++) {
				if (l + i > r) {
					break;
				}

				int g = 0;

				for (int j = 0; j < 4; j++) {
					if (c[j] == y[i]) {
						g = j;
					}
				}

				int pos = (10 * g + lens - 1) * 10 + (l + i) % lens;

				int cnt = (r - l - i) / lens;

				ans += go(pos, (l + i) / lens, (l + i + cnt * lens) / lens);
			}

			printf("%d\n", r - l + 1 - ans);
		}
	}

	return 0;
}