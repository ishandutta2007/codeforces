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
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)4e5 + 10;
int v[maxn];

map <int, int> w;

void add(int x) {
	if (!w.count(x)) {
		w[x] = 1;
	}
	else {
		w[x]++;
	}
}

void del(int x) {
	w[x]--;

	if (w[x] == 0) {
		w.erase(x);
	}
}

int main() {
	int n, c;

	cin >> n >> c;

	c *= 8;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	int d = (c / n);

	int r = 0;

	int k = 1;

	for (int i = 0; i < d; i++) {
		k *= 2;

		if (k > n) {
			break;
		}
	}

	int ans = 0;

	for (int l = 0; l < n; l++) {
		r = max(r, l);

		while (r < n && (int)w.size() <= k) {
			add(v[r]);
			r++;

			if ((int)w.size() > k) {
				r--;
				del(v[r]);
				break;
			}
		}

		del(v[l]);

		ans = max(ans, r - l);
	}

	cout << n - ans << endl;

	//system("pause");
}