#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)3e6 + 10;
int cnt[maxn];
int v[maxn];

void push(int x, int pos) {
	if (cnt[x] == 2) {
		return;
	}

	if (x < (1 << pos)) {
		cnt[x]++;
		return;
	}

	push(x, pos + 1);

	if ((x >> pos) & 1) {
		push(x ^ (1 << pos), pos + 1);
	}
}

int maxlog = 21;

int main() {
	int n;

	srand(10);

	cin >> n;
	//n = 200;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		//v[i] = rand() % 10000;
	}

	/*int res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				res = max(res, v[i] | (v[j] & v[k]));
			}
		}
	}

	cout << res << endl;
	*/
	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (i >= n - 2) {
			push(v[i], 0);
			continue;
		}

		int x = v[i];

		x ^= (1 << maxlog) - 1;

		int y = 0;

		for (int j = maxlog - 1; j >= 0; j--) {
			if ((x >> j) & 1) {
				if (cnt[y ^ (1 << j)] == 2) {
					y ^= (1 << j);
				}
			}
		}

		ans = max(ans, v[i] | y);

		push(v[i], 0);
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}