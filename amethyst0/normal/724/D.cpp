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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
char t[maxn];
bool used[maxn];

int main() {
	int n;

	cin >> n;

	scanf("%s", s);
	int len = strlen(s);

	for (char c = 'a'; c <= 'z'; c++) {
		for (int i = 0; i < len; i++) {
			if (s[i] == c) {
				used[i] = true;
			}
		}

		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += used[i];
		}

		if (sum == 0) {
			continue;
		}

		bool st = true;

		for (int i = 0; i < len - n; i++) {
			sum -= used[i];
			sum += used[i + n];

			if (sum == 0) {
				st = false;
				break;
			}
		}

		if (!st) {
			continue;
		}

		set <int> f;

		for (int i = 0; i < len; i++) {
			if (s[i] == c) {
				f.insert(i);
				used[i] = false;
			}
		}

		sum = 0;

		for (int i = 0; i < n; i++) {
			sum += used[i];
		}

		for (int i = 0; i <= len - n; i++) {
			if (sum == 0) {
				auto it = f.lower_bound(i + n);
				it--;

				sum++;
				used[*it] = true;
			}

			if (i + n == len) {
				break;
			}

			sum -= used[i];
			sum += used[i + n];
		}

		break;
	}

	int m = 0;

	for (int i = 0; i < len; i++) {
		if (used[i]) {
			t[m++] = s[i];
		}
	}

	sort(t, t + m);

	printf("%s", t);

	return 0;
}