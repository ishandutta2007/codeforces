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
	bool was = false;
	os << "{";
	for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const set<T> & v) {
	bool was = false;
	os << "{";
	for (typename set<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const multiset<T> & v) {
	bool was = false;
	os << "{";
	for (typename multiset<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const map<P, Q> & v) {
	bool was = false;
	os << "{";
	for (typename map<P, Q>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

#define all(x) (x).begin(), (x).end()

string nextToken() {
	static char str[(int)1e6 + 5];
	scanf("%s", str);
	return str;
}

template<class T>
T nextInt() {
	ll x = 0;
	bool p = false;
	char c;
	do {
		c = getchar();
	} while (c <= 32);
	if (c == '-') {
		p = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return (p ? -x : x);
}

bool f(const double& T, const vector<int>& a, const vector<int>& b, int n, int p) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double add = T * a[i] - b[i];
		if (add < 0) continue;
		sum += add;
	}
	return T * p >= sum;
}

int main(int argc, char * argv[]) {
	srand(time(0));

#ifdef LOCAL
	//gen();
	freopen("input.txt", "r", stdin);
#else
	
#endif
	
	int n, p;

	scanf("%d%d", &n, &p);

	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	if (sum <= p) {
		cout << "-1" << endl;
		exit(0);
	}

	double le = 0, ri = 1e12;

	for (int iter = 0; iter < 100; iter++) {
		double mid = (le + ri) / 2;
		if (f(mid, a, b, n, p)) le = mid;
		else ri = mid;
	}

	printf("%.20f\n", le);

}