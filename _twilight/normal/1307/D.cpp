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

#define pii pair<int, int>

const int N = 2e5 + 5;

typedef class Data {
	public:
		int f1, f2, id;

		Data() {	}
		Data(int f1, int f2, int id) : f1(f1), f2(f2), id(id) {	}
} Data;

int n, m, K;
int f1[N], f2[N];
vector<int> G[N];

void bfs(int s, int* f) {
	for (int i = 1; i <= n; i++)
		f[i] = -1;
	queue<int> Q;
	Q.push(s);
	f[s] = 0;
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		for (auto e : G[p]) {
			if (f[e] == -1) {
				f[e] = f[p] + 1;
				Q.push(e);
			}
		}
	}
}

vector<Data> d1, d2;
boolean check(int mid) {
	int mx = -N, id = -1, smx = -N;
	auto pd2 = d2.begin(), _pd2 = d2.end();
	for (auto x : d1) {
		while (pd2 != _pd2 && x.f1 + (*pd2).f2 + 1 >= mid) {
			if ((*pd2).f1 > mx) {
				swap(mx, smx);
				mx = (*pd2).f1;
				id = (*pd2).id;
			} else if ((*pd2).f1 > smx){
				smx = (*pd2).f1;
			}
			pd2++;
		}
		if (id == x.id) {
			if (x.f2 + smx + 1 >= mid) {
				return true;
			}
		} else if (x.f2 + mx  + 1>= mid) {
			return true;
		}
	}
	return false;
}

vector<int> a;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> K;
	a.resize(K);
	for (auto& x : a)
		cin >> x;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1, f1);
	bfs(n, f2);
	for (auto x : a) {
		d1.emplace_back(f1[x], f2[x], x);
	}
	d2 = d1;
	sort(d1.begin(), d1.end(), [&] (Data x, Data y) {	return x.f1 < y.f1;	});
	sort(d2.begin(), d2.end(), [&] (Data x, Data y) {	return x.f2 > y.f2;	});
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >>1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << min(l - 1, f1[n]) << '\n';
	return 0;
}