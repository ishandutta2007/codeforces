#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long

using namespace std;

const int maxn = (int)3e5 + 10;
vector <pii> ed[maxn];
int w[maxn];

ll ans = 0;

ll go(int v, int pr) {
	ll cur = w[v];

	vector <ll> f;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u == pr) {
			continue;
		}

		ll res = go(u, v) - ed[v][i].second;

		f.push_back(res);

		cur = max(cur, res + w[v]);
	}

	ans = max(ans, cur);

	sort(f.begin(), f.end());

	if ((int)f.size() >= 2) {
		ans = max(ans, f.back() + f[(int)f.size() - 2] + w[v]);
	}

	return cur;
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y, c;

		scanf("%d %d %d", &x, &y, &c);

		ed[x].push_back(mp(y, c));
		ed[y].push_back(mp(x, c));
	}

	go(1, 1);

	cout << ans << endl;
	
	//system("pause");

	return 0;
}