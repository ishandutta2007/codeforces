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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 26;

bool used[maxn];

char s[(int)1e5 + 10];
bool now[26];

int main() {
	for (int i = 0; i < 26; i++) {
		used[i] = true;
	}

	int n;

	cin >> n;

	bool good = false;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		char c;

		scanf(" %c", &c);

		scanf("%s", s);

		int len = strlen(s);

		if (c == '.') {
			for (int j = 0; j < len; j++) {
				used[s[j] - 'a'] = false;
			}
		}
		else if (c == '!') {
			if (good) {
				ans++;
			}

			memset(now, 0, sizeof now);
			for (int j = 0; j < len; j++) {
				now[s[j] - 'a'] = true;
			}

			for (int j = 0; j < 26; j++) {
				if (now[j] == false) {
					used[j] = false;
				}
			}
		}
		else {
			if (good) {
				ans++;
			}

			used[s[0] - 'a'] = false;
		}

		int cnt = 0;

		for (int j = 0; j < 26; j++) {
			cnt += used[j];
		}

		if (cnt == 1) {
			good = true;
		}
	}

	cout << max(0, ans - 1) << endl;

	return 0;
}