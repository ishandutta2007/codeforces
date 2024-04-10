#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>

using namespace std;

int n, k;

vector<int> f(deque<int> a) {
	stack<int> s;
	vector<int> ans;
	int b_end = 0;
	while (b_end != n) {
		if (s.size() > n || a.size() > n || b_end > n || ans.size() > n-k) {
			//cout << "failllll " << ' ' << (s.size() > n) << (a.size() > n) << (b_end > n) << (ans.size() > k);
			return{};
		}
		if (!s.empty() && s.top() == b_end + 1) {
			++b_end;
			s.pop();
			continue;
		}
		if (!a.empty()) {
			s.push(a.front());
			a.pop_front();
			continue;
		}
		if (s.empty()) {
			a.push_back(n);
			ans.push_back(n);
		}
		else {
			a.push_front(s.top() - 1);
			ans.push_back(s.top() - 1);
		}
	}
	if (b_end != n)
		return{};
	return ans;
}

void output(const vector<int> ans, const deque<int> &acpy) {
	if (ans.size() != n - k) {
		cout << "-1";
		return;
	}
	set<int> all;
	for (auto &&x : acpy)
		all.insert(x);
	for (auto &&x : ans)
		all.insert(x);
	if (all.size() != n || *(all.begin()) != 1 || *(all.rbegin()) != n) {
		cout << "-1";
		return;
	}
	vector<int> perm(acpy.begin(), acpy.end());
	perm.insert(perm.end(), ans.begin(), ans.end());
	cout << perm[0];
	for (int i = 1; i < perm.size(); ++i)
		cout << ' ' << perm[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	deque<int> a(k);
	for (int i = 0; i < k; ++i)
		cin >> a[i];
	output(f(a), a);
	return 0;
}