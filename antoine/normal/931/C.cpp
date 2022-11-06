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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	map<int, int> occ;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++occ[a];
	}

	if (occ.begin()->first + 2 == occ.rbegin()->first)
		occ[occ.begin()->first + 1];
	
	vector<int> v;

	for (auto &&x : occ)
		v.push_back(x.second);


	int ans = n;
	if (v.size() == 3)
		if (v[1] / 2 > min(v[0], v[2]))
			for (; v[1] >> 1; ans -= 2) {
				v[1] -= 2;
				v[0]++;
				v[2]++;
			}
		else
			for (; min(v[0], v[2]); ans -= 2) {
				v[1] += 2;
				v[0]--;
				v[2]--;

			}

	cout << ans << '\n';
	for (int j = 0; j < v.size(); ++j)
		while (v[j]--)
			cout << (occ.begin()->first) + j << ' ';

	return 0;
}