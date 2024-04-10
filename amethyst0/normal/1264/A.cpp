//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)4e5 + 10;
int p[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		vector <int> f;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
		}

		for (int i = 0; i < n; ) {
			int r = i;

			while (r < n && p[r] == p[i]) {
				r++;
			}

			int cnt = r - i;

			if ((n - r) * 2 >= n) {
				f.push_back(cnt);
				i = r;
				continue;
			}

			break;
		}

		if ((int)f.size() < 3) {
			printf("0 0 0\n");
			continue;
		}

		int x = f[0];

		int pos = 1;
		int y = 0;

		while (pos < (int)f.size() && y <= x) {
			y += f[pos];
			pos++;
		}

		if (y <= x) {
			printf("0 0 0\n");
			continue;
		}

		int z = 0;

		while (pos < (int)f.size()) {
			z += f[pos];
			pos++;
		}

		if (z <= x) {
			printf("0 0 0\n");
			continue;
		}

		printf("%d %d %d\n", x, y, z);
	}

	//system("pause");
}