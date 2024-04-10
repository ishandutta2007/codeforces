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

typedef vector<int> vec;

#ifdef local

class init_t {
	public:
		int p[805];

		init_t() {
			int n;
			cin >> n;
			for (int i = 1; i <= n; i++)
				p[i] = i;
			random_shuffle(p + 1, p + n + 1);
			if ((p[1] << 1) > n) {
				for (int i = 1; i <= n; i++)
					p[i] = n + 1 - p[i];
			}
			for (int i = 1; i <= n; i++)
				cerr << p[i] << " ";
			cerr << '\n';
		}

		boolean query(vec v) {
			int sum = 0;
			for (auto x : v)
				sum += p[x];
			return !(sum % v.size());
		}
} init_t;

boolean query(vec v) {
	return init_t.query(v);
} 

#else

boolean query(vec v) {
	if (v.size() == 1u)
		return true;
	cout << '?' << " " << v.size();
	for (auto x : v)
		cout << " " << x;
	cout << endl;
	int rt;
	cin >> rt;
	return rt;
}

#endif

boolean query(vec v, int y) {
	v.push_back(y);
	return query(v);
}

vec& remove(vec& a, int x) {
	a.erase(find(a.begin(), a.end(), x));
	return a;
}

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}
int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : x; 
}

const int N = 803;

int n;
int p[N], q[N], pari[N];

vec find_min_max(vec pos) {
	vec rt;
	for (int i = 0; i < (signed) pos.size() && rt.size() < 2u; i++) {
		vec tmp = pos;
		tmp.erase(tmp.begin() + i);
		if (query(tmp)) {
			rt.push_back(pos[i]);
		}
	}
	return rt;
}

void set_p(int pos, int val) {
	p[pos] = val;
	q[val] = pos;
}
void answer() {
	cout << "!";
	if ((p[1] << 1) > n) {
		for (int i = 1; i <= n; i++)
			cout << " " << n + 1 - p[i];
	} else {
		for (int i = 1; i <= n; i++)
			cout << " " << p[i];
	}
	cout << endl;
	exit(0);
}

vector<int> get_rest(int m, vector<vec> rule) {
	vector<int> rt (n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			rt[i] = p[i] % m;
		}
	}
	int sum = m * (m - 1) / 2;
	for (auto &v : rule) {
		int r = 0;
		for (auto& x : v) {
			if (x < 0) {
				r += n + 1 + x;
				x = q[n + 1 + x];
			} else {
				r += x;
				x = q[x];
			}
		}
		r = (m - r % m) % m;
		for (int i = 1; i <= n; i++) {
			if (rt[i] == -1 && query(v, i)) {
				rt[i] = r;
			}
		}
		sum -= r;
	}
	for (int i = 1; i <= n; i++) {
		(rt[i] == -1) && (rt[i] = sum, 0);
	}
	return rt;
}

int crt(vec a, vec m) {
	int M = 1, rt = 0, t = a.size();
	for (auto x : m)
		M *= x;
	for (int i = 0; i < t; i++)
		rt = (rt + 1ll * a[i] * inv(M / m[i] % m[i], m[i]) * (M / m[i]));
	return rt % M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);	
	cin >> n;
	vec rest (n);
	for (int i = 0; i < n; i++)
		rest[i] = i + 1;
	vec _ = find_min_max(rest);
	set_p(_[0], 1);
	set_p(_[1], n);
	if (n == 2) {
		answer();
	}
	for (int i = 1; i <= n; i++) {
		if (!p[i]) {
			pari[i] = query(vec {i, q[1]});
		} else {
			pari[i] = p[i] & 1;
		}
	}
	remove(remove(rest, _[0]), _[1]);
	for (int l = 2, r = n - 1; l <= r && l <= 4; l++, r--) {
		_ = find_min_max(rest);
		if (pari[_[0]] ^ (l & 1))
			swap(_[0], _[1]);
		set_p(_[0], l);
		set_p(_[1], r);
		remove(remove(rest, _[0]), _[1]);
	}
	if (n <= 8) {
		answer();
	}
	vec r3 = get_rest(3, vector<vec> {vec{1, 2}, vec{2, 3}});
	vec r5 = get_rest(5, vector<vec> {vec{1, 2, -1, -2}, vec{1, 2, -1, -3}, vec{1, 2, -1, -4}, vec{1, 3, -1, -2}});
	vec r7 = get_rest(7, vector<vec> {vec{1, 2, 3, -1, -2, -3}, vec{1, 2, 3, -1, -2, -4},
									   vec{1, 2, 3, -1, -3, -4}, vec{1, 2, 3, -2, -3, -4},
									   vec{1, 2, 4, -1, -2, -3}, vec{1, 3, 4, -1, -2, -3}});

	vec r8 (n + 1, -1);
	vec a[2], b[4], c[8];
	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			r8[i] = p[i] % 8;
		} else {
			a[pari[i]].push_back(i);
		}
	}
	for (int r = 0; r < 2; r++) {
		vec tmp {q[4], q[1], q[2], q[3]};
		tmp.erase(tmp.begin() + r);
		for (auto x : a[r]) {
			b[r + query(tmp, x) * 2].push_back(x);
		}
	}
	for (int r = 0; r < 4; r++) {
		vec tmp {q[4], q[1], q[2], q[3], q[n], q[n - 1], q[n - 2], q[n - 3]};
		tmp.erase(tmp.begin() + r);
		for (auto x : b[r]) {
			if (!r) {
				c[!query(tmp, x) * 4].push_back(x);
			} else {
				c[r + query(tmp, x) * 4].push_back(x);
			}
		}
	}
	for (int r = 0; r < 8; r++) {
		for (auto x : c[r]) {
			r8[x] = r;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		p[i] = crt(vec{r3[i], r5[i], r7[i], r8[i]}, vec{3, 5, 7, 8});
	}
	answer();
	return 0;
}