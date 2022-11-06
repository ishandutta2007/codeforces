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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, p;
	string s;
	cin >> n >> p >>s;
	for (int i = 0; i + p < n; ++i) {
		if (s[i] == '.')
			s[i] = s[i + p] == '0' ? '1' : '0';
		else if (s[i + p] == '.')
			s[i + p] = s[i] == '1' ? '0' : '1';
		else if (s[i] == s[i + p])
			continue;
		replace(s.begin(), s.end(), '.', '1');
		cout << s;
		return 0;
	}
	cout << "No";
	return 0;
}