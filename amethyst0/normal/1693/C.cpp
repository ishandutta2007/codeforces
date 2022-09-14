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
#include <limits.h>
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
const int inf = (int)1e9;
vector<int> ed[maxn];
vector<int> red[maxn];
int dst[maxn];
bool used[maxn];
int cnt[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		red[y].push_back(x);
	}
	
	dst[n - 1] = 0;
	for (int i = 0; i < n - 1; i++) {
		dst[i] = inf;
	}
	
	set<pair<int, int>> s;
	
	for (int i = 0; i < n; i++) {
		s.insert({dst[i], i});
	}
	
	used[n - 1] = true;
	
	while (!s.empty()) {
		int v = s.begin()->second;
		used[v] = true;
		s.erase(s.begin());
		if (v != n - 1) {
			dst[v]++;
		}
		for (int u : red[v]) {
			if (used[u]) {
				continue;
			}
			s.erase(mp(dst[u], u));
			dst[u] = min(dst[u], dst[v] + (int)ed[u].size() - 1 - cnt[u]);
			cnt[u]++;
			s.insert(mp(dst[u], u));
		}
	}
	
	cout << dst[0] << '\n';
}