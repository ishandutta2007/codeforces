//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
ll p[maxn];

int main() {
	vector <int> a, b;

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);
		p[x] -= w;
		p[y] += w;
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] < 0) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}

	int pos = 0;

	vector <pair <pii, ll> > w;

	for (int i = 0; i < (int)a.size(); i++) {
		ll x = -p[a[i]];
		int v = a[i];

		while (x > 0) {
			int u = b[pos];
			if (p[u] == 0) {
				pos++;
				continue;
			}
			if (p[u] <= x) {
				w.push_back(mp(mp(v, u), p[u]));
				x -= p[u];
				pos++;
			}
			else {
				w.push_back(mp(mp(v, u), x));
				p[u] -= x;
				x = 0;
			}
		}
	}

	cout << w.size() << '\n';

	for (auto it : w) {
		printf("%d %d %lld\n", it.first.first, it.first.second, it.second);
	}

	//system("pause");
}