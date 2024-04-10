#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>

using namespace std;

bool change;
string dp[256][3];

void update(int i, int j, string s, string &dep) {
	if (dep.empty())
		return;
	if (dp[i][j].empty() || s.length() < dp[i][j].length() || (s.length() == dp[i][j].length() && s < dp[i][j])) {
		dp[i][j] = s;
		change = true;
	}
}

void update(int i, int j, string s, string &dep1, string &dep2) {
	if (!dep2.empty())
		update(i, j, s, dep1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1 << 3 | 1 << 2 | 1 << 1 | 1][2] = "x";
	dp[1 << 5 | 1 << 4 | 1 << 1 | 1][2] = "y";
	dp[1 << 6 | 1 << 4 | 1 << 2 | 1][2] = "z";
	
	do {
		change = false;
		for (int i = 0; i < 256; ++i) {
			update(i, 0, dp[i][1], dp[i][1]);
			update(i, 1, dp[i][2], dp[i][2]);
			update((~i) & 255, 2, "!" + dp[i][2], dp[i][2]);
			update(i, 2, "(" + dp[i][0] + ')', dp[i][0]);
			for (int j = 0; j < 256; ++j) {
				update(i | j, 0, dp[i][0] + '|' + dp[j][1], dp[i][0], dp[j][1]);
				update(i & j, 1, dp[i][1] + '&' + dp[j][2], dp[i][1], dp[j][2]);
			}
		}
	} while (change);

	int n;
	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;
		cout << dp[bitset<8>(s).to_ulong()][0] << '\n';
	}
	return 0;
}