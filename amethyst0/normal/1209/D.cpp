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
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
bool used[maxn];

int dfs(int v) {
	int ans = 1;
	used[v] = true;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (!used[u]) {
			ans += dfs(u);
		}
	}

	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			ans += dfs(i) - 1;
		}
	}

	cout << k - ans << endl;

	//system("pause");
}