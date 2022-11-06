#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Interval {
	int l, r;

	Interval(int l, int r) : l(l), r(r) {}

	int size() const {
		return r - l + 1;
	}

	bool operator<(const Interval &other) const {
		return l != other.l ? l < other.l : r < other.r;
	}

	struct IntervalCompBySize {
		bool operator()(const Interval &lhs, const Interval &rhs) const {
			auto diff = (lhs.r - lhs.l) - (rhs.r - rhs.l);
			return diff ? diff < 0 : lhs.l != rhs.l ? lhs.l < rhs.l : lhs.r < rhs.r;
		}
	};
};


struct IntervalDS {
	set<Interval> byLR;
	set<Interval, Interval::IntervalCompBySize> bySZ;

	void insert(const Interval i) {
		if (i.l <= i.r) {
			byLR.insert(i);
			bySZ.insert(i);
		}
	}

	bool erase(const Interval &i) {
		return byLR.erase(i) && bySZ.erase(i);
	}

	Interval find(int x) {
		auto it = byLR.lower_bound({ x + 1, -1 });
		return it != byLR.begin() && x <= (--it)->r ? *it : Interval(-1, -3);
	}

	int getMaxSize() const {
		return bySZ.crbegin()->size();
	}
};

vector<long long> getDiff(const vector<long long> &a) {
	auto res = a;
	for (int i = 1; i < a.size(); ++i)
		res[i] = a[i] - a[i - 1];
	return res;
}

int getSign(long long x) {
	return (x < 0) ? -1 : (x > 0) ? 1 : 0;
}

void query(const int i, const long long d, vector<long long> &a, IntervalDS &intDS) {
	if (getSign(a[i]) == getSign(a[i] + d)) {// 3 cases
		a[i] += d;
		return;
	}

	if (getSign(a[i]) && getSign(a[i] + d)) { // 2 cases: + => - and - => +
		auto d1 = -a[i];
		auto d2 = a[i] + d;
		query(i, d1, a, intDS);
		query(i, d2, a, intDS);
		return;
	}

	if (getSign(a[i])) { // 2 cases: + => 0 and - => 0
		auto intv = intDS.find(i);
		intDS.erase(intv);
		intDS.insert({ intv.l, i - 1 });
		intDS.insert({ i + 1, intv.r });
	} else if (getSign(a[i] + d) > 0) { // 0 => +
		if (i > 1 && a[i - 1] > 0 && i + 1 < a.size() && a[i + 1]) {
			auto intvL = intDS.find(i - 1);
			auto intvR = intDS.find(i + 1);
			intDS.erase(intvL);
			intDS.erase(intvR);
			intDS.insert({ intvL.l, intvR.r });
		}
		else if (i > 1 && a[i - 1] > 0) {
			auto intvL = intDS.find(i - 1);
			intDS.erase(intvL);
			intDS.insert({ intvL.l, i });
		}
		else if (i + 1 < a.size() && a[i + 1]) {
			auto intvR = intDS.find(i + 1);
			intDS.erase(intvR);
			intDS.insert({ i, intvR.r });
		}
		else
			intDS.insert({ i, i });
	}
	else { // 0 =>  -

		if (i > 1 && a[i - 1] && i + 1 < a.size() && a[i + 1] < 0) {
			auto intvL = intDS.find(i - 1);
			auto intvR = intDS.find(i + 1);
			intDS.erase(intvL);
			intDS.erase(intvR);
			intDS.insert({ intvL.l, intvR.r });
		}
		else if (i > 1 && a[i - 1]) {
			auto intvL = intDS.find(i - 1);
			intDS.erase(intvL);
			intDS.insert({ intvL.l, i });
		}
		else if (i + 1 < a.size() && a[i + 1] < 0) {
			auto intvR = intDS.find(i + 1);
			intDS.erase(intvR);
			intDS.insert({ i, intvR.r });
		}
		else
			intDS.insert({ i, i });
	}
	a[i] += d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	a = getDiff(a);
	a[0] = numeric_limits<long long>::min() / 8;

	IntervalDS intDS;
	intDS.insert({ 1, n - 1 });
	{

		vector<long long> tmp(a.size(), -1);
		tmp[0] = a[0];

		for (int i = 1; i < tmp.size(); ++i) {

			query(i, a[i] - tmp[i], tmp, intDS);
			/*
			for (int i = 0; i < a.size(); ++i)
				cout << (tmp[i] > 0 ? '+' : tmp[i] < 0 ? '-' : ' ');
			cout << "\n";
			for (auto &&x : intDS.byLR)
				cout << "(" << x.l << ", " << x.r << "), ";
			cout << "\n\n\n";
			*/
		}
	}

	int m;
	cin >> m;

	while (m-- > 0) {
		int l, r, d;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		cin >> l >> r >> d;
		--l, --r;
		if(l > 0)
			query(l, d, a, intDS);
		if (r + 1 < n)
			query(r + 1, -d, a, intDS);
		/*
		for (int i = 0; i < a.size(); ++i)
			cout << (a[i] > 0 ? '+' : a[i] < 0 ? '-' : '0');
		cout << "\n";
		for (auto &&x : intDS.byLR)
			cout << "(" << x.l << ", " << x.r << "), ";
		cout << "\n";
		*/
		cout << (intDS.getMaxSize() + 1) << '\n';

	}
	return 0;
}