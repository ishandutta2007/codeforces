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

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

const int Mod = 998244353;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
};

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;

const int N = 2023;

int n, k;

namespace subtask1 {
	
	Zi f[N];

	void solve() {
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				f[j] += f[j - i];
			}
		}
		for (int i = n; --i;)
			f[i] += f[i + 1];
		printf("%d\n", f[1].v);
	}

}

namespace subtask2 {
	
	Zi f[N][N];

	void solve() {
		f[0][0] = 1;
		for (int v = n; v; v--) {
			for (int i = 1; i * v <= n; i++) {
				int d = i * v;
				for (int s = d; s <= n; s++) {
					f[i][s] += f[i - 1][s - d];
				}	
			}
		}
		Zi ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans += f[i][j];
			}
		}
		printf("%d\n", ans.v);
	}

}

namespace subtask3 {
	
	int sum2(int n) {
		return (n * (n + 1)) >> 1;
	}
	
	vector<int> fold(vector<int> a) {
		sort(a.begin(), a.end());
		vector<int> b;
		int cnt = 0, ls = a[0];
		for (auto x : a) {
			if (x == ls) {
				cnt++;
			} else {
				b.push_back(cnt);
				ls = x, cnt = 1;
			}
		}
		b.push_back(cnt);
		sort(b.begin(), b.end());
		return b;
	}
	
	int ans = 0;
	set<vector<int>> S[16];
	void work(vector<int> a) {
		if (S[3].count(a))
			return;
		S[3].insert(a);
		for (int i = 4; i <= k; i++) {
			a = fold(a);
			if (S[i].count(a)) {
				return;
			}
			S[i].insert(a);
		}
		ans++;
	}	

	vector<int> stk;
	int calc() {
		int sum = 0;
		for (auto x : stk)
			sum += x;
		int ret = 0, rk = 1;
		for (auto x : stk) {
			ret += rk++ * (sum2(sum) - sum2(sum - x));
			sum -= x;
		}
		return ret;
	}
	
	void dfs(int sum, int lim) {
		if (sum) {
			work(stk);
		}
		for (int i = 1; i <= lim; i++) {
			stk.push_back(i);
			if (calc() <= n)
				dfs(sum + i, i);
			stk.pop_back();
		}
	}

	void solve() {
		if (k >= 15) {
			puts("1");
		} else {
			dfs(0, 64);
			printf("%d\n", ans);	
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	if (k == 1) {
		subtask1::solve();
	} else if (k == 2) {
		subtask2::solve();
	} else {
		subtask3::solve();
	}
	return 0;
}