#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned char ubyte;

const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e18 + 5;

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

template<class T>
T sqr(const T & x) { return x * x; }

template<class T> 
ll abs(const T & x) { return x < 0 ? -x : x; }

template<class T>
ll myround(const T & x) { return x < 0 ? x - 0.5 : x + 0.5; }

template<class T> 
bool chmin(T & x, const T & y) {
	if (y < x) {
		x = y;
		return true;
	}
	return false;
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v) {
	os << "{";
	for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
		os << *it;
		if ((it + 1) != v.end()) os << ", ";
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const pair<P, Q> & p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<class T> 
bool chmax(T & x, const T & y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

#define all(a) (a).begin(), (a).end()

typedef vector<vector<double>> mat;

mat mul(const mat & a, const mat & b) {
	int n =	(int)a.size();
	mat z(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				z[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return z;
}

mat poww(mat a, int k) {
	int n = (int)a.size();
	mat res(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		res[i][i] = 1;
	}
	while (k) {
		if ((k & 1)) {
			res = mul(res, a);
			k--;
		}
		else {
			a = mul(a, a);
			k /= 2;
		}
	}
	return res;
}

int main() {
	srand(time(0));
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#else
#endif

	int k, n;
	cin >> k >> n;
	n++;
	vector<double> p(n);

	for (double & x : p) {
		cin >> x;
	}

	mat z(128, vector<double>(128));

	for (int x = 0; x < 128; x++) {
		for (int y = 0; y < n; y++) {
			z[x][x ^ y] += p[y];
		}
	}

	z = poww(z, k);

	double res = 1 - z[0][0];


	printf("%.20f\n", res);
}