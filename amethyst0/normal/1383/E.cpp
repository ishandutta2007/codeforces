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
#define mp make_pair

const int maxn = (int)1e6 + 10, mod = (int)1e9 + 7;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

char s[maxn];
int dp[maxn][2];
int sum[maxn];
int cnt[maxn];

int getsum(int l, int r) {
	return sub(sum[l], sum[r + 1]);
}

int main() {
	scanf("%s", s);
	int n = 0;

	while (s[n]) {
		n++;
	}

	int lst[2] = { n, n };

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			cnt[i] = 0;
		}
		else {
			cnt[i] = cnt[i + 1] + 1;
		}
	}

	vector <int> q;

	int numb = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			break;
		}

		numb++;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			dp[i][0] = add(dp[i + 1][0], dp[i + 1][1]);

			if (lst[1] != n) {
				dp[i][1] = dp[lst[1]][1];
			}
			else {
				dp[i][0] = add(dp[i][0], 1);
			}

			if (i < n - numb) {
				while (!q.empty() && cnt[i] > cnt[q.back()]) {
					q.pop_back();
				}

				q.push_back(i);
			}
		}
		else {
			dp[i][1] = 1;
			dp[i][1] = add(dp[i][1], numb);

			dp[i][1] = add(dp[i][1], dp[i + 1][1]);

			int prev = 0;

			for (int j = (int)q.size() - 1; j >= 0; j--) {
				int pos = q[j];

				dp[i][1] = add(dp[i][1], dp[pos + prev][0]);

				prev = cnt[pos];
			}
		}

		lst[s[i] - '0'] = i;
		sum[i] = sum[i + 1] + dp[i][0];
	}

	cout << add(dp[0][0], dp[0][1]) << '\n';
}