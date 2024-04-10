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

const int maxn = (int)2e5 + 10;

int dp[maxn][2];
vector <int> ed[maxn];

void del(int v, int p) {
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u == p) {
			swap(ed[v][i], ed[v].back());
			ed[v].pop_back();
			i--;
			continue;
		}
		else {
			del(u, v);
		}
	}
}

int st[maxn];

int go(int v, int x) {
	if (dp[v][x] != -1) {
		return dp[v][x];
	}

	int a = 0, b = 0, c = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (go(u, 0) && go(u, 1)) {
			b++;
		}
		else if (go(u, 0) && !go(u, 1)) {
			a++;
		}
		else if (!go(u, 0) && go(u, 1)) {
			c++;
		}
		else {
			return dp[v][x] = 0;
		}
	}

	int cnt = st[v] - x;

	cnt -= a;

	if (b == 0 && (cnt & 1)) {
		return dp[v][x] = 0;
	}

	return dp[v][x] = 1;
}

void write(int v, int x) {
	vector <int> a, b, c;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (go(u, 0) && go(u, 1)) {
			b.push_back(u);
		}
		else if (go(u, 0) && !go(u, 1)) {
			a.push_back(u);
		}
		else if (!go(u, 0) && go(u, 1)) {
			c.push_back(u);
		}
		else {
			throw 1;
		}
	}

	for (int i = 0; i < (int)a.size(); i++) {
		write(a[i], 0);
	}

	int cnt = st[v] - x;

	cnt -= (int)a.size();

	if (cnt & 1) {
		if (b.empty()) {
			throw 1;
		}

		write(b.back(), 0);
		b.pop_back();
	}

	printf("%d\n", v);

	for (int i = 0; i < (int)c.size(); i++) {
		write(c[i], 1);
	}

	for (int i = 0; i < (int)b.size(); i++) {
		write(b[i], 1);
	}
}

int main() {
	memset(dp, -1, sizeof dp);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);

		if (x != 0) {
			ed[x].push_back(i);
			ed[i].push_back(x);
			st[i]++;
			st[x]++;
		}
	}

	del(1, -1);

	if (go(1, 0) == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		write(1, 0);
	}

	//system("pause");
}