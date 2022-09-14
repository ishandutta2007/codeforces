/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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
#define pii pair <ll, ll>
#define mp make_pair

using namespace std;

const double PI = 3.14159265358979323846;
const int maxn = (int)2e5 + 101;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e9;
const double eps = 1e-9;

int n, m, k, x, y;
ll dp[maxn][5], ans[maxn], ans1[maxn];
vector<vector<int> > v(maxn);

void dfs(int ver, int p) {
	ll cnt = 0;
	for (int i = 0; i < v[ver].size(); i++) {
		int to = v[ver][i];
		if (to == p) {
			continue;
		}
		dfs(to, ver);
		cnt++;
		ans[ver] += ans[to];
		ans[ver] += dp[to][0];
		for (int j = 0; j < k; j++) {
			dp[ver][(j + 1) % k] += dp[to][j];
		}
	}
	dp[ver][1 % k] += cnt;
	ans[ver] += cnt;
	return;
}

void dfs1(int ver, int p, vector<int> tmp, ll add) {
	vector<int> tv;
	for (int i  = 0; i < k; i++) {
		tv.push_back(0);
	}
	ans1[ver] += add;
	ans1[ver] += tmp[0];
	if (p != -1) {
		ans1[ver] += 1;
		tv[1 % k]++;
	}
	for (int i = 0; i < tmp.size(); i++) {
		tv[(i + 1) % k] += tmp[i];
	}
	ll cnt = 0;
	for (int i = 0; i < v[ver].size(); i++) {
		int to = v[ver][i];
		if (to == p) {
			continue;
		}
		cnt++;
		for (int j = 0; j < k; j++) {
			tv[(j + 1) % k] += dp[to][j];
		}
	}
	tv[1 % k] += cnt;
	for (int i = 0; i < v[ver].size(); i++) {
		int to = v[ver][i];
		if (to == p) {
			continue;
		}
		for (int j = 0; j < k; j++) {
			tv[(j + 1) % k] -= dp[to][j];
		}
		tv[1 % k]--;
		dfs1(to, ver, tv, ans1[ver] + ans[ver] - ans[to] - 1 - dp[to][0]);		
		for (int j = 0; j < k; j++) {
			tv[(j + 1) % k] += dp[to][j];
		}
		tv[1 % k]++;
	}
	return;
}

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, -1);
	vector<int> tv;
	for (int i = 0; i < k; i++) {
		tv.push_back(0);
	}
	dfs1(1, -1, tv, 0);
	ll an = 0;
	for (int i = 1; i <= n; i++) {
		an += ans[i];
		an += ans1[i];
	}
	cout << an / 2;

    return 0;
}