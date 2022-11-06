#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

string s;
char dp[5002][5002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	memset(dp, 0, sizeof dp);

	int ans = 0;

	for (int i = 0; i < s.size(); ++i) {
		int open = 0;
		int closed = 0;
		for (int j = i; j < s.size(); ++j) {
			if (s[j] == '(')
				++open;
			else {
				if (open == closed && closed) {
					++open;
					--closed;
				}

				if (s[j] == ')') {
					if(open-- == closed)
						break;
				}
				else { // '?'
					open == closed ? ++open: ++closed;
				}
			}
			ans += open == closed;
		}
		//cout << ans << ' ';
	}

	cout << ans;

	return 0;
}