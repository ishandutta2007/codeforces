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
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
int e[maxn];

int main() {
	int n, u;

	cin >> n >> u;

	for (int i = 0; i < n; i++) {
		scanf("%d", &e[i]);
	}

	int r = 0;

	ll x = 0, y = 1;

	for (int i = 0; i < n - 2; i++) {
		if (r < i) {
			r = i;
		}

		while (r < n - 1 && e[r + 1] - e[i] <= u) {
			r++;
		}

		ll curx = e[r] - e[i + 1];
		ll cury = e[r] - e[i];

		if (curx * y > cury * x) {
			x = curx;
			y = cury;
		}
	}

	if (x == 0) {
		cout << -1 << endl;
		return 0;
	}

	printf("%.20lf\n", (ld)x / y);
	
	//system("pause");
}