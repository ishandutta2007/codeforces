#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxX = (int) 1e5 + 9;

struct LMSInfo {
	vector<int> dp;
	vector<vector<int>> buckets;
	vector<int> seq;
};

LMSInfo LMS(const vector<int> &a, const function<bool(int, int)> comp) {
	vector<int> dp;
	vector<vector<int>> buckets;
	static int pred[MaxX + 9];

	for (const int &x : a) {
		auto it = lower_bound(dp.begin(), dp.end(), x, comp);
		pred[x] = it != dp.begin() ? *prev(it) : 0;
		if (it == dp.end()) {
			dp.push_back(x);
			buckets.push_back( { x });
		} else {
			*it = x;
			buckets[it - dp.begin()].push_back(x);
		}
	}

	vector<int> seq;
	if (!dp.empty()) {
		seq = {dp.back()};
		while (pred[seq.back()] != 0)
			seq.push_back(pred[seq.back()]);
		reverse(seq.begin(), seq.end());
	}

	return {dp, buckets, seq};
}

LMSInfo LIS(const vector<int> &a) {
	function<bool(int, int)> fn = [](const int x, const int y) {
		return x<y;
	};
	return LMS(a, fn);
}

LMSInfo LDS(const vector<int> &a) {
	function<bool(int, int)> fn = [](const int x, const int y) {
		return x>y;
	};
	return LMS(a, fn);
}

void rem(vector<int> &a, const vector<int> &v) {
	auto i = a.begin();
	auto j = v.begin();
	for (; i != a.end() && j != v.end(); ++i) {
		if (*i == *j)
			*i = -1, ++j;

	}
	assert(j == v.end());
	a.erase(remove(a.begin(), a.end(), -1), a.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		vector<int> a;
		{

			int n;
			cin >> n;
			a.resize(n);
		}
		for (int &x : a)
			cin >> x;

		vector<vector<int>> res;
		int k = (int) a.size() + 2;

		while (!a.empty()) {
			while (k * (k + 1LL) / 2 > (int) a.size())
				--k;

			const LMSInfo info = LIS(a);

			const vector<vector<int>> &buckets = info.buckets;

			if ((int) buckets.size() <= k) {
				move(buckets.begin(), buckets.end(), back_inserter(res));
				break;
			}

			const vector<int> &seq = info.seq;
			rem(a, seq);
			res.push_back(move(seq));
		}

		cout << res.size() << '\n';
		for (const auto &x : res) {
			cout << x.size();
			for (const int &y : x)
				cout << ' ' << y;
			cout << '\n';
		}
	}
	return 0;
}