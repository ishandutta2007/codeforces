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

const int N = 200200;

const int K = 5;

int n, k;
vector<int> g[N];

struct DP {
	pair<ll, int> f[K];
	DP() {
		memset(f, 0, sizeof(f));
	}
	DP goUp() const {
		DP res;
		for (int rem = 0; rem < k; rem++) {
			int nrem = rem + 1;
			res.f[nrem % k].first = f[rem].first + (nrem / k) * 1LL * f[rem].second;
			res.f[nrem % k].second = f[rem].second;
		}
		return res;
	}
};

DP f[N];

ll globalRes = 0;

DP combine(DP a, DP b) {
	DP res;
	for (int x = 0; x < k; x++) {
		for (int y = 0; y < k; y++) {
			globalRes += a.f[x].first * b.f[y].second + a.f[x].second * b.f[y].first + ((x + y + k - 1) / k) * 1LL * a.f[x].second * b.f[y].second;
		}
	}
	for (int x = 0; x < k; x++) {
		res.f[x].first = a.f[x].first + b.f[x].first;
		res.f[x].second = a.f[x].second + b.f[x].second;
	}
	return res;
}

DP dfs(int v, int p) {
	f[v].f[0] = make_pair(0LL, 1);
	for (int to : g[v]) {
		if (to == p) continue;
		DP z = dfs(to, v);
		z = z.goUp();
		f[v] = combine(f[v], z);
	}
	return f[v];
}

int main(int argc, char * argv[]) {
	srand(time(0));

#ifdef LOCAL
	//gen();
	freopen("input.txt", "r", stdin);
#else
	
#endif

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, -1);

	cout << globalRes << endl;

}