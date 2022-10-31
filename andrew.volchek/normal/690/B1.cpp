#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acos(-1.0);
const ll LINF = (ll)1e18 + 5;
const int INF = (int)1e9 + 5;

template<class T>
T sqr(T x) { return x * x; }

template<class T>
T abs(T x) { return x < 0 ? -x : x; }

template<class T>
ll round(T x) { return x < 0 ? x - 0.5 : x + 0.5; }

template<class T>
bool chmin(T & x, const T & y) {
	if (y < x) {
		x = y;
		return true;
	}
	return false;
}

template<class T>
bool chmax(T & x, const T & y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const pair<P, Q> & p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v) {
	os << "{";
	bool was = false;
	for (const T & x : v) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const set<T> & v) {
	os << "{";
	bool was = false;
	for (const T & x : v) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const map<P, Q> & m) {
	os << "{";
	bool was = false;
	for (const auto & x : m) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
	#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#else
	#define DEBUG(x) {}
#endif

const int N = 55;

int n;
char s[N][N];
int sum[5][N][N];

void calcSum(int val) {
	auto cur = sum[val];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cur[i][j] = cur[i - 1][j] + cur[i][j - 1] - cur[i - 1][j - 1] + (s[i][j] == (val + '0') ? 1 : 0);
		}
	}
}

bool ok(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int getSum(int val, int x, int y, int xx, int yy) {
	if (x > xx || y > yy || !ok(x, y) || !ok(xx, yy)) return 0;
	auto cur = sum[val];
	return cur[xx][yy] - cur[x - 1][yy] - cur[xx][y - 1] + cur[x - 1][y - 1];
}

bool fullOf(int val, int x, int y, int xx, int yy, int & s) {
	if (x > xx || y > yy || !ok(x, y) || !ok(xx, yy)) return true;
	auto cur = sum[val];
	int tmp = cur[xx][yy] - cur[x - 1][yy] - cur[xx][y - 1] + cur[x - 1][y - 1];
	if ((xx - x + 1) * (yy - y + 1) != tmp) return false;
	s -= tmp;
	return true;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#else

#endif

	scanf("%d", &n);
		
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}

	for (int val = 0; val <= 4; val++) {
		calcSum(val);
	}

	int total1 = getSum(1, 1, 1, n, n);
	int total2 = getSum(2, 1, 1, n, n);
	int total3 = getSum(3, 1, 1, n, n);
	int total4 = getSum(4, 1, 1, n, n);

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int xx = x; xx <= n; xx++) {
				for (int yy = y; yy <= n; yy++) {
					int tmp = total4;
					if (!fullOf(4, x, y, xx, yy, tmp)) continue;
					if (tmp != 0) continue;
					tmp = total1;
					if (!fullOf(1, x - 1, y - 1, x - 1, y - 1, tmp) || !fullOf(1, xx + 1, yy + 1, xx + 1, yy + 1, tmp) ||
						!fullOf(1, x - 1, yy + 1, x - 1, yy + 1, tmp) || !fullOf(1, xx + 1, y - 1, xx + 1, y - 1, tmp)) continue;
					if (tmp != 0) continue;
					tmp = total2;
					if (!fullOf(2, x, y - 1, xx, y - 1, tmp) || !fullOf(2, x, yy + 1, xx, yy + 1, tmp) || 
						!fullOf(2, x - 1, y, x - 1, yy, tmp) || !fullOf(2, xx + 1, y, xx + 1, yy, tmp)) continue;
					if (tmp != 0) continue;
					if (total3 != 0) continue;
					puts("Yes");
					exit(0);
				}
			}
		}
	}

	puts("No");
}