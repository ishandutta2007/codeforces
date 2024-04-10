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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10, maxlog = 19;
int v[maxn];
int p[maxlog];
int pos[maxlog][maxn];

int main() {
	int n, q;

	cin >> n >> q;

	for (int i = 0; i < maxlog; i++) {
		p[i] = n;
		pos[i][n] = n;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int b = 0; b < maxlog; b++) {
			if ((v[i] >> b) & 1) {
				pos[b][i] = i;
			}
			else {
				pos[b][i] = n;

				for (int j = 0; j < maxlog; j++) {
					if ((v[i] >> j) & 1) {
						pos[b][i] = min(pos[b][i], pos[b][p[j]]);
					}
				}
			}
		}

		for (int b = 0; b < maxlog; b++) {
			if ((v[i] >> b) & 1) {
				p[b] = i;
			}
		}
	}

	while (q--) {
		int x, y;
		
		scanf("%d %d", &x, &y);

		x--;
		y--;

		int ans = 0;

		for (int b = 0; b < maxlog; b++) {
			if (((v[y] >> b) & 1) && pos[b][x] <= y) {
				ans = 1;
			}
		}

		if (ans == 1) {
			printf("Shi\n");
		}
		else {
			printf("Fou\n");
		}
	}

	//system("pause");
}