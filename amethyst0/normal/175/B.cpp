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

vector <pair <int, string> > v;

void write(int l, int r, string ans) {
	for (int i = l; i < r; i++) {
		cout << v[i].second << ' ' << ans << endl;
	}
}

int main() {
	int n;

	cin >> n;

	map <string, int> m;

	for (int i = 0; i < n; i++) {
		string a;
		int x;

		cin >> a >> x;

		m[a] = max(m[a], x);
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back(mp(it->second, it->first));
	}

	sort(v.begin(), v.end());

	printf("%d\n", (int)m.size());

	for (int i = 0; i < (int)v.size(); ) {
		int r = i;

		while (r < (int)v.size() && v[i].first == v[r].first) {
			r++;
		}

		int a = i;
		int b = r - i;
		int c = (int)v.size() - r;

		if (2 * c > (int)v.size()) {
			write(i, r, "noob");
		} else if (2 * c <= (int)v.size() && 5 * c > (int)v.size()) {
			write(i, r, "random");
		} else if (5 * c <= 4 * (int)v.size() && 10 * c > (int)v.size()) {
			write(i, r, "average");
		} else if (10 * c <= (int)v.size() * 9 && 100 * c > (int)v.size()) {
			write(i, r, "hardcore");
		} else {
			write(i, r, "pro");
		}

		i = r;
	}

	return 0;
}