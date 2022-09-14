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
#define ull unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
int p[maxn];

int main() {
	int h;

	cin >> h;

	for (int i = 0; i <= h; i++) {
		scanf("%d", &v[i]);
	}

	bool fl = true;

	for (int i = 0; i < h; i++) {
		if (v[i] > 1 && v[i + 1] > 1) {
			fl = false;
		}
	}

	if (fl) {
		cout << "perfect" << endl;
		return 0;
	}

	cout << "ambiguous" << endl;

	int pos = 2;
	int last = 1;

	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < v[i]; j++) {
			p[pos + j] = last;
		}

		last = pos;
		pos += v[i];
	}

	for (int i = 1; i < pos; i++) {
		printf("%d ", p[i]);
	}

	printf("\n");

	pos = 2;
	last = 1;

	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < v[i]; j++) {
			p[pos + j] = last;
		}

		if (v[i - 1] > 1 && v[i] > 1) {
			p[pos + v[i] - 1] = last + 1;
		}

		last = pos;
		pos += v[i];
	}

	for (int i = 1; i < pos; i++) {
		printf("%d ", p[i]);
	}
}