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

#define ll long long
#define ld double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1e3 + 40;
int cnt[2][maxn];

int main() {
	int n, k, x;

	cin >> n >> k >> x;

	for (int i = 0; i < n; i++) {
		int a;

		scanf("%d", &a);

		cnt[0][a]++;
	}

	int it = 1;

	for (int i = 0; i < k; i++) {
		memset(cnt[it], 0, sizeof cnt[it]);

		int f = 0;

		for (int j = 0; j < maxn; j++) {
			if (cnt[it ^ 1][j] & 1) {
				if (f == 0) {
					cnt[it][j] += cnt[it ^ 1][j] / 2;
					cnt[it][j ^ x] += (cnt[it ^ 1][j] + 1) / 2;
					f = 1;
				} else {
					cnt[it][j] += (cnt[it ^ 1][j] + 1) / 2;
					cnt[it][j ^ x] += cnt[it ^ 1][j] / 2;
					f = 0;
				}
			} else {
				cnt[it][j] += cnt[it ^ 1][j] / 2;
				cnt[it][j ^ x] += cnt[it ^ 1][j] / 2;
			}
		}

		it ^= 1;
	}

	it ^= 1;

	for (int i = maxn - 1; i >= 0; i--) {
		if (cnt[it][i] != 0) {
			cout << i << endl;
			break;
		}
	}

	for (int i = 0; i < maxn; i++) {
		if (cnt[it][i] != 0) {
			cout << i << ' ';
			break;
		}
	}

	return 0;
}