#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}
	for(auto &&x : mp)
		if (x.second & 1) {
			cout << "Conan";
			return 0;
		}
	cout << "Agasa";
	return 0;
}