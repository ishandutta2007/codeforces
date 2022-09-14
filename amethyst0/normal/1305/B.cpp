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

int main() {
	string s;

	cin >> s;

	int a = 0;

	int b = 0;

	for (char c : s) {
		if (c == ')') {
			b++;
		}
	}

	int pos = 0;

	while (a < b) {
		if (s[pos] == '(') {
			a++;
		}
		else {
			b--;
		}

		pos++;
	}

	if (a == 0) {
		cout << 0 << '\n';
		return 0;
	}

	cout << 1 << '\n';

	cout << a + b << '\n';

	for (int i = 0; i < pos; i++) {
		if (s[i] == '(') {
			cout << i + 1 << ' ';
		}
	}

	for (int i = pos; i < (int)s.size(); i++) {
		if (s[i] == ')') {
			cout << i + 1 << ' ';
		}
	}

	cout << '\n';
}