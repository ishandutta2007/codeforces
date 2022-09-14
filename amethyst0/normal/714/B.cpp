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
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

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

	if (s.size() < 3) {
		printf("YES\n");
		return 0;
	}


	int r = max_element(v, v + n) - v;
	int l = min_element(v, v + n) - v;

	r = v[r];
	l = v[l];

	if ((r - l) & 1) {
		cout << "NO" << endl;
		return 0;
	}

	int x = (r - l) / 2;

	for (int i = 0; i < n; i++) {
		if (v[i] != l && v[i] != r && v[i] != r - x) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}