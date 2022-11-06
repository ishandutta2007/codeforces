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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	char curr = 'a';
	for (int i = 0; i < s.size() && curr <= 'z'; ++i) {
		if (s[i] > curr) continue;
		s[i] = curr++;
	}
	cout << (curr <= 'z' ? "-1" : s);
	return 0;
}