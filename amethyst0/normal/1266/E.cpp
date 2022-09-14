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

const int maxn = (int)2e5 + 10;
int a[maxn];
int in[maxn];

map <pii, int> ed;

ll tot = 0;

void add(int x, int c) {
	tot -= min(a[x], in[x]);
	in[x] += c;
	tot += min(a[x], in[x]);
}

int main() {
	int n;

	cin >> n;

	ll sum = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int q;

	cin >> q;

	while (q--) {
		int s, t, u;

		scanf("%d %d %d", &s, &t, &u);

		if (ed.count(mp(s, t))) {
			int to = ed[mp(s, t)];
			ed.erase(mp(s, t));
			add(to, -1);
		}

		if (u != 0) {
			ed[mp(s, t)] = u;
			add(u, 1);
		}

		printf("%lld\n", sum - tot);
	}

	//system("pause");
}