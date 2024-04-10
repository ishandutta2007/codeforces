#include <bits/stdc++.h>

using namespace std;

const int MX = 500000;

namespace fwt {
	long long dataAdd[MX + 1], dataMul[MX + 1];
	
	void internalUpdate(int at, int mul, int add) {
		while (at <= MX) {
			dataMul[at] += mul;
			dataAdd[at] += add;
			at |= (at + 1);
		}
	}

	void add(int left, int right, int by) {
		left++;
		right++;
		
		internalUpdate(left, by, -by * (left - 1));
		internalUpdate(right, -by, by * right);
	}

	long long get(int at) {
		at++;
		
		long long mul = 0;
		long long add = 0;
		int start = at;
		while (at >= 0) {
			mul += dataMul[at];
			add += dataAdd[at];
			at = (at & (at + 1)) - 1;
		}
		
		return mul * start + add;
	}
}

bool solve(int n, int sa[MX], int ea[MX], int sb[MX], int eb[MX]) {
	memset(fwt::dataAdd, 0, sizeof fwt::dataAdd);
	memset(fwt::dataMul, 0, sizeof fwt::dataMul);
	
	vector<tuple<int, int, int>> events;
	for (int i = 0; i < n; i++) {
		events.emplace_back(sb[i], 0, i);
		events.emplace_back(eb[i], 1, i);
	}
	
	sort(events.begin(), events.end());
	
	for (auto& e : events) {
		int t, i;
		tie(ignore, t, i) = e;
		if (t == 0) {
			if (fwt::get(ea[i]) - fwt::get(sa[i] - 1) > 0) return true;
		}
		else {
			fwt::add(sa[i], ea[i], 1);
		}
	}
	
	return false;
}

int sa[MX], ea[MX], sb[MX], eb[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	set<int> xs;
	for (int i = 0; i < n; i++) {
		ignore = scanf("%d %d %d %d", sa + i, ea + i, sb + i, eb + i);
		
		xs.insert(sa[i]);
		xs.insert(sb[i]);
		xs.insert(ea[i]);
		xs.insert(eb[i]);
	}
	
	map<int, int> mp;
	int id = 0;
	for (int x : xs) mp[x] = id++;
	
	for (int i = 0; i < n; i++) {
		sa[i] = mp[sa[i]];
		ea[i] = mp[ea[i]];
		sb[i] = mp[sb[i]];
		eb[i] = mp[eb[i]];
	}
	
	bool bad = solve(n, sa, ea, sb, eb) || solve(n, sb, eb, sa, ea);
	printf("%s\n", bad ? "NO" : "YES");
	
	return 0;
}