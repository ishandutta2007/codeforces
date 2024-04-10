#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

mt19937 rr(18973491204867 + 12986481764 + 1298461824 + 89163478239 + 191 + 1289419498134 + 12489712984798124 + 18967417864);

int go(int pos) {
	cout << "? " << pos + 1 << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	int n;
	cin >> n;

	int l = 0;
	int r = n - 1;

	while (l != r) {
		int m = (l + r) >> 1;
		int x = go(m);
		int y = go(m + 1);
		if (x > y) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	cout << "! " << l + 1 << endl;
}