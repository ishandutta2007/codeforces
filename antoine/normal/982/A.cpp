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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

bool f() {
	int n;
	string s;
	cin >> n >> s;
	if (n == 1)
		return s == "1";
	if (n == 2)
		return s == "10" || s == "01";
	if (s[0] == '0' && s[1] == '0')
		return false;
	if (s[n - 1] == '0' && s[n - 2] == '0')
		return false;
	int prev = -1;
	for(int i = 0; i < s.size(); ++i)
		if (s[i] == '1') {
			if (prev != -1) {
				int diff = i - prev;
				if (diff != 2 && diff != 3)
					return false;
			}
			prev = i;
		}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << (f() ? "Yes" : "No");

	return 0;
}