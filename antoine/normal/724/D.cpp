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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

string s;
int m;

// bool : feasible ? | int: number of times we used c
pair<bool, int> feasible(char c) {
	int lastC = -1;
	int lastPicked = -1;
	int cUsed = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] < c) {
			lastPicked = i;
		}
		else if (s[i] == c)
			lastC = i;
		if (i - lastPicked >= m) {
			if (lastC > i - m) {
				lastPicked = lastC;
				++cUsed;
			}
			else
				return { false, 0 };
		}
	}
	return { true, cUsed };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> s;

	char lo = 'a';
	char hi = 'z';
	while (lo < hi) {
		char mid = (lo + hi) / 2;
		if (!feasible(mid).first)
			lo = mid + 1;
		else
			hi = mid;
	}

	const int cnt = feasible(lo).second;
	sort(s.begin(), s.end());
	cout << s.substr(0, s.find_first_of(lo)) << string(cnt, lo);
	return 0;
}