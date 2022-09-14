/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
 
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

const int maxn = 155;
char t[(int)1e5 + 10];
char s[maxn][maxn];
bitset <maxn> b[maxn], now[2][maxn], c[maxn];

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int sum = 0;

	int xx = 0;
	int yy = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);

		for (int j = 0; j < m; j++) {
			if (s[i][j] != '#') {
				b[i][j] = 1;
				now[0][i][j] = 1;
				sum++;
			} else {
				c[i][j] = 1;
			}

			if (s[i][j] == 'E') {
				xx = i;
				yy = j;
			}
		}
	}

	if (sum == 1) {
		cout << 0 << endl;
		return 0;
	}

	int it = 0;

	scanf("%s", t);

	int len = strlen(t);

	for (int i = 0; i < len; i++) {
		int sum = 0;

		if (t[i] == 'L') {
			for (int j = 0; j < n; j++) {
				now[it ^ 1][j] = ((now[it][j] >> 1) & b[j]) | (now[it][j] & (c[j] << 1));
				sum += now[it ^ 1][j].count();
			}
		} else if (t[i] == 'R') {
			for (int j = 0; j < n; j++) {
				now[it ^ 1][j] = ((now[it][j] << 1) & b[j]) | (now[it][j] & (c[j] >> 1));
				sum += now[it ^ 1][j].count();
			}
		} else if (t[i] == 'D') {
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					now[it ^ 1][j] = now[it][j] & c[j + 1];
				} else if (j == n - 1) {
					now[it ^ 1][j] = now[it][j - 1] & b[j];
				} else {
					now[it ^ 1][j] = (now[it][j] & c[j + 1]) | (now[it][j - 1] & b[j]);
				}
				sum += now[it ^ 1][j].count();
			}
		} else {
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					now[it ^ 1][j] = now[it][j + 1] & b[j];
				} else if (j == n - 1) {
					now[it ^ 1][j] = now[it][j] & c[j - 1];
				} else {
					now[it ^ 1][j] = (now[it][j] & c[j - 1]) | (now[it][j + 1] & b[j]);
				}
				sum += now[it ^ 1][j].count();
			}
		}

		it ^= 1;

		if (sum == 1 && now[it][xx][yy] == 1) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}