//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 65;
char c[maxn][maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m;

		scanf("%d %d", &n, &m);

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			scanf("%s", c[i]);

			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'P') {
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			printf("%d\n", 0);
			continue;
		}

		if (cnt == n * m) {
			printf("MORTAL\n");
			continue;
		}

		int a = 0, b = 0;

		for (int i = 0; i < n; i++) {
			if (c[i][0] == 'P') {
				a++;
			}

			if (c[i][m - 1] == 'P') {
				b++;
			}
		}

		if (a == 0 || b == 0) {
			printf("1\n");
			continue;
		}

		a = 0;
		b = 0;

		for (int j = 0; j < m; j++) {
			if (c[0][j] == 'P') {
				a++;
			}

			if (c[n - 1][j] == 'P') {
				b++;
			}
		}

		if (a == 0 || b == 0) {
			printf("1\n");
			continue;
		}

		bool ok = false;

		for (int i = 0; i < n; i++) {
			int cnt = 0;

			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'P') {
					cnt++;
				}
			}

			if (cnt == 0) {
				ok = true;
				break;
			}
		}

		for (int j = 0; j < m; j++) {
			int cnt = 0;

			for (int i = 0; i < n; i++) {
				if (c[i][j] == 'P') {
					cnt++;
				}
			}

			if (cnt == 0) {
				ok = true;
				break;
			}
		}

		if (ok || c[0][0] == 'A' || c[n - 1][0] == 'A' || c[0][m - 1] == 'A' || c[n - 1][m - 1] == 'A') {
			printf("2\n");
			continue;
		}

		a = 0;
		b = 0;

		for (int i = 0; i < n; i++) {
			if (c[i][0] == 'A') {
				a++;
			}

			if (c[i][m - 1] == 'A') {
				b++;
			}
		}

		if (a != 0 || b != 0) {
			printf("3\n");
			continue;
		}

		a = 0;
		b = 0;

		for (int j = 0; j < m; j++) {
			if (c[0][j] == 'A') {
				a++;
			}

			if (c[n - 1][j] == 'A') {
				b++;
			}
		}

		if (a != 0 || b != 0) {
			printf("3\n");
			continue;
		}

		printf("4\n");
	}

	//system("pause");
}