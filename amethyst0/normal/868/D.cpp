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

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 210, magic = 15;

string s[maxn];
bitset <(1 << magic)> b[maxn][magic + 1];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];

		for (int j = 0; j < (int)s[i].size(); j++) {
			int now = 0;

			for (int k = j; k < (int)s[i].size(); k++) {
				if (k - j + 1 > magic) {
					break;
				}

				now <<= 1;
				now += s[i][k] - '0';
				b[i][k - j + 1][now] = 1;
			}
		}
	}

	int m;

	cin >> m;
	int p = n;

	while (m--) {
		int a, c;

		cin >> a >> c;
		a--;
		c--;

		s[p] = s[a] + s[c];
		
		for (int i = 1; i <= magic; i++) {
			b[p][i] = b[a][i] | b[c][i];
		}

		for (int i = 1; i <= (int)s[a].size(); i++) {
			if (i > magic) {
				break;
			}

			int now = 0;

			for (int j = (int)s[a].size() - i; j < (int)s[a].size(); j++) {
				now <<= 1;
				now += s[a][j] - '0';
			}

			for (int j = 1; j <= (int)s[c].size(); j++) {
				if (i + j > magic) {
					break;
				}

				now <<= 1;
				now += s[c][j - 1] - '0';

				b[p][i + j][now] = 1;
			}
		}

		int ans = 0;

		for (int i = 1; i <= magic; i++) {
			int fl = 0;
			for (int j = 0; j < (1 << i); j++) {
				if (b[p][i][j] == 0) {
					fl = 1;
					break;
				}
			}

			if (fl == 0) {
				ans++;
			} else {
				break;
			}
		}

		if ((int)s[p].size() > 2 * magic) {
			string s1, s2;

			for (int i = 0; i < magic; i++) {
				s1.push_back(s[p][i]);
			}

			for (int i = (int)s[p].size() - magic; i < (int)s[p].size(); i++) {
				s2.push_back(s[p][i]);
			}

			s[p] = s1 + s2;
		}

		p++;

		cout << ans << endl;
	}

	return 0;
}