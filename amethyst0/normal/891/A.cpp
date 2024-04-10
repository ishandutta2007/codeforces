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

const int maxn = 2010;
int v[maxn];

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	int n;

	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		if (v[i] == 1) {
			cnt++;
		}
	}

	if (cnt != 0) {
		cout << n - cnt << endl;
		return 0;
	}

	int ans = n + 1;

	for (int i = 0; i < n; i++) {
		int now = v[i];
		for (int j = i + 1; j < n; j++) {
			now = gcd(now, v[j]);

			if (now == 1) {
				ans = min(ans, j - i + 1);
				break;
			}
		}
	}

	if (ans != n + 1) {
		cout << n - 1 + ans - 1 << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}