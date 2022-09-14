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

const int maxn = 3010;

char a[maxn][maxn], b[maxn][maxn];

struct vt {
	int len;
	int lnk;
	int pos;
	int ed[26];

	vt() {
		len = 0;
		lnk = -1;
		pos = -1;
		memset(ed, -1, sizeof ed);
	}
};

vt mas[2 * maxn];
int posit = 0;

int my_new() {
	mas[posit] = vt();
	return posit++;
}

void add_let(int &last, int c) {
	int cur = my_new();

	int p = last;

	mas[cur].len = mas[p].len + 1;
	mas[cur].pos = mas[cur].len - 1;

	for (; p != -1 && mas[p].ed[c] == -1; p = mas[p].lnk) {
		mas[p].ed[c] = cur;
	}

	if (p == -1) {
		mas[cur].lnk = 0;
	}
	else {
		int q = mas[p].ed[c];

		if (mas[q].len == mas[p].len + 1) {
			mas[cur].lnk = q;
		}
		else {
			int clone = my_new();
			mas[clone].len = mas[p].len + 1;
			mas[clone].pos = mas[q].pos;
			mas[clone].lnk = mas[q].lnk;
			memcpy(mas[clone].ed, mas[q].ed, sizeof mas[q].ed);

			for (; p != -1 && mas[p].ed[c] == q; p = mas[p].lnk) {
				mas[p].ed[c] = clone;
			}

			mas[cur].lnk = mas[q].lnk = clone;
		}
	}

	last = cur;
}

int pos, l, r;

bool cor(int i) {
	posit = 0;

	int t = my_new();

	int len = strlen(a[i]);

	for (int j = 0; j < len; j++) {
		int c = a[i][j] - 'a';

		add_let(t, c);
	}

	t = 0;
	for (int j = l; j <= r; j++) {
		int c = a[pos][j] - 'a';

		if (mas[t].ed[c] == -1) {
			t = -1;
			break;
		}

		t = mas[t].ed[c];
	}

	int fir = -(int)1e9;

	if (t != -1) {
		fir = mas[t].pos - (r - l);
		if (fir < 0) {
			throw 1;
		}
	}

	for (int j = 0; j < len; j++) {
		if (fir <= j && j <= fir + r - l) {
			if (b[pos][l + j - fir] != b[i][j]) {
				return false;
			}
		}
		else if (a[i][j] != b[i][j]) {
			return false;
		}
	}

	return true;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}

	pos = -1;

	int bl, br;
	int blen;

	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);

		int len = strlen(b[i]);

		int lm = len;
		int rm = -1;

		for (int j = 0; j < len; j++) {
			if (a[i][j] != b[i][j]) {
				lm = min(lm, j);
				rm = max(rm, j);
			}
		}

		if (rm == -1) {
			continue;
		}

		if (pos == -1) {
			pos = i;
			l = lm;
			r = rm;
			bl = 0;
			br = len - 1;
			blen = len;
		}
		else {
			if (rm - lm + 1 != r - l + 1) {
				cout << "NO\n";
				return 0;
				//continue;
			}

			for (int j = l; j <= r; j++) {
				if (a[pos][j] != a[i][j - l + lm] || b[pos][j] != b[i][j - l + lm]) {
					cout << "NO\n";
					return 0;
				}
			}

			int p = -1;

			while (l + p >= 0 && lm + p >= 0 && a[i][lm + p] == a[pos][l + p]) {
				p--;
			}

			bl = max(bl, l + p + 1);

			p = 1;

			while (rm + p < len && r + p < blen && a[i][rm + p] == a[pos][r + p]) {
				p++;
			}

			br = min(br, r + p - 1);
		}
	}

	if (pos == -1) {
		throw 1;
	}

	l = bl;
	r = br;

	bool fl = true;

	for (int i = 0; i < n; i++) {
		if (!cor(i)) {
			fl = false;
			break;
		}
	}

	if (!fl) {
		printf("NO\n");
	}
	else {
		printf("YES\n");

		for (int i = l; i <= r; i++) {
			printf("%c", a[pos][i]);
		}

		printf("\n");

		for (int i = l; i <= r; i++) {
			printf("%c", b[pos][i]);
		}

		printf("\n");
	}

	//system("pause");
}