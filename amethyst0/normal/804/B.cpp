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
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

const int maxn = (int)1e6 + 10, mod = (int)1e9 + 7;
char s[maxn];
int st[maxn];

int main() {
	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * 2;

		if (st[i] >= mod) {
			st[i] -= mod;
		}
	}

	for (int i = 1; i < maxn; i++) {
		st[i] += st[i - 1];
		
		if (st[i] >= mod) {
			st[i] -= mod;
		}
	}

	int cnt = 0;

	scanf("%s", s);
	int len = strlen(s);

	int ans = 0;

	for (int i = 0; i < len; i++) {
		if (s[i] == 'a') {
			cnt++;
		} else {
			if (cnt != 0) {
				ans += st[cnt - 1];

				if (ans >= mod) {
					ans -= mod;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}