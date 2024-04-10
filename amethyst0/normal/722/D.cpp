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
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];

int main() {
	int n;

	cin >> n;

	set <int> s;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}

	while (true) {
		int x = *s.rbegin();
		int y = x;

		s.erase(*s.rbegin());

		x /= 2;

		while (x >= 1 && s.count(x)) {
			x /= 2;
		}

		if (x == 0) {
			s.insert(y);
			break;
		}

		s.insert(x);
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		printf("%d ", *it);
	}

	return 0;
}