//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <limits.h>
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = 510;

int ans[maxn][maxn];

int main() {
	int n;
	cin >> n;
	memset(ans, -1, sizeof ans);

	for (int i = 0; i < n; i++) {
		int g;
		scanf("%d", &g);
		int x = i;
		int y = i;
		int col = g;
		while (g--) {
			ans[x][y] = col;
			if (y != 0 && ans[x][y - 1] == -1) {
				y--;
			}
			else {
				x++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}