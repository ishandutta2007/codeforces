#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
}
#ifdef LOCAL
#define DEBUG
#endif
#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e6 + 10;

int a[MAX], l[MAX], r[MAX];
int s[MAX];

int get(vector<int> &v, int val) {
	int l = 0, r = (int) v.size() - 1;
	while (l < r) {
		int x = (l + r) >> 1;
		if (v[x] == val) {
			return x;
		} else if (v[x] < val) {
			l = x + 1;
		} else {
			r = x - 1;
		}
	}
	return l;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<int> v;
	v.push_back(-1e9);
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		for(int j = -1; j <= 1; j++) {
			v.push_back(l[i] + j);
			v.push_back(r[i] + j);
		}
	}

	sort(v.begin(), v.end());

	vector<int> vec;
	for(int a : v) {
		if(vec.empty() || vec.back() != a) {
			vec.push_back(a);
		}
	}

	for(int i = 0; i < n; i++) {
		int l = get(vec, ::l[i]);
		int r = get(vec, ::r[i]);
		a[l]++, a[r + 1]--;
	}

	int val = 0;

	for(int i = 1; i < MAX; i++) {
		val += a[i];
		s[i] = s[i - 1];
		if(val == 1) {
			s[i]++;
		}
	}

	for(int i = 0; i < n; i++) {
		int l = get(vec, ::l[i]);
		int r = get(vec, ::r[i]);
		if(s[r] - s[l - 1] == 0){
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

}