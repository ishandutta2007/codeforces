#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;
int lnk[maxn];
int ans[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &lnk[i]);
		lnk[i]--;
	}

	for (int i = 0; i < n; i++) {
		int lm = max(i - k, 0);
		int rm = min(i + k, n - 1);

		if (lnk[i] == -1) {
			ans[i] = rm - lm + 1;
		}
		else {
			int l = max(lnk[i] - k, 0);
			int r = min(lnk[i] + k, n - 1);

			l = max(l, lm);
			r = min(r, rm);

			ans[i] = ans[lnk[i]] + rm - lm + 1 - max(0, r - l + 1);
		}

		printf("%d ", ans[i]);
	}

	//system("pause");
}