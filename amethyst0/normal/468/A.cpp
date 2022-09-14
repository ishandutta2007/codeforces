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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	int n;
	cin >> n;

	if (n < 4) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	while (n > 5) {
		cout << n << " - " << n - 1 << " = " << 1 << '\n';
		cout << n - 2 << " * " << 1 << " = " << n - 2 << '\n';
		n -= 2;
	}

	if (n == 4) {
		cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
	}
	else {
		cout << "5 - 1 = 4\n4 - 2 = 2\n4 * 2 = 8\n8 * 3 = 24\n";
	}
}