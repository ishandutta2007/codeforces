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

char s[1010];
int cnt[4], p[4];

int main() {
	cin >> s;
	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		if (s[i] == '!') {
			cnt[i % 4]++;
		} else {
			if (s[i] == 'R') {
				p[0] = i % 4;
			} else if (s[i] == 'B') {
				p[1] = i % 4;
			} else if (s[i] == 'Y') {
				p[2] = i % 4;
			} else {
				p[3] = i % 4;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << cnt[p[i]] << ' ';
	}

	return 0;
}