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
pii a[maxn];
pii b[maxn];
int ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}

	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);

	for (int i = 0; i < n; i++) {
		ans[b[i].second] = a[i].first;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
}