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
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 510;
int v[maxn];
int n;

bool check(int ans) {
	for (int i = 0; i < n; i++) {
		if (v[i] % ans > v[i] / ans) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		//v[i] = (int)1e9 - i;
	}

	sort(v, v + n);

	int ans = 1;

	while (ans * ans <= v[0]) {
		ans++;
	}

	if (abs(v[n - 1] - v[0]) <= 1) {
		cout << n << endl;
		return 0;
	}

	ans--;

	int l = v[0] - ans;
	int r = v[0];

	int tmp = ans;

	for (int i = 1; i <= tmp; i++) {
		for (int j = r / i; j * i >= l; j--) {
			if (j <= ans) {
				break;
			}

			if (check(j)) {
				ans = j;
			}
		}
	}

	ll res = 0;

	for (int i = 0; i < n; i++) {
		ll now = v[i] / (ans + 1);
		ll d = v[i] % (ans + 1);

		if (d != 0) {
			now++;
		}

		res += now;
	}

	cout << res << endl;

	return 0;
}