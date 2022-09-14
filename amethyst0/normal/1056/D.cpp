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
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
vector <int> g;

int go(int v) {
	int cnt = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		cnt += go(u);
	}

	if (cnt == 0) {
		cnt++;
	}

	g.push_back(cnt);
	return cnt;
}

int main() {
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;

		scanf("%d", &p);

		ed[p].push_back(i);
	}

	go(1);

	sort(g.begin(), g.end());

	for (int k = 1; k <= n; k++) {
		printf("%d ", g[k - 1]);
	}

	//system("pause");
}