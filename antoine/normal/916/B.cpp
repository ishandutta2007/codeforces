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

priority_queue<int> getBits(long long n) {
	priority_queue<int> bits;
	for (int i = 0; n; ++i)
		if (n&(1ll << i)) {
			bits.push(i);
			n ^= (1ll << i);
		}
	return bits;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n; int k;
	cin >> n >> k;
	auto pq = getBits(n);
	if (pq.size() > k) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	while (pq.size() < k) {
		auto x = pq.top();
		pq.pop();
		pq.push(x - 1);
		pq.push(x - 1);
	}

	int m = pq.top();
	pq = getBits(n);
	while (pq.size() < k && pq.top() != m) {
		auto x = pq.top();
		pq.pop();
		pq.push(x - 1);
		pq.push(x - 1);
	}
	multiset<int> ms;
	while (!pq.empty()) {
		ms.insert(pq.top());
		pq.pop();
	}
	while (ms.size() < k) {
		int x = *ms.begin();
		ms.erase(ms.begin());
		ms.insert(x - 1);
		ms.insert(x - 1);
	}
	for(auto it = ms.rbegin(); it != ms.rend(); ++it)
		cout << *it << ' ';
	return 0;
}