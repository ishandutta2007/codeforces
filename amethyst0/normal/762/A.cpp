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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	ll n;
	int k;

	cin >> n >> k;

	vector <ll> a, b;

	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			a.push_back(i);

			if (i * i != n) {
				b.push_back(n / i);
			}
		}
	}

	k--;

	if (k < (int)a.size()) {
		cout << a[k] << endl;
		return 0;
	}

	k -= a.size();

	if (k < (int)b.size()) {
		cout << b[(int)b.size() - k - 1] << endl;
		return 0;
	}

	cout << -1 << endl;

	return 0;
}