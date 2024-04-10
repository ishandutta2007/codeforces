//#pragma comment(linker, "/STACK:1000000000")
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 1;
pii v[maxn];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		v[i] = mp(x, y);
	}

	if (n == 2) {
		cout << 1 << '\n' << 1 << '\n';
		return 0;
	}

	while (true) {
		int mask = 0;

		for (int i = 0; i < n; i++) {
			int x = (v[i].first + v[i].second) & 1;
			mask |= 1 << x;
		}

		vector <int> a;

		if (mask == 3) {
			for (int i = 0; i < n; i++) {
				if ((v[i].first + v[i].second) & 1) {
					a.push_back(i);
				}
			}

			cout << a.size() << '\n';
			for (int x : a) {
				printf("%d ", x + 1);
			}

			cout << '\n';

			return 0;
		}

		for (int i = 0; i < n; i++) {
			int x = v[i].first + v[i].second;
			int y = v[i].first - v[i].second;
			if (x & 1) {
				x++;
				y++;
			}

			x >>= 1;
			y >>= 1;

			v[i] = mp(x, y);
		}
	}

	return 0;
}