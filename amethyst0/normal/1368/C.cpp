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
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
int v[maxn];
int cnt[maxn];

int main() {
	int n;

	cin >> n;

	vector <pii> g;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0 && j == 2) {
				continue;
			}

			if (i == 2 && j == 0) {
				continue;
			}

			g.push_back(mp(i, j));
		}
	}

	n--;

	int x = 2, y = 2;

	while (n--) {
		g.push_back(mp(x + 1, y + 1));
		g.push_back(mp(x + 1, y));
		g.push_back(mp(x, y + 1));
		x++;
		y++;
	}

	cout << g.size() << '\n';

	for (pii f : g) {
		printf("%d %d\n", f.first, f.second);
	}
}