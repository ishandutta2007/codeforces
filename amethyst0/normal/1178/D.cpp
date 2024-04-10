#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = 1010;

bool prime(int x) {
	if (x == 1) {
		return false;
	}

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

vector <pii> solve(int n) {
	vector <pii> e;

	for (int i = 1; i <= n; i++) {
		int x = i;
		int y = i + 1;
		if (x == n) {
			y = 1;
		}

		e.push_back(mp(x, y));
	}

	int m = n;

	int p = 1;
	int np = n / 2 + 1;

	if (n % 2 == 1) {
		np++;
	}

	vector <pii> g;

	while (!prime(m)) {
		if (np == n + 1) {
			return g;
		}

		m++;
		e.push_back(mp(p, np));
		p++;
		np++;
	}

	return e;
}

int main() {
	int n;

	cin >> n;

	vector <pii> e = solve(n);

	cout << e.size() << endl;

	for (int i = 0; i < (int)e.size(); i++) {
		cout << e[i].first << ' ' << e[i].second << endl;
	}

	//system("pause");
}