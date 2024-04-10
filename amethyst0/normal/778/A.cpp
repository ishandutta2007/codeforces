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
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
bool used[maxn];

int main() {
	string s, t;

	cin >> s >> t;

	int n = (int)s.size();

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i]--;
	}

	int l = 0;
	int r = n - 1;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		for (int i = 0; i < m; i++) {
			used[v[i]] = true;
		}

		int pos = 0;

		for (int i = 0; i < n; i++) {
			if (used[i]) {
				continue;
			}

			if (pos < (int)t.size() && s[i] == t[pos]) {
				pos++;
			}
		}

		for (int i = 0; i < m; i++) {
			used[v[i]] = false;
		}

		if (pos == (int)t.size()) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	cout << l << endl;

	return 0;
}