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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	string b;
	cin >> b;
	for(int i = 0; i < b.size(); ++i)
		if (b[i] == '1') {
			int j = i + 1;
			while (j < b.size() && b[j] == '1')
				++j;
			sort(a.begin() + i, a.begin() + j + 1);
			i = j;
		}
	for(int i = 0; i + 1 < n; ++i)
		if (a[i] > a[i + 1]) {
			cout << "NO";
			return 0;
		}

	cout << "YES";
	return 0;
}