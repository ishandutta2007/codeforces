#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;
int v[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int l = 0;
	int r = m - 1;

	while (l != r) {
		int d = (l + r) >> 1;

		int cur = 0;
		bool fl = true;

		for (int i = 0; i < n; i++) {
			int x = v[i];
			
			if (x + d < m) {
				if (x + d < cur) {
					fl = false;
					break;
				}
				else {
					cur = max(x, cur);
				}
			}
			else {
				int y = (x + d) % m;

				if (y >= cur) {

				}
				else {
					cur = max(cur, x);
				}
			}
		}

		if (fl) {
			r = d;
		}
		else {
			l = d + 1;
		}
	}

	cout << l << endl;

	//system("pause");
}