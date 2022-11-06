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

bool f(array<int, 2> p1, array<int, 2> p2) {
	//cout << "[" << p1[1] << ' ' << p2[1] << "]\n";
	if (p1[0] > p2[0] || ((p1[0] ^ p2[0]) & 1) || p1[1] < p2[1])
		return false;
	if (p1[0] == p2[0])
		return (p1[1] - p2[1]) % 3 == 0;
	if (!p1[0]) { // p2[0]
		return f({ 2, p1[1] - 1 }, p2) || (p1[1] >= 2 && f({ 2, p1[1] - 2 }, p2)) || (p1[1] >= 3 && f({ 2, p1[1] - 3 }, p2));
	}
	return true;
}

struct DS {
	string s;
	vector<int> cs, last;
	DS() {
		cin >> s;
		cs.resize(s.size());
		last.resize(s.size());
		for (int i = 0; i < s.size(); ++i) {
			cs[i] = (i ? cs[i - 1] : 0) + (s[i] != 'A');
			last[i] = s[i] != 'A' ? i : i ? last[i - 1] : -1;
		}
	}
	array<int, 2> query(int i, int j) {
		if (last[j] < i)
			return{ 0, j - i + 1 };
		return{ cs[last[j]] - (i ? cs[i - 1] : 0), j - last[j] };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	DS ds1;
	DS ds2;

	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b; --c; --d;
		cout << f(ds1.query(a, b), ds2.query(c, d));
	}
	return 0;
}