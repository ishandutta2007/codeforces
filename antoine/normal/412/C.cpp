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

	int n; std::cin >> n;
	std::vector<string> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	string res = v[0];
	for (int j = 0; j < v[0].size(); ++j) {
		set<char> s;
		for (int i = 0; i < n; ++i)
			if (v[i][j] != '?')
				s.insert(v[i][j]);
		if (s.size() == 0)
			res[j] = 'a';
		else if (s.size() == 1)
			res[j] = *s.begin();
		else
			res[j] = '?';
	}
	cout << res << endl;
	return 0;
}