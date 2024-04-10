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

using namespace std;

int n, a, b;
double pA[2000], pB[2000], pAB[2000];

pair<double, array<int, 2>> f(double costA, double costB) {
	double E = 0;
	int countA = 0, countB = 0;
	for (int i = 0; i < n; ++i) {
		struct Entry {
			double E;
			bool usesA;
			bool usesB;

			bool operator<(const Entry &other) const {
				return E < other.E;
			}
		};
		const Entry choices[] = {
			{ 0, false, false },
			{ pA[i] - costA, true, false },
			{ pB[i] - costB, false, true },
			{ pAB[i] - costA - costB, true, true },
		};
		const Entry &bestChoice = *max_element(choices, choices + 4);
		E += bestChoice.E;
		if (bestChoice.usesA) ++countA;
		if (bestChoice.usesB) ++countB;
	}

	return{ E + costA * a + costB * b, { countA, countB } };
}

pair<double, int> f(const double &costA) {
	double lo = 0;
	double hi = 2;
	for (int i = 0;; ++i) {
		auto mid = (lo + hi) / 2;
		auto res = f(costA, mid);
		if (res.second[1] > b && i < 60)
			lo = mid;
		else if (res.second[1] < b && i < 60)
			hi = mid;
		else
			return{ res.first, res.second[0] };
	}
}

double f() {
	double lo = 0;
	double hi = 2;
	for (int i = 0;; ++i) {
		auto mid = (lo + hi) / 2;
		auto res = f(mid);
		if (res.second > a && i < 60)
			lo = mid;
		else if (res.second < a && i < 60)
			hi = mid;
		else
			return res.first;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	
	for (int i = 0; i < n; ++i)
		cin >> pA[i];

	for (int i = 0; i < n; ++i) {
		cin >> pB[i];
		pAB[i] = pA[i] + (1 - pA[i]) * pB[i];
	}
	
	cout << setprecision(10) << f();
	return 0;
}