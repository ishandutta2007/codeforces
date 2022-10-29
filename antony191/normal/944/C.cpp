#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <queue>


using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	p[0] = -1;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}
	vector<int> d(n, 0);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			d[to] = d[v] + 1;
			q.push(to);
		}
	}
	sort(d.begin(), d.end());
	int k = d[n - 1];
	int sum = 0;
	vector<int> s(k + 1, 0);
	for (int i = 0; i < n; ++i) {
		s[d[i]]++;
	}
	for (int i = 0; i <= k; ++i)
		if (s[i] & 1)
			++sum;
	cout << sum;
	return 0;
}