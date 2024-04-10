/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1010;
string s[maxn], t[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int j = 0; j < m; j++) {
		cin >> t[j];
	}

	int cnt = 0;

	sort(s, s + n);
	sort(t, t + m);

	int pos = 0;

	for (int i = 0; i < n; i++) {
		while (pos < m && t[pos] < s[i]) {
			pos++;
		}

		if (pos < m && t[pos] == s[i]) {
			cnt++;
		}
	}

	int it = 0;

	while (cnt != 0) {
		n--;
		m--;
		it ^= 1;
		cnt--;
	}

	if (it == 0) {
		if (n <= m) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	} else {
		if (m <= n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}