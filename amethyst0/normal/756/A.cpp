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

const int maxn = (int)2e5 + 10;
int v[maxn];
int b[maxn];
bool used[maxn];

void go(int x) {
	used[x] = true;

	if (!used[v[x]]) {
		go(v[x]);
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	int x = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		x += b[i];
	}

	x &= 1;

	int ans = 0;

	if (x == 0) {
		ans++;
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt++;
			go(i);
		}
	}

	if (cnt != 1) {
		ans += cnt;
	}

	cout << ans << endl;

	return 0;
}