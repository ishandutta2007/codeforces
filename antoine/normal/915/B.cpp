#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int f() {
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	if (l == 1 && r == n)
		return 0;
	if (l == 1)
		return abs(pos - r) + 1;
	if (r == n)
		return abs(pos - l) + 1;
	return 2 + min(abs(pos - l), abs(pos - r)) + r - l;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << f();
	return 0;
}