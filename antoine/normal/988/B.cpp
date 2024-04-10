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

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), [](const string &s, const string &t) {
		return s.size() < t.size();
	});
	for(int i = 0; i + 1 < n; ++i)
		if (v[i + 1].find(v[i]) == -1) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for (string s : v)
		cout << s << '\n';
	return 0;
}