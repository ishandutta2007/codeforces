#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <deque>

using namespace std;

int a[300000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, m;
	cin >> n >> m >> k;
	deque<int> all;
	int ans = 0;
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	std::sort(a, a + n);

	for(int i = 0; i < n; ++i) {
		all.push_back(a[i]);
		while (all.size() > 0 && all.front() <= a[i] - m)
			all.pop_front();
		while (all.size() >= k) {
			all.pop_back();
			++ans;
		}
	}
	std::cout << ans << '\n';
	return 0;
}