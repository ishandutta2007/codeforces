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

using namespace std;
typedef long long ll;


int f(ll a, int d) {
	int res = 0;
	while (a%d == 0) {
		a /= d;
		++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >>n>> s;
	map<string, int> mp;
	for (int i = 0; i + 1 < n; ++i)
		++mp[s.substr(i, 2)];
	int res = -1;
	string ans = "";
	for(auto &&x: mp)
		if (x.second > res) {
			res = x.second;
			ans = x.first;
		}
	cout << ans;
	return 0;
}