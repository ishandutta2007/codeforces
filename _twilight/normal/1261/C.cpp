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

int n, m;
vector<string> G;
vector<vector<int>> g;

void prebfs() {
#define f g
	auto out = [&] (int x, int y) {
		return x < 0 || x >= n || y < 0 || y >= m;
	};
	vector<int> dx, dy;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (i || j)
				dx.pb(i), dy.pb(j);
	
	queue<int> qx, qy;
	f.resize(n, vector<int>(m, -1));
	for (int i = -1; i <= n; i++) {
		for (int j = -1; j <= m; j++) {
			if (out(i, j) || G[i][j] == '.') {
				qx.push(i);
				qy.push(j);
				if (!out(i, j))
					f[i][j] = 0;
			}
		}
	}
	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		qx.pop(), qy.pop();
		int v = (out(x, y)) ? 0 : f[x][y];
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (!out(nx, ny) && f[nx][ny] == -1) {
				f[nx][ny] = v + 1;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
#undef f
}

vector<vector<int>> f;
boolean check(int mid) {
	auto out = [&] (int x, int y) {
		return x < 0 || x >= n || y < 0 || y >= m;
	};
	vector<int> dx, dy;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (i || j)
				dx.pb(i), dy.pb(j);
	
	queue<int> qx, qy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] > mid) {
				qx.push(i);
				qy.push(j);
				f[i][j] = 0;
			} else {
				f[i][j] = -1;
			}
		}
	}
	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		qx.pop(), qy.pop();
		int v = f[x][y];
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (!out(nx, ny) && f[nx][ny] == -1) {
				f[nx][ny] = v + 1;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i][j] == -1)
				return false;
			char c = (f[i][j] <= mid) ? 'X' : '.';
			if (c ^ G[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	G.resize(n);
	for (auto& s : G)
		cin >> s;
	prebfs();
	f.resize(n, vector<int>(m, -1));
	int l = 0, r = max(n, m), mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	mid = l - 1;

	cout << mid << '\n';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			G[i][j] = ((g[i][j] > mid) ? ('X') : ('.'));
	for (auto& s : G)
		cout << s << '\n';	
	return 0;
}