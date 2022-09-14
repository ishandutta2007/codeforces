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
//#include <random>
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 2110;

char s[maxn];
bitset <maxn> b[maxn];
bitset <maxn> ans[maxn];
vector <int> v;
const int mag = 24;

int modd(vector <int> &x, int z) {
	vector <int> f;
	int o = 0;

	for (int i = 0; i < (int)x.size(); i++) {
		o *= 10;
		o += x[i];

		if (!f.empty() || o / z != 0) {
			f.push_back(o / z);
		}

		o %= z;
	}

	x = f;

	return o;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int len = strlen(s);

		v.clear();

		for (int j = 0; j < len; j++) {
			v.push_back(s[j] - '0');
		}

		int x = (1 << mag);
		int posit = 0;

		while (!v.empty()) {
			int y = modd(v, x);

			for (int j = posit; j < posit + mag; j++) {
				b[i][j] = y & 1;
				y >>= 1;
			}

			posit += mag;
		}
	}

	for (int i = 0; i < n; i++) {
		int pos = -1;

		for (int j = 0; j < maxn; j++) {
			if (b[i][j] == 1) {
				pos = j;
				break;
			}
		}

		if (pos == -1) {
			vector <int> f;

			for (int j = 0; j < n; j++) {
				if (ans[i][j]) {
					f.push_back(j);
				}
			}

			printf("%d ", f.size());
			
			for (int j = 0; j < (int)f.size(); j++) {
				printf("%d ", f[j]);
			}

			printf("\n");

			continue;
		}

		ans[i][i] = 1;

		for (int j = i + 1; j < n; j++) {
			if (b[j][pos] == 1) {
				b[j] ^= b[i];
				ans[j] ^= ans[i];
			}
		}

		printf("0\n");
	}

	return 0;
}