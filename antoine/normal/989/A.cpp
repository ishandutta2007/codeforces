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

	string s;
	cin >> s;
	for(int i = 0; i + 2 < s.size(); ++i)
		if (set<char>(s.begin() + i, s.begin() + i + 3) == set<char>{'A', 'B', 'C'}) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}