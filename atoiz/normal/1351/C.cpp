#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		set<tuple<int, int, int>> paths;
		int x = 0, y = 0, ans = 0;
		for (auto c : str) {
			tuple<int, int, int> cur;
			if (c == 'N') cur = make_tuple(x, y++, 0);
			else if (c == 'S') cur = make_tuple(x, --y, 0);
			else if (c == 'W') cur = make_tuple(--x, y, 1);
			else cur = make_tuple(x++, y, 1);
			ans += (paths.find(cur) == paths.end() ? 5 : 1);
			paths.insert(cur);
		}
		cout << ans << endl;
	}
}