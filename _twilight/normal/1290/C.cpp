#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

int n, m;
int ans = 0;
string s;
vector<vector<int>> app;
vector<int> uf, v, c[2];

int find(int x) {
	if (uf[x] == x)
		return x;
	int f = uf[x];
	uf[x] = find(uf[x]);
	v[x] ^= v[f];
	return uf[x];
}

int calc(int p) {
	int q = find(p);
	if (q == find(m)) {
		return c[0][q]; 
	}
	return min(c[0][q], c[1][q]);
}

void unit(int x, int y, int d) {
	find(x), find(y);
	d ^= v[x] ^ v[y];
	x = find(x), y = find(y);
	if (x > y)
		swap(x, y);
	if (x ^ y) {
		ans -= calc(x);
		ans -= calc(y);
		uf[x] = y;
		v[x] = d;
		c[0][y] += c[d][x];
		c[1][y] += c[d ^ 1][x];	
		ans += calc(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	uf.resize(m + 1);
	c[0].resize(m + 1, 1);
	c[1].resize(m + 1, 0);
	v.resize(m + 1, 0);
	app.resize(n);
	c[0][m] = 0;
	for (int i = 0; i <= m; i++)
		uf[i] = i;
	for (int i = 0, k, x; i < m; i++) {
		cin >> k;
		while (k--) {
			cin >> x;
			app[--x].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		vector<int>& v = app[i];
		if (v.size() == 2u) {
			unit(v[0], v[1], (s[i] - '0') ^ 1);
		} else if (v.size() == 1u) {
			unit(v[0], m, (s[i] - '0'));
		}
		cout << ans << '\n';
	}
	return 0;
}