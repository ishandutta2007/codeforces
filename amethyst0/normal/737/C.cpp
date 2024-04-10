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
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

int main() {
	int n, s;

	cin >> n >> s;

	multiset <int> q;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

		if (v[i] == 0 && i != s) {
			v[i] = (int)1e9;
		}

		q.insert(v[i]);
	}

	int cnt = 0;

	if (v[s] != 0) {
		q.erase(q.find(v[s]));
		cnt++;
		q.insert(0);
	}

	int now = 0;

	while (!q.empty()) {
		int z = *q.begin();
		q.erase(q.begin());

		if (z <= now + 1) {
			now = max(now, z);
			continue;
		}

		q.insert(z);

		int f = *q.rbegin();

		cnt++;

		q.erase(q.find(f));
		q.insert(now + 1);
		now++;
	}

	cout << cnt << endl;

	return 0;
}