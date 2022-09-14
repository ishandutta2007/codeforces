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

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
bool used[maxn];

int main() {
	scanf("%s", s);

	int len = strlen(s);

	for (int i = 0; i <= len - 26; i++) {
		memset(used, 0, sizeof used);
		bool st = true;
		for (int j = 0; j < 26; j++) {
			if (s[i + j] != '?') {
				if (used[s[i + j] - 'A']) {
					st = false;
					break;
				}

				used[s[i + j] - 'A'] = true;
			}
		}

		if (st) {
			int pos = 0;

			for (int j = 0; j < 26; j++) {
				if (s[i + j] == '?') {
					while (pos < 26 && used[pos]) {
						pos++;
					}

					used[pos] = true;

					s[i + j] = 'A' + pos;
				}
			}

			for (int j = 0; j < len; j++) {
				if (s[j] == '?') {
					s[j] = 'A';
				}
			}

			printf("%s\n", s);
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}