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
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
ll v[maxn];
int num[50];
int mus[50];
int ans[50];

bool check() {
	int cnt = 0;

	for (int i = 49; i >= 0; i--) {
		cnt += ans[i];

		if (mus[i] > cnt) {
			return false;
		}

		cnt -= mus[i];
	}

	return true;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);

		ll st = 1;
		int cnt = 0;

		while (2 * st < v[i]) {
			st *= 2;
			cnt++;
		}

		mus[cnt]++;
		
		if (v[i] == 1) {
			num[0]++;
		} else if (v[i] == 2 * st) {
			num[cnt + 1]++;
		}
	}

	int l = -1;
	int r = -1;

	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 0; j < 50; j++) {
			if (num[j] == 0) {
				now = j - 1;
				break;
			}
		}

		if (now == -1) {
			break;
		}

		ans[now]++;

		for (int j = 0; j <= now; j++) {
			num[j]--;

			if (j != 0) {
				mus[j - 1]--;
			} else {
				mus[j]--;
			}
		}

		if (check()) {
			if (l == -1) {
				l = i;
			}

			r = i;
		}
	}

	if (l == -1) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = l; i <= r; i++) {
		printf("%d ", i);
	}

	return 0;
}