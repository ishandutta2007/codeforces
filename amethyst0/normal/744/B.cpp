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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1010;
int n;
int ans[maxn];
int v[maxn][maxn];

vector <int> go(vector <int> a) {
	vector <int> f;
	for (int i = 1; i <= n; i++) {
		int x = (int)1e9 + 10;

		for (int j = 0; j < (int)a.size(); j++) {
			x = min(x, v[i][a[j]]);
		}

		f.push_back(x);
	}

	return f;
}

void make(vector <int> &a) {
	printf("%d\n", a.size());
	for (int j = 0; j < (int)a.size(); j++) {
		printf("%d ", a[j]);
	}

	printf("\n");
	fflush(stdout);

	//vector <int> f = go(a);

	int l = 0;

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);

		//x = f[i - 1];

		while (l != (int)a.size() && a[l] < i) {
			l++;
		}

		if (l == (int)a.size() || i != a[l]) {
			ans[i] = min(ans[i], x);
		}
	}
}
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ans[i] = (int)1e9 + 10;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//scanf("%d", &v[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) {
		if ((1 << i) > n) {
			break;
		}

		vector <int> a, b;
		for (int j = 1; j <= n; j++) {
			if ((j & (1 << i)) != 0) {
				a.push_back(j);
			} else {
				b.push_back(j);
			}
		}

		make(a);
		make(b);
	}

	printf("-1\n");

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	printf("\n");
	fflush(stdout);

	return 0;
}