#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn], ps[maxn];

bool cmp(int a, int b) {
	return v[a] < v[b];
}

int res[maxn];

const int inf = (int)1e9 + 10;

int main() {
	int n;

	cin >> n;

	int m = n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		ps[i] = i;
	}

	bool fl = true;

	while (m % 3 != 0) {
		/*if (fl) {
			v[m] = 0;
			fl = false;
		}
		else {
			v[m] = (n + 2) / 3;
		}*/
		v[m] = inf + m;
		ps[m] = m;
		m++;
	}

	sort(ps, ps + m, cmp);

	printf("YES\n");

	int cnt = m / 3;

	for (int i = 0; i < cnt; i++) {
		res[ps[i]] = i;
	}

	int x = 1;

	set <int> s;

	for (int i = cnt; i < 2 * cnt; i++) {
		res[ps[i]] = v[ps[i]] - x;
		s.insert(res[ps[i]]);
		x += 2;
	}

	x = 0;

	for (int i = 2 * cnt; i < m; i++) {
		res[ps[i]] = v[ps[i]] - x;
		while (s.count(res[ps[i]])) {
			x += 2;
			res[ps[i]] = v[ps[i]] - x;
		}
		s.insert(res[ps[i]]);
		x += 2;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}

	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i] - res[i]);
	}

	printf("\n");

	//system("pause");
}