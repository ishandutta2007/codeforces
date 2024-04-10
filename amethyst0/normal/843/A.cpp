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
#include <map>
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
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
vector <int> g;
int p[maxn];

int getp(int x) {
	return p[x] = (p[x] == x ? x : getp(p[x]));
}

vector <int> res[maxn];
int num[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		p[i] = i;
		scanf("%d", &v[i]);
		g.push_back(v[i]);
	}

	sort(g.begin(), g.end());

	int ans = n;

	for (int i = 0; i < n; i++) {
		v[i] = lower_bound(g.begin(), g.end(), v[i]) - g.begin();

		int x = i;
		int y = v[i];

		x = getp(x);
		y = getp(y);

		if (x != y) {
			ans--;
		}

		p[x] = y;
	}

	cout << ans << endl;

	memset(num, -1, sizeof num);
	int pos = 0;

	for (int i = 0; i < n; i++) {
		int x = getp(i);

		if (num[x] == -1) {
			num[x] = pos++;
		}

		res[num[x]].push_back(i + 1);
	}

	for (int i = 0; i < ans; i++) {
		printf("%d ", (int)res[i].size());

		for (int j = 0; j < (int)res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}

		printf("\n");
	}

	return 0;
}