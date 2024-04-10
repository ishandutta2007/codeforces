#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int f[maxn];

int ans[48] = { 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401 };

int main() {
	//freopen("output.txt", "w", stdout);
	int maxx = (1 << 25);

	vector <pii> g;

	int ps = 0;

	for (int i = 2; i < maxx; i <<= 1) {
		/*int ans = 0;
		for (int j = 1; j < i; j++) {
			ans = max(ans, gcd(i & j, i ^ j));
		}

		cout << ans << ", ";*/
		g.push_back(mp(i, ans[ps++]));
	}

	for (int i = 4; i <= maxx; i <<= 1) {
		i--;
		/*int ans = 0;
		for (int j = 1; j < i; j++) {
			ans = max(ans, gcd(i & j, i ^ j));
		}

		cout << ans << ", ";*/
		g.push_back(mp(i, ans[ps++]));
		i++;
	}

	sort(g.begin(), g.end());

	int q;

	cin >> q;

	while (q--) {
		int x;

		scanf("%d", &x);

		int p = lower_bound(g.begin(), g.end(), mp(x + 1, -1)) - g.begin() - 1;
		cout << g[p].second << "\n";
	}

	//system("pause");

	return 0;
}