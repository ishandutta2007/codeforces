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
int l[maxn], r[maxn];

vector<int> ed[maxn];

int ans = 0;

ll dfs(int v) {
	ll s = 0;
	for (int u : ed[v]) {
		s += dfs(u);
	}
	
	if (s < l[v]) {
		ans++;
		s = r[v];
	} else if (s <= r[v]) {
		
	} else {
		s = r[v];
	}
	
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			ed[i].clear();
		}
		
		for (int i = 1; i < n; i++) {
			int x;
			scanf("%d", &x);
			x--;
			ed[x].push_back(i);
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &l[i], &r[i]);
		}
		
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
}