#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
#define prev asdklhsdireufhdashj
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
inline void read(int &n) {
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

int n, k, x;
const int MAX = 2e5;
ll ar[MAX];

ld get(ll *ar, int n){
	ld ans = 0;
	bool _plus = true;
	for(int i = 0; i < n; i++){
		if(ar[i] == 0)
			return 0;
		if(ar[i] < 0)
			_plus ^= 1;
		ans += log2(abs(ar[i]));
	}
	if(!_plus)
		ans *= -1;
	return ans;
}

ld solve_long(ll *ar, int n, int k, int x){
	if(k == 0){
		return get(ar, n);
	}
	ld ans = INT_MAX;
	for(int i = 0; i < n; i++){
		ar[i] -= x;
		ans = min(ans, solve_long(ar, n, k - 1, x));
		ar[i] += 2 * x;
		ans = min(ans, solve_long(ar, n, k - 1, x));
		ar[i] -= x;
	}
	return ans;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k >> x;

	bool is_plus = true;

	for(int i = 0; i < n; i++) {
		cin >> ar[i];
		if(ar[i] < 0)
		is_plus = !is_plus;
	}

	dbg cout << solve_long(ar, n, k, x) << endl;

	for(int i = 0; i < n && k; i++) {
		if(ar[i] == 0) {
			if(is_plus) {
				ar[i] -= x;
				k--;
				is_plus = false;
			} else {
				ar[i] += x;
				k--;
			}
		}
	}
	if(k && is_plus) {
		int ind = 0;
		for(int i = 1; i < n; i++) {
			if(abs(ar[i]) < abs(ar[ind])) {
				ind = i;
			}
		}
		if(abs(ar[ind]) - 1LL * x * k <= 0) {
			if(ar[ind] > 0) {
				//cout << "@" << endl;
				while(ar[ind] > 0) {
					k--;
					ar[ind] -= x;
				}
			} else {
				//cout << "%" << endl;
				while(ar[ind] < 0) {
					k--;
					ar[ind] += x;
					//cout << "% " << ar[ind] << endl;
				}
			}
			is_plus = false;
		}
	}

	if(k) {
		if(is_plus) {
			set<ii> s;
			for(int i = 0; i < n; i++) {
				s.insert(make_pair(abs(ar[i]), i));
			}
			while(k--) {
				int ind = s.begin()->second;
				s.erase(*s.begin());
				if(ar[ind] < 0) {
					ar[ind] += x;
				} else {
					ar[ind] -= x;
				}
				s.insert(make_pair(abs(ar[ind]), ind));
			}
		} else {
			is_plus = true;
			for(int i = 0; i < n; i++){
				if(ar[i] < 0)
					is_plus ^= 1;
			}
			for(int i = 0; i < n; i++){
				if(!ar[i]){
					ar[i] += (is_plus ? -x : x);
					k--;
					break;
				}
			}
			set<ii> s;
			for(int i = 0; i < n; i++) {
				s.insert(make_pair(abs(ar[i]), i));
			}
			while(k--) {
				int ind = s.begin()->second;
				s.erase(*s.begin());
				if(ar[ind] > 0) {
					ar[ind] += x;
				} else {
					ar[ind] -= x;
				}
				s.insert(make_pair(abs(ar[ind]), ind));
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << ar[i] << " ";
	}
	cout << endl;

	dbg cout << get(ar, n) << endl;

}