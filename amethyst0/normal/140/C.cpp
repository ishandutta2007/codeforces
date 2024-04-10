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
int r[maxn];
vector <int> g[maxn];

int n;

bool go(int cnt) {
	for (int i = 0; i < cnt; i++) {
		g[i].clear();
	}

	int fir = 0;

	for (int i = 0; i < n;) {
		int rm = i;

		while (rm < n && r[i] == r[rm]) {
			rm++;
		}

		int num = rm - i;

		num = min(num, cnt);

		while (num != 0) {
			if ((int)g[fir].size() == 3) {
				break;
			}

			g[fir].push_back(r[i]);
			num--;
			fir++;
			if (fir == cnt) {
				fir = 0;
			}
		}

		i = rm;
	}

	return (int)g[fir].size() == 3;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}

	sort(r, r + n);

	int l = 0, r = n / 3;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (go(m)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	go(l);

	cout << l << endl;

	for (int i = 0; i < l; i++) {
		sort(g[i].begin(), g[i].end());
		for (int j = 2; j >= 0; j--) {
			printf("%d ", g[i][j]);
		}

		printf("\n");
	}

	//system("pause");
}