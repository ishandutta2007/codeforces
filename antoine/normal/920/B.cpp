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

struct Student {
	int i, l, r;

	bool operator<(const Student &other) const {
		if (l != other.l)
			return l > other.l;
		return i > other.i;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<int> ans(n, 0);
		vector<Student> students(n);
		for (int i = 0; i < n; ++i) {
			students[i].i = i;
			cin >> students[i].l >> students[i].r;
		}
		sort(students.begin(), students.end());
		for (int sec = 0; !students.empty(); ++sec) {
			if (students.back().r < sec) {
				students.pop_back();
				--sec;
			}
			else {
				sec = max(sec, students.back().l);
				ans[students.back().i] = sec;
				students.pop_back();
			}
		}
		for (int i = 0; i < n; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}