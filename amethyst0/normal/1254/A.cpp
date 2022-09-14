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

const int maxn = 110;
char s[maxn][maxn];
int k;

int get_c(int n) {
	if (n < 26) {
		return 'a' + n;
	}

	n -= 26;

	if (n < 26) {
		return 'A' + n;
	}

	n -= 26;

	return '0' + n;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m;

		cin >> n >> m >> k;

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);

			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'R') {
					cnt++;
				}
			}
		}

		int x = 0;
		int y = 0;
		int dy = 1;
		int it = 0;

		while (k > 0) {
			int num = cnt / k;
			if (cnt % k != 0) {
				num++;
			}

			k--;

			cnt -= num;

			char c = get_c(it);
			it++;

			while (num >= 0 && x < n) {
				if (num == 0 && s[x][y] == 'R') {
					break;
				}

				if (s[x][y] == 'R') {
					num--;
				}

				s[x][y] = c;
				y += dy;

				if (y == m) {
					x++;
					y = m - 1;
					dy = -1;
				}

				if (y == -1) {
					x++;
					y = 0;
					dy = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			printf("%s\n", s[i]);
		}
	}

	//system("pause");
}