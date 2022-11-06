#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

template<typename T> struct ArrayRange {
	int offset;
	int size;
	std::vector<T> container;
	double maxSec();

	ArrayRange(int lo, int hi) {
		offset = lo;
		container.resize(hi - lo + 1);
	}

	ArrayRange(int lo, std::vector<T> cont) {
		offset = lo;
		container = cont;
	}

	T& operator[](size_t pos) {
		return container[pos - offset];
	}
};

template<> double ArrayRange<std::pair<double, double>>::maxSec() {
	auto res = container[0].second;
	for (auto &&x : container)
		res = std::max(res, x.second);
	return res;
}

int N;
double proba[1 << 6][1 << 6];

ArrayRange<std::pair<double, double>> f(int lo, int hi, int &round) {
	if (lo + 1 == hi) {
		round = 0;
		return ArrayRange<std::pair<double, double>>(lo, { {proba[lo][hi], proba[lo][hi]}, {proba[hi][lo], proba[hi][lo]} });
	}

	int mid = (lo + hi) >> 1;
	auto res1 = f(lo, mid, round);
	auto res2 = f(mid + 1, hi, round);
	++round;

	auto res = ArrayRange<std::pair<double, double>>(lo, hi);
	
	for (int i = lo; i <= mid; ++i)
		for (int j = mid + 1; j <= hi; ++j)
			res[i].first += res1[i].first * res2[j].first * proba[i][j];

	for (int i = mid + 1; i <= hi; ++i)
		for (int j = lo; j <= mid; ++j)
			res[i].first += res2[i].first * res1[j].first * proba[i][j];

	double bestLeft = res1.maxSec(), bestRight = res2.maxSec();


	for (int i = lo; i <= mid; ++i)
		res[i].second = res1[i].second + res[i].first * (1 << round) + bestRight;
	for (int i = mid + 1; i <= hi; ++i)
		res[i].second = res2[i].second + res[i].first * (1 << round) + bestLeft;
	return res;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> N;
	for (int i = 0; i < (1 << N); ++i)
		for (int j = 0; j < (1 << N); ++j) {
			std::cin >> proba[i][j];
			proba[i][j] /= 100.0;
		}

	int round = 0;
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << f(0, (1 << N) - 1, round).maxSec();
	return 0;
}