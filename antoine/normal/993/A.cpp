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
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

const int inf = 1e9;
const double eps = 1e-6;

struct Line {
	double a, b;
	Line(pair<double, double> pt, int a) : a(a) {
		b = pt.second - a*pt.first;
	}
	// > 0 if pt below line
	double cmpPt(pair<double, double> pt) {
		return a*pt.first + b - pt.second;
	}
};

pair<double, double> extra1, extra2;

bool containsPt1(const vector<pair<int, int>> sq, pair<double, double> pt) {
	int xMin = inf, xMax = -inf, yMin = inf, yMax = -inf;
	for (auto &&pt : sq) {
		xMin = min(xMin, pt.first);
		xMax = max(xMax, pt.first);
		yMin = min(yMin, pt.second);
		yMax = max(yMax, pt.second);
	}

	extra1.first = (xMin + xMax) / 2.0;
	extra1.second = (yMin + yMax) / 2.0;

	return pt.first >= xMin && pt.first <= xMax &&
		pt.second >= yMin && pt.second <= yMax;
}

bool containsPt2(const vector<pair<int, int>> sq, pair<double, double> pt) {
	int xMin = inf, xMax = -inf, yMin = inf, yMax = -inf;
	for (auto &&pt : sq) {
		xMin = min(xMin, pt.first);
		xMax = max(xMax, pt.first);
		yMin = min(yMin, pt.second);
		yMax = max(yMax, pt.second);
	}

	extra2.first = (xMin + xMax) / 2.0;
	extra2.second = (yMin + yMax) / 2.0;

	const double yAvg = (yMin + yMax) / 2.0;
	
	return
		Line({ xMin, yAvg }, -1).cmpPt(pt) <= eps &&
		Line({ xMax, yAvg }, -1).cmpPt(pt) >= -eps &&
		Line({ xMin, yAvg }, +1).cmpPt(pt) >= -eps &&
		Line({ xMax, yAvg }, +1).cmpPt(pt) <= eps;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> sq1(4, { 0,0 }), sq2(4, { 0, 0 });
	for (int i = 0; i < 4; ++i)
		cin >> sq1[i].first >> sq1[i].second;
	for (int i = 0; i < 4; ++i)
		cin >> sq2[i].first >> sq2[i].second;

	for(auto &&pt : sq2)
		if (containsPt1(sq1, pt)) {
			cout << "YES";
			return 0;
		}

	for(auto &&pt : sq1)
		if (containsPt2(sq2, pt)) {
			cout << "YES";
			return 0;
		}

	if (containsPt2(sq2, extra1) || containsPt1(sq1, extra2)) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}