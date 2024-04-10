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

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

const int N = 1e3 + 3;
const int bzmax = 12;

typedef class SparseTable {
	public:
		int n;
		int *a;
		int log2[N];
		int f[bzmax][N];

		SparseTable() {	}

		void init(int n, int *a) {
			this->n = n, this->a = a;
			log2[0] = -1;
			for (int i = 1; i <= n; i++) {
				log2[i] = log2[i >> 1] + 1;
			}
			for (int i = 1; i <= n; i++) {
				f[0][i] = a[i];
			}
			for (int i = 1; i < bzmax; i++) {
				for (int j = 1; j + (1 << i) - 1 <= n; j++) {
					f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
				}
			}
		}

		int query(int l, int r) {
			int b = log2[r - l + 1];
			return min(f[b][l], f[b][r - (1 << b) + 1]);
		}
} SparseTable;

typedef class Pair3 {
	public:
		int x, y, id;

		Pair3() {	}
		Pair3(int x, int y, int id) : x(x), y(y), id(id) {	}
} Pair3;

typedef class SuffixArray {
	public:
		int n;
		char *str;
		int cnt[N];
		SparseTable st;
		Pair3 X[N], Y[N];
		int sa[N], rk[N], hei[N];
		
		SuffixArray() {	}

		void set(int n, char* str) {
			this->n = n, this->str = str;
		}

		void radix_sort() {
			int m = max(256, n);
			pfill(cnt, cnt + m + 1, 0);
			for (int i = 1; i <= n; i++)
				cnt[X[i].y]++;
			for (int i = 1; i <= m; i++)
				cnt[i] += cnt[i - 1];
			for (int i = 1; i <= n; i++)
				Y[cnt[X[i].y]--] = X[i];
			
			pfill(cnt, cnt + m + 1, 0);
			for (int i = 1; i <= n; i++)
				cnt[Y[i].x]++;
			for (int i = 1; i <= m; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i; i--)
				X[cnt[Y[i].x]--] = Y[i];
		}

		void build() {
			for (int i = 1; i <= n; i++)
				rk[i] = str[i];
			for (int k = 1; k <= n; k <<= 1) {
				for (int i = 1; i + k <= n; i++)
					X[i] = Pair3(rk[i], rk[i + k], i);
				for (int i = n - k + 1; i <= n; i++)
					X[i] = Pair3(rk[i], 0, i);
				radix_sort();
				int dif = 1;
				rk[X[1].id] = 1;
				for (int i = 2; i <= n; i++)
					rk[X[i].id] = (X[i].x == X[i - 1].x && X[i].y == X[i - 1].y) ? (dif) : (++dif);
				if (dif == n) {
					break;
				}
			}
			for (int i = 1; i <= n; i++) {
				sa[rk[i]] = i;
			}
		}

		void get_height() {
			for (int i = 1, j, k = 0; i <= n; i++, k && k--) {
				if (rk[i]) {
					for (j = sa[rk[i] - 1]; i + k <= n && j + k <= n && str[i + k] == str[j + k]; k++);
					hei[rk[i]] = k;
				}
			}
		}

		void init_st() {
			st.init(n, hei);
		}

		int lcp(int u, int v) {
			if (u == v) {
				return n - u + 1;
			}
			u = rk[u], v = rk[v];
			if (u > v) swap(u, v);
			return st.query(u + 1, v);
		}

		int compare(int l1, int r1, int l2, int r2) {
			int len_lcp = lcp(l1, l2);
			int R1 = l1 + len_lcp, R2 = l2 + len_lcp;
			if (R1 > r1 && R2 > r2)
				return ((r1 - l1) > (r2 - l2)) ? (1) : ((r1 - l1 == r2 - l2) ? (0) : (-1));
			if (R1 > r1 || R2 > r2)
				return (R1 > r1) ? (-1) : (1);
			return (str[R1] < str[R2]) ? (-1) : (1);
		}

		int operator [] (int p) {
			return sa[p];
		}
		int operator () (int p) {
			return hei[p];
		}
} SuffixArray;

#define ll long long
#define pii pair<int, int>

const ll Lim = ((ll) 1e18) + 3;

int n, m;
ll k;
char s[N];
SuffixArray sa;

pii get_kth(ll k) {
	for (int i = 1; i <= n; i++) {
		int l = n - sa[i] + 1 - sa(i);
		if (k < l) {
			return pii(sa[i], sa[i] + sa(i) + k);
		} else {
			k -= l;
		}
	}
	assert(false);
}

int R[N];
ll sum[N];
ll f[N][N];
vector<int> E[N];
boolean check(ll k) {
	pii _ = get_kth(k);
	int sl = _.first, sr = _.second;
	for (int i = 1; i <= n + 1; i++)
		E[i].clear();
//	cerr << k << " " << sl << " " << sr << ": ";
	for (int i = 1; i <= n; i++) {
		int len = sa.lcp(i, sl);
		if (len <= sr - sl) {
			if (s[i + len] < s[sl + len]) {
				R[i] = n + 1;
			} else {
				R[i] = i + len;
			}
		} else {
			R[i] = i + sr - sl + 1;
		}
//		cerr << R[i] << " ";
		E[R[i]].push_back(i - 1);
	}
//	cerr << '\n';
	f[0][0] = 1;
	for (int i = 1; i <= m; i++)
		sum[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (auto p : E[i]) {
			for (int j = 1; j <= m; j++) {
				vmin(sum[j] += f[p][j - 1], Lim);
			}
		}
		for (int j = 1; j <= m; j++) {
			f[i][j] = sum[j]; 
		}
	}
	return f[n][m] < ::k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	cin >> (s + 1);
	sa.set(n, s);
	sa.build();
	sa.get_height();
	sa.init_st();
	ll l = 0, r =  1ll * n * (n + 1) / 2 - 1;
	for (int i = 1; i <= n; i++)
		r -= sa(i);
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	pii _ = get_kth(r + 1);
	int sl = _.first, sr = _.second;
	s[sr + 1] = 0;
	cout << (s + sl);
	return 0;
}