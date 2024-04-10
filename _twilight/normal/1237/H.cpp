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

int T;
int n;

void solve() {
	vector<int> a, b;

	auto read = [&] (vector<int>& v) {
		static char tmp[4005];
		scanf("%s", tmp);
		n = strlen(tmp);
		v.resize(n);
		for (int i = 0; i < n; i++)
			v[i] = tmp[i] - '0';
	};

	read(a);
	read(b);

	vector<int> c (3, 0);
	for (int i = 0; i < n; i += 2) {
		c[a[i] + a[i + 1]]++;
	}
	for (int i = 0; i < n; i += 2) {
		c[b[i] + b[i + 1]]--;
	}
	if (smin(c[0], c[1], c[2]) < 0) {
		puts("-1");
		return;
	}

	auto getsum = [&] (vector<int>& a) {
		int sum = 0;
		for (int i = 0; i < n; i += 2) {
			if (a[i] + a[i + 1] == 1) {
				sum = sum + a[i] - a[i + 1];
			}
		}
		return sum;
	};
	
	auto make_equal = [&] (vector<int>& a, int dif) {
		if (!dif)
			return -1;
		int sum = 0;
		for (int i = 0; i < n; i += 2) {
			if (a[i] + a[i + 1] == 1) {
				sum = sum + a[i] - a[i + 1];
			}
			if (sum == dif) {
				return i;	
			}
		}
		return -2;
	};

	int suma = getsum(a);
	int sumb = getsum(b);
	int goal = (suma + sumb) >> 1;
	int rst = -1, red = -1;
	rst = make_equal(a, goal);
	if (rst == -2) {
		red = make_equal(b, goal);
		assert(red > -2);
	}

	vector<int> rt;
	auto push = [&] (int x) {
		if (x < 0)
			return;
		x += 2;
		reverse(a.begin(), a.begin() + x);
		rt.push_back(x);
	};
	push(rst);
	if (red >= 0)
		reverse(b.begin(), b.begin() + red + 2);
	for (int i = 0; i < n; i += 2) {
		int gx = b[n - i - 2], gy = b[n - i - 1];
		for (int j = i; j < n; j += 2) {
			if (a[j] == gy && a[j + 1] == gx) {
				push(j - 2);
				push(j);
				goto succ;
			}
		}
		assert(false);
succ:;
	}
	if (red >= 0)
		rt.push_back(red + 2);

	printf("%d\n", (signed) rt.size());
	for (auto x : rt)
		printf("%d ", x);
	putchar('\n');
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}