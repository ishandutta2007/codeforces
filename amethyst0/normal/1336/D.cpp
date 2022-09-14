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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = 110;

int cur[maxn];
int ans[maxn];

pii operator -(pii a, pii b) {
	a.first -= b.first;
	a.second -= b.second;
	return a;
}

pii add(int x) {
	cout << "+ " << x << endl;
	pii ans;
	cin >> ans.first >> ans.second;
	return ans;
}

pii lst;

int getval(int val) {
	int x = 1;

	while (x * (x - 1) / 2 < val) {
		x++;
	}

	return x;
}

pii a[maxn];

int main() {
	int n;

	cin >> n;

	cin >> a[n].first >> a[n].second;

	for (int i = n - 1; i >= 3; i--) {
		a[i] = add(i);
	}

	pii x = add(1);
	a[1] = x;
	a[2] = add(2);
	pii y = add(1);

	ans[1] = getval(y.first - a[2].first) - 1;
	ans[3] = (y.second - a[2].second) - (x.second - a[3].second) - 1;
	ans[2] = (y.second - a[2].second) / (ans[3] + 1) - 1;

	for (int i = 2; i <= n - 2; i++) {
		pii x = (i != 2 ? a[i] - a[i + 1] : a[i] - a[i - 1]);
		x.second -= ans[i - 2] * ans[i - 1];
		if (i != 2) {
			x.second -= ans[i - 1] * (ans[i + 1] + 1);
		}
		else {
			x.second -= (ans[i - 1] + 1) * (ans[i + 1] + 1);
		}
		x.second /= ans[i + 1] + 1;
		if (i != n - 2) {
			ans[i + 2] = x.second - 1;
		}
		else {
			ans[i + 2] = x.second;
		}
	}

	cout << "! ";

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;
}