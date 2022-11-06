#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
string s;
int N;

int dp[2][5020];
int cs[2][5020];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;
		s += c;
	}

	int i = (N - 1);
	cs[i & 1][0] = dp[i & 1][0] = 1;
	for (int j = 1; j < 5020; ++j) {
		dp[i & 1][j] = 1;
		cs[i & 1][j] = cs[i & 1][j - 1] + 1;
	}
	for (i = N - 2; i >= 0; --i) {
		for (int j = 0; j < 5020; ++j) {
			if (s[i] == 's')
				dp[i & 1][j] = cs[(i + 1) & 1][j];
			else if(j < 5019)
				dp[i & 1][j] = dp[(i + 1) & 1][j + 1];
		}
		cs[i & 1][0] = dp[i & 1][0];
		for (int j = 1; j < 5020; ++j)
			cs[i & 1][j] = (cs[i & 1][j - 1] + dp[i & 1][j]) % mod;
	}

	cout << dp[0][0];

	return 0;
}