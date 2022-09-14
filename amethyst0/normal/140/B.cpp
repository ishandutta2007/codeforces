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

const int maxn = 310;

int pr[maxn][maxn];
int num[maxn];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;

			scanf("%d", &x);

			pr[i][x] = j;
		}
	}

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);
		num[x] = i;
	}

	for (int i = 1; i <= n; i++) {
		int best = (int)1e9;
		int pos = -1;

		int cur = -1;

		for (int j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}

			if (cur == -1) {
				cur = j;
			}
			else if (num[cur] > num[j]) {
				cur = j;
			}

			if (pr[i][cur] < best) {
				best = pr[i][cur];
				pos = j;
			}
		}

		printf("%d ", pos);
	}

	//system("pause");
}