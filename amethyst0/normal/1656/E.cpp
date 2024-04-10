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

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
int res[maxn];

void go(int v, int p, int h) {
	res[v] = (int)ed[v].size() * h;
	
	for (int u : ed[v]) {
		if (u != p) {
			go(u, v, h * -1);
		}
	}
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
		
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			ed[x].push_back(y);
			ed[y].push_back(x);
		}
		
		go(0, -1, 1);
		
		for (int i = 0; i < n; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
}