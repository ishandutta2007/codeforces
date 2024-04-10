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
int discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 1e3 + 5; 

const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
char s[N][N];
bool vis[N][N];

void bfs(int sx, int sy) {
	queue<int> qx, qy;
	qx.push(sx);
	qy.push(sy);
	vis[sx][sy] = true;
	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int ex = x + mov[i][0];
			int ey = y + mov[i][1];
			if (ex < 1 || ey < 1 || ex > n || ey > m) {
				continue;
			}
			if (vis[ex][ey] || s[ex][ey] == '.') {
				continue;
			}
			vis[ex][ey] = true;
			qx.push(ex);
			qy.push(ey);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
	}
	int er = 0, ec = 0;
	for (int i = 1; i <= n; i++) {
		int l = m + 1, r = 0, c = 0;
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '#') {
				l = min(l, j);
				r = j;
				c++;
			}
		}
		if (l > r) {
			er++;
		} else {
			if (r - l + 1 != c) {
				cout << "-1";
				return 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int l = n + 1, r = 0, c = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j][i] == '#') {
				l = min(l, j);
				r = j;
				c++;
			}
		}
		if (l > r) {
			ec++;
		} else {
			if (r - l + 1 != c) {
				cout << "-1";
				return 0;
			}
		}
	}
	if (!ec + !er == 1) {
		cout << "-1";
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && s[i][j] == '#') {
				ans++;
				bfs(i, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}