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

const int bzmax = 20;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	vector<int> a (n << 1);
	int sum = 0, avg = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a.data() + i);
		sum += a[i];
	}
	avg = sum / n; 
	for (int i = n; i < (n << 1); i++) {
		a[i] = a[i - n];
	}
	int n2 = n << 1;
	vector<int> psum (n2);
	map<pair<int, int>, vector<int>> G;
	for (int i = 0, _sum = 0; i < n2; i++) {
		psum[i] = _sum;
		_sum += a[i] - avg;
	}
//	cerr << Vmsg(psum) << '\n';
	for (int i = 0; i < n2; i++) {
		G[make_pair(i % (k - 1), psum[i])].push_back(i);
	}
	vector<vector<int>> bz (bzmax, vector<int>(n2 + 1));
	for (int i = 0; i < n2; i++) {
		auto id = make_pair((i + 1) % (k - 1), psum[i]);
		if (!G.count(id)) {
			bz[0][i] = n2;
		} else {
			auto& v = G[id];
			auto it = upper_bound(v.begin(), v.end(), i);
			if (it == v.end()) {
				bz[0][i] = n2;
			} else {
				bz[0][i] = *it;
			}
		}
	}
	bz[0][n2] = n2;
	for (int i = 1; i < bzmax; i++) {
		for (int j = 0; j <= n2; j++) {
			bz[i][j] = bz[i - 1][bz[i - 1][j]];
		}
	}
//	cerr << Vmsg(bz[0])<< '\n';
	int ans = n2, id = -1;
	for (int i = 0; i < n; i++) {
		int tmp = 0, p = i;
		for (int j = bzmax - 1; ~j; j--) {
			if (bz[j][p] < i + n) {
				p = bz[j][p];
				tmp |= 1 << j;
			}
		}
		tmp = (p - i - tmp) / (k - 1) + (i + n - p + k - 3) / (k - 1);
		if (tmp < ans) {
			ans = tmp;
			id = i;
		}
	}
	printf("%d\n", ans);
	
	vector<int> bel (n2);

	auto rearrange = [&] (int p, int tol, int tor) {
//		cerr << Vmsg(a) << '\n';
		int sum = 0;
		int r = p + k - 1, bl = r;
		while (bl >= p && bel[bl] == bel[r])
			bl--;
		for (int i = bl + 1; i <= r; i++)
			sum += a[i];
		assert(sum == avg * (r - bl) + tol + tor);
		for (int i = bl + 1; i <= r; i++)
			a[i] = avg;
		if (bl >= p) {
			a[bl] += tol;
		} else {
			assert(!tol);
		}
		a[r] += tor;
		bel[r]++;
		printf("%d", p % n);	
		for (int i = 0; i < k; i++)
			printf(" %d", a[i + p]);
		putchar('\n');
	};
	
	auto construct = [&] (int l, int r) {
		if (l == r)
			return;
		int c = (r - l + k - 2) / (k - 1);
		for (int i = l, t = 0; i <= r; i++, t++) {
			if (t < k) {
				bel[i] = 0;
			} else {
				bel[i] = (t - k) / (k - 1) + 1;
			}
		}
		vector<int> bsum (c, 0);
		vector<int> deg (c, 0);
		vector<int> Gl (c, 0), Gr (c, 0);
		for (int i = l; i <= r; i++) {
			bsum[bel[i]] += a[i] - avg;
		}
		int sum = 0;
		for (int i = 0; i < c; i++) {
			if (sum < 0) {
				Gl[i] = -sum;
				deg[i - 1]++;
			}
			if (sum > 0) {
				Gr[i - 1] = sum;
				deg[i]++;
			}
			sum += bsum[i];
		}
//		cerr << Vmsg(bsum) << '\n';
//		cerr << Vmsg(Gl) << '\n';
//		cerr << Vmsg(Gr) << '\n';
		queue<int> Q;
		for (int i = 0; i < c; i++) {
			if (!deg[i]) {
				Q.push(i);
			}
		}
		while (!Q.empty()) {
			int p = Q.front();
			Q.pop();
			int rr = min(r, l + (k - 1) * (p + 1));
			int ll = rr - (k - 1);
			rearrange(ll, Gl[p], Gr[p]);
			if (Gl[p] && !--deg[p - 1])
				Q.push(p - 1);
			if (Gr[p] && !--deg[p + 1])
				Q.push(p + 1);
		}
	};
	
	int p = id, R = id + n;
	while (bz[0][p] < R) {
		construct(p, bz[0][p] - 1);
		p = bz[0][p];
	}
	construct(p, R - 1);
	return 0;
}