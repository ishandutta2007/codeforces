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
#include <iomanip>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

int x[10];

string b[10] = {
	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

const int maxn = 2010;

int dst[10][10];
int v[maxn];

int dp[maxn][maxn];
int n;

int cnt[1 << 7];

int go(int pos, int k) {
	if (k < 0) {
		return 0;
	}

	if (dp[pos][k] != -1) {
		return dp[pos][k];
	}

	if (pos == n) {
		return dp[pos][k] = (k == 0);
	}

	int ans = 0;

	for (int i = 0; i < 10; i++) {
		if ((x[i] & v[pos]) == v[pos]) {
			ans = max(ans, go(pos + 1, k - cnt[x[i] ^ v[pos]]));
		}
	}

	return dp[pos][k] = ans;
}

int main() {
	cnt[0] = 0;

	for (int i = 1; i < (1 << 7); i++) {
		cnt[i] = (i & 1) + cnt[i >> 1];
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 7; j++) {
			if (b[i][j] == '1') {
				x[i] |= (1 << j);
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int a = x[i] ^ x[j];

			for (int k = 0; k < 7; k++) {
				if ((a >> k) & 1) {
					dst[i][j]++;
				}
			}
		}
	}

	int k;

	cin >> n >> k;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < (int)s.size(); j++) {
			if (s[j] == '1') {
				v[i] |= 1 << j;
			}
		}
	}

	memset(dp, -1, sizeof dp);

	bool ok = true;
	string ans = "";

	for (int i = 0; i < n; i++) {
		bool cur = false;
		for (int j = 9; j >= 0; j--) {
			if ((v[i] & x[j]) == v[i] && go(i + 1, k - cnt[v[i] ^ x[j]])) {
				k -= cnt[v[i] ^ x[j]];
				ans.push_back('0' + j);
				cur = true;
				break;
			}
		}

		if (!cur) {
			ok = false;
			break;
		}
	}

	if (!ok) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
}