#include <iostream>
#include<algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <array>

using namespace std;

struct Segment {
	int idx, val, len;
	Segment(int i, int v, int l) : idx(i), val(v), len(l) {}
};

struct Comp1 {
	bool operator()(const Segment &l, const Segment &r) const {
		if (l.len != r.len)
			return l.len > r.len;
		return l.idx < r.idx;
	}
};


struct Comp2 {
	bool operator()(const Segment &l, const Segment &r) const {
		return l.idx < r.idx;
	}
};

set<Segment, Comp1> s1; // by len
set<Segment, Comp2> s2; // by idx

void in() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int idx = 0;
	int val = 0;

	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a != val) {
			if (val) {
				s2.emplace(*(s1.emplace(idx, val, i - idx).first));
			}
			idx = i;
			val = a;
		}
	}
	s2.emplace(*(s1.emplace(idx, val, n - idx).first));
}

int main() {
	in();

	int ans = 0;
	for (; s1.size(); ++ans) {
		auto it1 = s1.begin();
		auto it2 = s2.find(*it1);
		s1.erase(it1);
		it2 = s2.erase(it2);
		if (it2 != s2.begin() && it2 != s2.end()) {
			auto it3 = it2;
			--it2;
			if (it2->val == it3->val) {
				auto elt = *it2;
				elt.len += it3->len;
				
				s1.erase(*it2);
				s1.erase(*it3);
				it2 = s2.erase(it2);
				it2 = s2.erase(it2);

				s2.insert(elt);
				s1.insert(elt);
			}
		}
	}
	cout << ans;
	return 0;
}