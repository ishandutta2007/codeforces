/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e6 + 2;
int d[2 * maxn + 10];

int main() {
	int n, k;

	cin >> n >> k;

	vector <int> a;

	for (int i = 0; i < k; i++) {
		int x;

		scanf("%d", &x);

		if (x == n) {
			cout << 1 << endl;
			return 0;
		}

		a.push_back(x);
	}

	sort(a.begin(), a.end());

	a.resize(unique(a.begin(), a.end()) - a.begin());

	queue <int> q;

	for (int i = 0; i < (int)a.size(); i++) {
		a[i] -= n;
	}

	memset(d, -1, sizeof d);

	q.push(5000);

	d[5000] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < (int)a.size(); i++) {
			int x = v + a[i];

			if (x < 0 || x > 10000) {
				continue;
			}

			if (x == 5000) {
				cout << d[v] + 1 << endl;
				return 0;
			}

			if (d[x] == -1) {
				d[x] = d[v] + 1;
				q.push(x);
			}
		}
	}

	cout << -1 << endl;

	return 0;
}