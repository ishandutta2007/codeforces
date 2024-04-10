#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = (int)1e5 + 10;
int v[maxn];
int in[maxn];

map <int, int> s;
int a, b;

void dfs(int pos) {
	int x = v[pos];
	
	bool ga = s.count(a - x), gb = s.count(b - x);

	if (ga && gb) {
		s[v[pos]] = pos;
		return;
	}

	if (!ga && !gb) {
		cout << "NO\n";
		exit(0);
	}

	if (ga) {
		in[pos] = 0;
		int to = s[a - x];
		in[to] = 0;
		s.erase(a - x);
		s.erase(x);
		int f = b - (a - x);
		if (s.count(f)) {
			dfs(s[f]);
		}
	}
	else {
		in[pos] = 1;
		int to = s[b - x];
		in[to] = 1;
		s.erase(b - x);
		s.erase(x);
		int f = a - (b - x);
		if (s.count(f)) {
			dfs(s[f]);
		}
	}
}

int main() {
	int n;
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		v[i] = x;
		in[i] = -1;
		s[x] = i;
	}

	for (int i = 0; i < n; i++) {
		if (in[i] != -1) {
			continue;
		}

		dfs(i);
	}

	cout << "YES\n";

	for (int i = 0; i < n; i++) {
		printf("%d ", max(in[i], 0));
	}
}