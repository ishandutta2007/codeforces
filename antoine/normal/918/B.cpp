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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	map<string, string> mp;
	while (n-- > 0) {
		string a, b;
		cin >> a >> b;
		mp[b] = a;
	}
	while (m-- > 0) {
		string a, b;
		cin >> a >> b;
		cout << a << ' ' << b;
		b = b.substr(0, b.size() - 1);
		cout << " #" << mp[b] << '\n';
	}
	return 0;
}