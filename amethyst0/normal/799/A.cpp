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

int main() {
	int n, t, k, d;

	cin >> n >> t >> k >> d;

	int ans = 0;

	int z = n;

	while (z > 0) {
		ans += t;
		z -= k;
	}

	int res = ans - 1;

	if (res / t * k + max(res - d, 0) / t * k >= n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}