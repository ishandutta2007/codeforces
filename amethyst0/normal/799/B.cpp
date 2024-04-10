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

using namespace std;

const int maxn = (int)2e5 + 10;
int p[maxn];
int a[maxn];
int b[maxn];
vector <pii> z[5];

set <int> s;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);

		s.insert(i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		z[a[i]].push_back(mp(p[i], i));
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);

		z[b[i]].push_back(mp(p[i], i));
	}

	for (int i = 1; i <= 3; i++) {
		sort(z[i].rbegin(), z[i].rend());
	}

	int m;

	cin >> m;

	while (m--) {
		int c;

		scanf("%d", &c);

		while (!z[c].empty() && !s.count(z[c].back().second)) {
			z[c].pop_back();
		}

		if (z[c].empty()) {
			printf("-1 ");
		} else {
			printf("%d ", z[c].back().first);
			s.erase(z[c].back().second);
		}
	}

	return 0;
}