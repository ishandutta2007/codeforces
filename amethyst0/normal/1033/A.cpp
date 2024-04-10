#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool is_check(int x, int y, int ax, int ay) {
	if (x == ax || y == ay) {
		return false;
	}

	if (x - y == ax - ay) {
		return false;
	}

	if (x + y == ax + ay) {
		return false;
	}

	return true;
}

const int maxn = 1010;

bool used[maxn][maxn];

int main() {
	int n;

	cin >> n;
	int ax, ay, bx, by, cx, cy;

	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	queue <pii> q;

	q.push(mp(bx, by));
	used[bx][by] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int it = 0; it < 8; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !used[nx][ny] && is_check(nx, ny, ax, ay)) {
				q.push(mp(nx, ny));
				used[nx][ny] = true;
			}
		}
	}

	if (used[cx][cy]) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	//system("pause");
}