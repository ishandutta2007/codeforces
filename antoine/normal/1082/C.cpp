#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Iter {
	vector<int>::iterator it;
	vector<int> * v;

	Iter(vector<int> &v) {
		it = v.begin();
		this->v = &v;
	}

	bool isEnd() {
		return it == v->end();
	}

	int val() {
		return *it;
	}
	void inc() {
		++it;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<int, vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		int s, r;
		cin >> s >> r;
		mp[s].push_back(r);
	}

	list<Iter> its;

	for (auto &&x : mp) {
		vector<int> &v = x.second;
		sort(v.rbegin(), v.rend());


		partial_sum(v.begin(), v.end(), v.begin());
		while(!v.empty() && v.back() <= 0)
			v.pop_back();

		its.emplace_back(v);
	}

	int ans = 0;

	while (!its.empty()) {
		int res = 0;
		for (auto it = its.begin(); it != its.end();) {
			if(it->isEnd())
				it = its.erase(it);
			else {
				res += it->val();
				it->inc();
				++it;
			}
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';

	return 0;
}