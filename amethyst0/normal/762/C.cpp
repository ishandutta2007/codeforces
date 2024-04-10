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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

char s[maxn], t[maxn];
int lnk[maxn][26];
int lens, lent;
int pos[2][maxn];

void make(int it) {
	memset(lnk[lens], -1, sizeof lnk[lens]);

	for (int i = lens - 1; i >= 0; i--) {
		memcpy(lnk[i], lnk[i + 1], sizeof lnk[i + 1]);

		lnk[i][s[i] - 'a'] = i;
	}

	int now = 0;

	memset(pos[it], -1, sizeof pos[it]);

	for (int i = 0; i < lent; i++) {
		pos[it][i] = lnk[now][t[i] - 'a'];
		now = pos[it][i] + 1;

		if (pos[it][i] == -1) {
			break;
		}
	}

	pos[it][lent] = 0;
}

int main() {
	scanf("%s %s", s, t);

	lens = strlen(s);
	lent = strlen(t);

	make(0);
	reverse(s, s + lens);
	reverse(t, t + lent);
	make(1);

	int w = lent;

	reverse(pos[1], pos[1] + lent);
	pos[1][lent] = -1;

	for (int i = 0; i <= lent; i++) {
		if (pos[1][i] != -1) {
			w = i;
			break;
		}
	}

	for (int i = w; i <= lent; i++) {
		pos[1][i] = lens - pos[1][i] - 1;
	}

	int l = -1;
	int r = w;

	for (int i = 0; i < lent; i++) {
		if (pos[0][i] == -1) {
			continue;
		}

		int x = upper_bound(pos[1] + w, pos[1] + lent + 1, pos[0][i]) - pos[1];

		if (r - l > x - i) {
			l = i;
			r = x;
		}
	}

	if (r <= l + 1) {
		r = l + 1;
	}

	if (l + 1 == 0 && r == lent) {
		cout << '-' << endl;
		return 0;
	}

	reverse(t, t + lent);

	for (int i = 0; i <= l; i++) {
		printf("%c", t[i]);
	}

	for (int i = r; i < lent; i++) {
		printf("%c", t[i]);
	}

	return 0;
}