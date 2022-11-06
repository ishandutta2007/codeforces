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

using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	vector<int> v = { 0 };
	for (char &c : s)
		if (c == '.')
			++v.back();
		else
			v.push_back(0);
	int ans = 0;
	for (auto &&x : v) {
		while (x >= 2 && a && b) {
			x -= 2;
			--a;
			--b;
			ans += 2;
		}
	}
	a += b;
	for (auto &&x : v) {
		if (x) {
			int temp = min((x + 1) >> 1, a);
			ans += temp;
			a -= temp;
		}
	}
	cout << ans;
	return 0;
}