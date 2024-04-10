#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ans = 0;
		if (n <= 2) ans = 0;
		else if ((int) count(s.begin(), s.end(), 'L') == n || (int) count(s.begin(), s.end(), 'R') == n) {
			ans = (n + 2) / 3;
		} else {

			int head = 0;
			for (; s[head] == s.back(); ++head);
			rotate(s.begin(), s.begin() + head, s.end());
			assert(s.front() != s.back());
			s += "-";
			for (int i = 0, j; i < n; i = j) {
				for (j = i; s[i] == s[j]; ++j);
				ans += (j - i) / 3;
			}
		}
		cout << ans << '\n';
	}
}