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
const int maxn = (int)2e5 + 11;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e9;
const double eps = 1e-9;

int n, m, x, y;
ll sz, cnt;
int color[maxn];
vector<vector<int> > v(maxn);

void dfs(int ver) {
	sz++;
	cnt += v[ver].size();
	color[ver] = 1;
	for (int i = 0; i < v[ver].size(); i++) {
		int to = v[ver][i];
		if (!color[to]) {
			dfs(to);
		}
	}
	return;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			sz = 0;
			cnt = 0;
			dfs(i);
			cnt /= 2;
			if (cnt != sz * (sz - 1) / 2) {
				printf("NO");
				return 0;
			}
		}

	}
	printf("YES");
    return 0;
}