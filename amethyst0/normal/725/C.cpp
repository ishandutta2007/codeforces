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
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int pos[26];
char res[2][13];

int main() {
	string s;

	cin >> s;

	memset(pos, -1, sizeof pos);
	int l = -1, r = -1;

	for (int i = 0; i < (int)s.size(); i++) {
		int x = s[i] - 'A';

		if (pos[x] == -1) {
			pos[x] = i;
		} else {
			l = pos[x];
			r = i;
		}
	}

	if (l + 1 == r) {
		cout << "Impossible" << endl;
		return 0;
	}

	int cnt = r - l - 1;

	for (int i = 0; i <= 12; i++) {
		int now = cnt;

		int posit = i;
		int dx = 1;

		while (now != 0) {
			now--;

			if (posit == 12 && dx == 1) {
				dx = -1;
				continue;
			}

			posit += dx;
		}

		if (abs(posit - i) > 1 || dx == 1) {
			continue;
		}

		now = cnt;
		posit = i;
		dx = 1;

		int g = 0;
		int w = l;

		while (now != 0) {
			res[g][posit] = s[w];
			w++;
			now--;

			if (posit == 12 && dx == 1) {
				dx = -1;
				g = 1;
				continue;
			}

			posit += dx;
		}

		res[g][posit] = s[w];
		w++;

		posit = i;
		dx = -1;
		g = 0;

		while (w != l) {
			res[g][posit] = s[w];
			w++;
			if (w == (int)s.size()) {
				w = 0;
			}

			if (posit == 0 && dx == -1) {
				dx = 1;
				g = 1;
				continue;
			}

			posit += dx;
		}

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 13; k++) {
				printf("%c", res[j][k]);
			}

			printf("\n");
		}

		return 0;
	}

	throw 1;
}