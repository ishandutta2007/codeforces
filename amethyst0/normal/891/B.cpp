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

const int maxn = 25;
pii v[maxn];
int ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].first);
		v[i].second = i;
	}

	sort(v, v + n);

	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			ans[v[i].second] = v[i + 1].first;
		}
		else {
			ans[v[i].second] = v[0].first;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
}