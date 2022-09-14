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
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10;
pii v[maxn];
int n;

int get_cnt(int pos, int x) {
	int l = 1;
	int r = n + 1;

	while (l != r) {
		int m = (l + r) >> 1;

		if ((x + m - 1) / m <= v[pos].first) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	return l;
}

int main() {
	//freopen("output.txt", "w", stdout);
	int x1, x2;

	cin >> n >> x1 >> x2;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].first);
		v[i].second = i;
	}

	sort(v, v + n);

	int last1 = -1;
	int last2 = -1;

	for (int i = n - 1; i >= 0; i--) {
		int cnt1 = get_cnt(i, x1);
		int cnt2 = get_cnt(i, x2);

		if (i + cnt1 <= n && last1 == -1) {
			last1 = i;
		}

		if (i + cnt2 <= n && last2 == -1) {
			last2 = i;
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt = get_cnt(i, x1);

		if (last2 >= i + cnt) {
			printf("Yes\n");

			printf("%d %d\n", cnt, n - last2);

			for (int j = i; j < i + cnt; j++) {
				printf("%d ", v[j].second + 1);
			}

			printf("\n");

			for (int j = last2; j < n; j++) {
				printf("%d ", v[j].second + 1);
			}

			return 0;
		}

		cnt = get_cnt(i, x2);

		if (last1 >= i + cnt) {
			printf("Yes\n");

			printf("%d %d\n", n - last1, cnt);

			for (int j = last1; j < n; j++) {
				printf("%d ", v[j].second + 1);
			}

			printf("\n");

			for (int j = i; j < i + cnt; j++) {
				printf("%d ", v[j].second + 1);
			}

			return 0;
		}
	}

	printf("No\n");

	//system("pause");
}