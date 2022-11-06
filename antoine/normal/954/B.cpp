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
#include <stack>
#include <memory>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for (int i = s.size(); i; --i) {
		string t = s.substr(0, i) + s.substr(0, i);
		if (s.substr(0, t.size()) == t) {
			cout << t.size() / 2 + 1 + s.size() - t.size();
			return 0;
		}
	}
	cout << s.size();
	return 0;
}