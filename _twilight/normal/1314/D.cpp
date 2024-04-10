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

const int N = 81, Kmx = 11;

const int inf = (signed) (~0u >> 2);

int myrand() {
	const static unsigned msk = (1u << 30) - 1;
	static unsigned seed = 2333;
	return (seed = seed * seed * 7 + seed * 998244353 + 142857) & msk;
}

int n, K;
int col[N];
int G[N][N];
int f[Kmx][N][N];

int main() {
	srand((unsigned) time (NULL));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> G[i][j];
		}
	}
	int ans = inf;
	while (clock() * 1.0 / CLOCKS_PER_SEC < 2.7) {
		vector<int> V[2];
		for (int i = 1; i <= n; i++) {
			col[i] = rand() & 1;
			V[col[i]].push_back(i);
		}
		for (int i = 0; i <= K; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					f[i][j][k] = inf;
				}
			}
		}
		f[0][1][1] = 0;
		for (int i = 0; i < K; i++) {
			for (int u = 1; u <= n; u++) {
				for (int v = 1; v <= n; v++) {
					int g = f[i][u][v];
					if (g == inf)
						continue;
					for (auto e : V[col[v] ^ 1]) {
						vmin(f[i + 1][u][e], g + G[v][e]);
					}
				}
			}
		}
		vmin(ans, f[K][1][1]);
	}
	printf("%d\n", ans);
	return 0;
}