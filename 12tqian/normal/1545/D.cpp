#include <bits/stdc++.h>

using namespace std;

struct Frac {
	long long n, d;
	Frac(long long _n, long long _d) {
		n = _n, d = _d;
		long long g = __gcd(n, d); n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	Frac(long long _n) : Frac(_n, 1) {}
	Frac() : Frac(0) {}
	friend Frac abs(Frac F) { return Frac(abs(F.n), F.d); }
	friend bool operator<(const Frac& l, const Frac& r) { return l.n * r.d < r.n * l.d; }
	friend bool operator<=(const Frac& l, const Frac& r) { return l.n * r.d <= r.n * l.d; }
	friend bool operator>(const Frac& l, const Frac& r) { return l.n * r.d > r.n * l.d; }
	friend bool operator>=(const Frac& l, const Frac& r) { return l.n * r.d >= r.n * l.d; }
	friend bool operator==(const Frac& l, const Frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const Frac& l, const Frac& r) { return !(l == r); }
	Frac operator-() const { return Frac(-n, d); }
	friend Frac operator+(const Frac& l, const Frac& r) { return Frac(l.n * r.d + r.n * l.d, l.d * r.d); }
	friend Frac operator-(const Frac& l, const Frac& r) { return Frac(l.n * r.d - r.n * l.d, l.d * r.d); }
	friend Frac operator*(const Frac& l, const Frac& r) { return Frac(l.n * r.n, l.d * r.d); }
	friend Frac operator*(const Frac& l, int r) { return l * Frac(r, 1); }
	friend Frac operator*(int r, const Frac& l) { return l * r; }
	friend Frac operator/(const Frac& l, const Frac& r) { return l * Frac(r.d, r.n); }
	friend Frac operator/(const Frac& l, const int& r) { return l / Frac(r, 1); }
	friend Frac operator/(const int& l, const Frac& r) { return Frac(l, 1) / r; }
	friend Frac& operator+=(Frac& l, const Frac& r) { return l = l + r; }
	friend Frac& operator-=(Frac& l, const Frac& r) { return l = l - r; }
	template <class T> friend Frac& operator*=(Frac& l, const T& r) { return l = l * r; }
	template <class T> friend Frac& operator/=(Frac& l, const T& r) { return l = l / r; }
	friend ostream& operator<<(std::ostream& os, const Frac& a) { return os << a.n << "/" << a.d; }
	long long get() { return n / d; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, k;
	cin >> m >> k;
	swap(m, k);
	vector<vector<long long>> a(m, vector<long long>(k));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
		}
	}
	vector<long long> sum(m);
	vector<long long> sum2(m);
	map<long long, int> diff_cnt;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			sum[i] += a[i][j];
			sum2[i] += a[i][j] * a[i][j];
		}
		if (i) {
			++diff_cnt[sum[i] - sum[i - 1]];
		}
	}
	pair<int, long long> best = {0, 0};
	for (auto x : diff_cnt) {
		best = max(best, make_pair(x.second, x.first));
	}
	int row = -1;
	for (int i = 1; i < m; ++i) {
		if (sum[i] - sum[i - 1] != best.second) {
			row = i;
			break;
		}
	}
	vector<pair<int, long long>> eval;
	int idx = -1;
	while (eval.size() < 3) {
		++idx;
		if (idx == row) {
			continue;
		}
		eval.push_back(make_pair(idx, sum2[idx]));
	}
	vector<Frac> coeff(3);
	for (int i = 0; i < 3; ++i) {
		Frac prod = 1;
		Frac root_sum = 0;
		Frac root_prod = 1;
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				continue;
			}
			prod *= (eval[i].first - eval[j].first);
			root_sum += eval[j].first;
			root_prod *= eval[j].first;
		}
		prod = 1 / prod;
		prod *= eval[i].second;
		coeff[0] += root_prod * prod;
		coeff[1] -= root_sum * prod;
		coeff[2] += prod;
	}
	long long actual = (coeff[2] * row * row + coeff[1] * row + coeff[0]).get();
	long long cur = sum2[row];
	long long diff2 = actual - cur;
	long long diff = sum[row - 1] + best.second - sum[row];
	for (int j = 0; j < k; ++j) {
		long long prv = a[row][j];
		long long nxt = diff + a[row][j];
		if (nxt * nxt - prv * prv == diff2) {
			cout << row << ' ' << nxt << '\n';
			return 0;
		}
	}
	return 0;
}