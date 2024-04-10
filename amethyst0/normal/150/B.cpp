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
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

const int mod = (int)1e9 + 7;

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return a * my_pow(a, b - 1) % mod;
	}

	ll t = my_pow(a, b >> 1);

	return t * t % mod;
}

const int maxn = 2010;
vector <int> ed[maxn];
bool used[maxn];

void dfs(int v) {
	used[v] = true;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (!used[u]) {
			dfs(u);
		}
	}
}

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j < k; j++) {
			ed[i + j].push_back(i + (k - j - 1));
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << my_pow(m, cnt) << endl;

	return 0;
}