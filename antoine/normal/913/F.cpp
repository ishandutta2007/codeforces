#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int Mod = 998244353;

struct intM {
	int v;

	intM() {}
	intM(const int v) { this->v = ((v % Mod) + Mod) % Mod; }
	intM(const long long v) { this->v = ((v % Mod) + Mod) % Mod; }
	intM operator=(const int n) { return *this = intM(n); }

	intM operator+(const intM &other) const { return{ (v + other.v) % Mod }; }
	intM operator-(const intM &other) const { return{ (v - other.v + Mod) % Mod }; }
	intM operator*(const intM &other) const { return{ ((long long)v * other.v) % Mod }; }
	friend intM pow(intM n, int k) { intM res(1); for (; k; k >>= 1) { if (k & 1) res *= n; n *= n; } return res; }
	intM operator/(const intM &other) const { return{ (*this) * pow(intM(other), Mod - 2) }; }

	intM operator+(const int &other) const { return{ *this + intM(other) }; }
	intM operator-(const int &other) const { return{ *this - intM(other) }; }
	intM operator*(const int &other) const { return{ *this * intM(other) }; }
	intM operator/(const int &other) const { return{ *this / intM(other) }; }

	intM operator+=(const intM &other) { return *this = *this + other; }
	intM operator-=(const intM &other) { return *this = *this - other; }
	intM operator*=(const intM &other) { return *this = *this * other; }
	intM operator/=(const intM &other) { return *this = *this / other; }

	friend istream &operator >> (istream &in, intM &n) { in >> n.v; return in; }
	friend ostream &operator<<(ostream &out, const intM &n) { out << n.v; return out; }
	operator int() { return v; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, a, b;
	cin >> N >> a >> b;

	intM p = intM(a) / intM(b);
	intM pBar = intM(1) - intM(p);

	vector<vector<intM>> f(N + 1, vector<intM>(N + 1));
	for (int i = 0; i <= N; ++i) {
		f[i][0] = f[i][i] = 1;
		for (int k = 1; k < i; ++k)
			f[i][k] = pow(p, i - k) * f[i - 1][k - 1] + pow(pBar, k) * f[i - 1][k];
	}

	vector<intM> g(N + 1, 1);
	for (int i = 0; i <= N; ++i)
		for (int j = 1; j < i; ++j)
			g[i] -= f[i][j] * g[j];

	vector<intM> e(N + 1, 0);
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j)
			e[i] += f[i][j] * g[j] * (j * (j - 1) / 2 + j * (i - j) + e[j] + e[i - j]);
		
		// new = old + g(i) * iC2 + g(i) * new
		// new * (1 - g(i)) = old + g(i) * iC2
		e[i] = (e[i] + g[i] * i * (i - 1) / 2) / (1 - g[i]);
	}

	cout << e[N];
	return 0;
}