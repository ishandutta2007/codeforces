#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Vec: pair<int, int> {
	Vec operator+(const Vec &other) const {
		Vec res;
		res.first = first + other.first;
		res.second = second + other.second;
		return res;
	}

	Vec operator-(const Vec &other) const {
		Vec res;
		res.first = first - other.first;
		res.second = second - other.second;
		return res;
	}
};

bool f(const int n, const vector<Vec> pts, const vector<Vec> vecs, const Vec T) {
	multiset<Vec> ms(vecs.begin(), vecs.end());
	for (auto &&p : pts) {
		Vec x = T - p;
		auto it = ms.find(x);
		if(it == ms.end())
			return false;
		ms.erase(it);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<Vec> pts(n);
	vector<Vec> vecs(n);

	for (auto &&x : pts)
		cin >> x.first >> x.second;
	for (auto &&x : vecs)
		cin >> x.first >> x.second;

	for (auto &&x : vecs) {
		Vec T = pts[0] + x;
		if (f(n, pts, vecs, T)) {
			cout << T.first << ' ' << T.second << endl;
			return 0;
		}
	}
	return 0;
}