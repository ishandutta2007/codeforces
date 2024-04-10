#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = -1;

int n, k, q;
int a[5555];
char mn[(int)(2e8 + 10)];

int main() {
/*#ifndef __ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif*/
	
	while (scanf("%d%d", &n, &k) == 2) {
		memset(mn, 63, sizeof(mn));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				mn[a[i] * j] = min(mn[a[i] * j], (char)j);
			}
		}
		scanf("%d", &q);
		for (int it = 0; it < q; it++) {
			int x;
			scanf("%d", &x);

			char ans = 100;
			for (int i = 0; i < n; i++) {
				for (int j = 1; j <= k; j++) {
					if (x - a[i] * j < 0) break;
					ans = min(ans, (char)(j + mn[x - a[i] * j]));
				}
			}
			if (ans > k) ans = -1;
			printf("%d\n", (int)(ans));
		}
	}

	return 0;
}