#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a%b);
}

struct Fraction {
	long long num = 0, den = 1;
	Fraction() {}
	Fraction(long long n, long long d) {
		if (n == 0)
			d = 1;
		if (d < 0) {
			n *= -1;
			d *= -1;
		}
		long long g = gcd(n, d);
		num = n / g;
		den = d / g;
	}
	bool operator==(const Fraction &o) const {
		return num == o.num && den == o.den;
	}
	bool operator!=(const Fraction &o) const {
		return !(*this == o);
	}
	Fraction operator*(long long a) const {
		return Fraction(a * num, den);
	}
	Fraction operator+(long long a) const {
		return{ num + a*den, den };
	}
	bool operator==(const long long x) const {
		return den == 1 && num == x;
	}
	bool operator!=(const long long x) const {
		return !(*this == x);
	}
	Fraction operator+(const Fraction &o) const {
		return{ num * o.den + den * o.num, den * o.den };
	}
};

struct Line {
	Fraction a, b;
	Line(std::pair<long long, long long> p1, std::pair<long long, long long> p2) {
		a = { p1.second - p2.second, p1.first - p2.first };
		b = a * (-p1.first) + p1.second;
		// p1.second = p1.first * a + b;
	}
};

int n;
int y[1000];

auto removeLine(std::vector<std::pair<long long, long long>> pts, Line line) {
	std::vector<std::pair<long long, long long>> result;
	for (long long i = 0; i < pts.size(); ++i) {
		if ((line.a * pts[i].first) + line.b != pts[i].second)
			result.push_back(pts[i]);
	}
	return result;
}

bool program() {
	if (n == 1) return false;
	if (n == 2) return true;
	std::vector<std::pair<long long, long long>> pts(n);
	for (long long i = 0; i < n; ++i)
		pts[i] = { i, y[i] };
	for (long long i = 1; i < n; ++i) {
		std::swap(pts[1], pts[i]);
		Line line1( pts[0], pts[1]);
		auto rest = removeLine(pts, line1);
		if (rest.empty()) return false;
		if (rest.size() == 1) return true;
		Line line2(rest[0], rest[1]);
		if (line1.a != line2.a)
			continue;
		if (removeLine(rest, line2).empty())
			return true;
		std::swap(pts[1], pts[i]);
	}
	Line line1(pts[1], pts[2]);
	auto rest = removeLine(pts, line1);
	return rest.size() == 1 && rest[0] == pts[0];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (long long i = 0; i < n; ++i)
		std::cin >> y[i];
	std::cout << (program() ? "Yes" : "No");
	return 0;
}