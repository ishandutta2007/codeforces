#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
void discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

const int N = 2e5 + 5;

int n, m, lp;
int f[N];
vector<int> G0[N];
vector<int> G[N];
vector<int> P;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G0[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> lp;
	P.resize(lp);
	for (auto& e : P)
		cin >> e;
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		f[i] = -1;
	Q.push(P.back());
	f[P.back()] = 0;
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
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < lp; i++) {
		ans1 += (f[P[i - 1]] != f[P[i]] + 1);
	}
	for (int i = 0; i < lp - 1; i++) {
		int u = P[i], v = P[i + 1];
		if (f[u] != f[v] + 1) {
			ans2++;
		} else {
			for (auto p : G0[u]) {
				if ((p ^ v) && (f[u] == f[p] + 1)) {
					ans2++;
					break;
				}
			}
		}
	}
	cout << ans1 << " " << ans2 << '\n';
	return 0;
}