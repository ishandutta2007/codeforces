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
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;
char s[maxn];
int dp[maxn];

int main() {
	scanf("%s", s);

	int n = strlen(s);
	dp[n - 1] = 1;

	int ans = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) {
			dp[i] = dp[i + 1] + 1;
		}
		else {
			dp[i] = 1;
		}

		ans = max(ans, dp[i]);
	}

	if (s[0] != s[n - 1]) {
		for (int i = n - 1; i >= 0; i--) {
			if (dp[i] + i == n) {
				ans = max(ans, dp[0] + dp[i]);
			}
		}
	}

	if (ans >= n) {
		ans = n;
	}

	cout << ans << endl;

	//system("pause");
}