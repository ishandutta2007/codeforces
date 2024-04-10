#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)1e5 + 10;
int cnt = 0;
int s[2][maxn];

int n;

int f(int pos) {
	return (s[0][pos] == 0 && s[0][pos + 1] == 0) || (s[1][pos] == 0 && s[1][pos + 1] == 0);
}

void change(int x, int y) {
	if (y != n - 1) {
		cnt -= f(y) ^ 1;
	}

	if (y != 0) {
		cnt -= f(y - 1) ^ 1;
	}

	s[x][y] ^= 1;

	if (y != n - 1) {
		cnt += f(y) ^ 1;
	}

	if (y != 0) {
		cnt += f(y - 1) ^ 1;
	}
}

int main() {
	int q;

	cin >> n >> q;

	while (q--) {
		int x, y;

		scanf("%d %d", &x, &y);

		x--;
		y--;
		change(x, y);

		if (cnt == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}