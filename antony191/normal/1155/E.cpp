#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'003;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

#define int ll 
struct polinome {
	vector<int> a;
	polinome() {
		a.resize(11);
	}
	int &operator[](int i) {
		return a[i];
	}
	int get(int k) {
		ll ans = a[0], t = 1;
		firn(i, 11) {
			t = t * k % mod;
			ans = (ans + t * a[i]) % mod;
		}
		if (ans < 0) ans += mod;
		return ans;
	}
};
polinome operator +(polinome & a, polinome & b) {
	polinome ans;
	forn(i, 11) ans[i] = (a[i] + b[i]) % mod;
	return ans;
}
polinome operator -(polinome & a, polinome & b) {
	polinome ans;
	forn(i, 11) ans[i] = (a[i] - b[i]) % mod;
	return ans;
}
polinome operator *(polinome & a, polinome & b) {
	polinome ans;
	forn(i, 11)
		forn(j, 11 - i)
		ans[i + j] += a[i] * b[j] % mod;
	forn(i, 11) ans[i] %= mod;
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> ans(11), r(mod);
	r[1] = 1;
	for (int i = 2; i < mod; ++i) {
		r[i] = (mod - (mod / i) * r[mod % i] % mod) % mod;
	}
	forn(i, 11) {
		cout << "? " << i << endl;
		cin >> ans[i];
	}
	polinome f;
	forn(i, 11) {
		polinome tmp;
		tmp[0] = 1;
		ll t = 1;
		forn(j, 11) {
			if (i == j) continue;
			t = t * (i - j) % mod;
			polinome k;
			k[0] = -j;
			k[1] = 1;
			tmp = tmp * k;
		}
		t = r[(t % mod + mod) % mod];
		t = t * ans[i] % mod;
		forn(j, 11) tmp[j] = tmp[j] * t % mod;
		f = f + tmp;
	}
	bool ok = 0;
	forn(i, mod) {
		if (!f.get(i)) {
			ok = 1;
			cout << "! " << i << endl;
			break;
		}
	}
	if (!ok) cout << "! -1" << endl;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}