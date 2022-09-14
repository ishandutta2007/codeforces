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
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

bitset <maxn> g;

bool getp(int x) {
	if (x == 1) {
		return false;
	}

	int cnt = 0;

	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
	}

	if (x != 1) {
		cnt++;
	}

	return cnt <= 2;
}

bitset <maxn> b[210];

int dp[maxn];

int main() {
	for (int i = 1; i < maxn; i++) {
		g[i] = getp(i);
	}

	int n, f;

	cin >> n >> f;

	g[f] = 0;

	for (int i = 0; i < maxn; i++) {
		int cur = 0;

		while (b[cur][i]) {
			cur++;
		}

		dp[i] = cur;

		b[cur] |= (g << i);
	}

	int res = 0;

	for (int i = 0; i < n; i++) {
		int x, y, z;

		scanf("%d %d %d", &x, &y, &z);

		res ^= dp[y - x - 1] ^ dp[z - y - 1];
	}

	if (res) {
		cout << "Alice\nBob\n";
	}
	else {
		cout << "Bob\nAlice\n";
	}

	//system("pause");
}