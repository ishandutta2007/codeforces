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
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = 5010;
int v[maxn];

int cnt(int l, int r) {
	if (l > r) {
		return 0;
	}

	return (r - l + 1) / 2;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}

	ll cur = 0;

	for (int i = 1; i <= n; i++) {
		cur += cnt(1, i - 1);
	}

	if (cur < m) {
		cout << -1 << '\n';
		return 0;
	}

	int inf = (int)1e9;

	for (int i = n; i > 0; i--) {
		int num = cnt(1, i - 1);

		if (cur - num >= m) {
			cur -= num;
			v[i] = inf;
			inf -= 5 * n;
			continue;
		}

		while (cur != m) {
			cur -= num;
			v[i]++;
			num = cnt(v[i] - (i - 1), i - 1);
			cur += num;
		}

		break;
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] << ' ';
	}

	cout << '\n';
}