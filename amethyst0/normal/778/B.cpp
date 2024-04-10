/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 5010;

map <string, int> d;
string s[maxn];
string a[maxn], b[maxn];
bool st[maxn];
string op[maxn];
int bita[maxn], bitb[maxn];

int getcy(int w, int i, int j, int h) {
	if (w == 0) {
		if (a[i].size() == 1 && a[i][0] == '?') {
			return h;
		}

		int pos = d[a[i]];

		if (h == 0) {
			return bita[pos];
		} else {
			return bitb[pos];
		}
	}

	if (b[i].size() == 1 && b[i][0] == '?') {
		return h;
	}

	int pos = d[b[i]];

	if (h == 0) {
		return bita[pos];
	} else {
		return bitb[pos];
	}
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	scanf("%*c");

	for (int i = 0; i < n; i++) {
		char c;

		while (scanf("%c", &c) != EOF) {
			if (c == ' ') {
				break;
			}

			s[i].push_back(c);
		}

		d[s[i]] = i;

		scanf("%*c%*c%*c");

		while (scanf("%c", &c) != EOF) {
			if (c == ' ') {
				st[i] = true;
				break;
			}

			if (c == '\n') {
				break;
			}

			a[i].push_back(c);
		}

		if (st[i]) {
			while (scanf("%c", &c) != EOF) {
				if (c == ' ') {
					break;
				}

				op[i].push_back(c);
			}

			while (scanf("%c", &c) != EOF) {
				if (c == '\n') {
					break;
				}

				b[i].push_back(c);
			}
		}
	}

	string ans1, ans2;

	for (int j = 0; j < m; j++) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			if (!st[i]) {
				if (a[i][j] == '1') {
					bita[i] = 1;
					bitb[i] = 1;
					cnt1++;
					cnt2++;
				} else {
					bita[i] = 0;
					bitb[i] = 0;
				}
			} else {
				int c1 = getcy(0, i, j, 0);
				int c2 = getcy(1, i, j, 0);

				if (op[i][0] == 'X') {
					bita[i] = (c1 ^ c2);
					cnt1 += (c1 ^ c2);
				} else if (op[i][0] == 'A') {
					bita[i] = (c1 & c2);
					cnt1 += (c1 & c2);
				} else {
					bita[i] = (c1 | c2);
					cnt1 += (c1 | c2);
				}

				c1 = getcy(0, i, j, 1);
				c2 = getcy(1, i, j, 1);

				if (op[i][0] == 'X') {
					bitb[i] = (c1 ^ c2);
					cnt2 += (c1 ^ c2);
				} else if (op[i][0] == 'A') {
					bitb[i] = (c1 & c2);
					cnt2 += (c1 & c2);
				} else {
					bitb[i] = (c1 | c2);
					cnt2 += (c1 | c2);
				}
			}
		}

		if (cnt1 <= cnt2) {
			ans1.push_back('0');
		} else {
			ans1.push_back('1');
		}

		if (cnt1 >= cnt2) {
			ans2.push_back('0');
		} else {
			ans2.push_back('1');
		}
	}

	cout << ans1 << endl << ans2 << endl;

	return 0;
}