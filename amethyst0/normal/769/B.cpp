/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 110;
int a[maxn];
bool used[maxn];
int n;

vector <pii> ed;

void dfs(int v) {
	used[v] = true;

	while (a[v] > 0) {
		int u = -1;

		for (int i = 1; i <= n; i++) {
			if (!used[i] && (u == -1 || (a[u] < a[i]))) {
				u = i;
			}
		}

		if (u == -1) {
			break;
		}

		ed.push_back(mp(v, u));
		a[v]--;
		dfs(u);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << ed.size() << endl;

	for (int i = 0; i < (int)ed.size(); i++) {
		printf("%d %d\n", ed[i].first, ed[i].second);
	}

	return 0;
}