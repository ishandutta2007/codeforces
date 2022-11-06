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

using namespace std;

vector<long long> getAll(const vector<long long> &p) {
	vector<long long> res = { 1 };
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (auto &&x : p)
		pq.push(x);
	while (!pq.empty()) {
		long long x = pq.top();
		pq.pop();
		if (!res.empty() && res.back() == x)
			continue;
		res.push_back(x);
		for (auto &&y : p)
			if ((double)x * y <= 1e18 + 1e6 && x*y <= (long long)1e18)
				pq.push(x*y);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	long long k;
	cin >> k;

	vector<long long> p1, p2;
	for (int i = 0; i < p.size(); ++i)
		if (i & 1)
			p2.push_back(p[i]);
		else
			p1.push_back(p[i]);

	vector<long long> a1 = getAll(p1),
		a2 = getAll(p2);
	
	long long lo = 0, hi = 1e18;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		long long count = 0;
		for (int i = 0, j = a2.size(); i < a1.size(); ++i) {
			while (j && ((double)a1[i] * a2[j - 1] > mid + 1e6 || a1[i] * a2[j - 1] > mid))
				--j;
			count += j;
		}
		if (count >= k)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo;
	return 0;
}