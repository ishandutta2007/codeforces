/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = 50;
int n, m;
int v[maxn][maxn];

bool go(int a, int b) {
	for (int i = 0; i < n; i++) {
		int sum = 0;

		for (int j = 0; j < m; j++) {
			if (j == a && v[i][j] != b) {
				sum++;
			} else if (j == b && v[i][j] != a) {
				sum++;
			} else if (j != a && j != b && v[i][j] != j) {
				sum++;
			}
		}

		if (sum > 2) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (go(i, j)) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}