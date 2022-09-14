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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e6 + 10;

void print(int x, int y) {
	printf("%d %d\n", x + 1, y + 1);
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int p = n - i - 1;

		if (i > p) {
			break;
		}

		if (i < p) {
			if (i % 2 == 0) {
				for (int j = 0; j < m; j++) {
					print(i, j);
					print(p, m - j - 1);
				}
			}
			else {
				for (int j = m - 1; j >= 0; j--) {
					print(i, j);
					print(p, m - j - 1);
				}
			}
		}
		else {
			for (int j = 0; j < m; j++) {
				int x = m - 1 - j;

				if (x < j) {
					break;
				}

				if (i % 2 == 0) {
					print(i, j);
				}
				else {
					print(i, m - 1 - j);
				}

				if (x != j) {
					if (i % 2 == 0) {
						print(i, m - 1 - j);
					}
					else {
						print(i, j);
					}
				}
			}
		}
	}

	//system("pause");

	return 0;
}