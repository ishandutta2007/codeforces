#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int _a, _b, _c, _d;

inline void upd(int a, int b, int c, int d) {
	if (b + d > _b + _d) {
		_a = a;
		_b = b;
		_c = c;
		_d = d;
	}
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	const int MAX = 2e6 + 1;
	vector<bool> prime(MAX, true);
	prime[0] = prime[1] = false;
	int s = sqrt(MAX);
	for(int i = 2; i <= s; i++) {
		if(prime[i]) {
			for(int j = i * i; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}

	int n;
	cin >> n;

	vector<int> ar(n);
	for(int i = 0; i < n; i++)
	cin >> ar[i];

	sort(ar.begin(), ar.end());

	vector<ii> vec;
	int ones = 0;
	for(int i = 0; i < n; i++) {
		int a = 1;
		while(i + 1 < n && ar[i] == ar[i + 1]) {
			a++, i++;
		}
		if(ar[i] == 1)
		ones = a;
		vec.push_back(make_pair(ar[i], a));
	}

	for(int i = 0; i < (int) vec.size(); i++) {
		for(int j = i + 1; j < (int) vec.size(); j++) {
			if(prime[vec[i].first + vec[j].first]) {
				upd(vec[i].first, 1, vec[j].first, 1);
			}
		}
		if(vec[i].first != 1 && prime[vec[i].first + 1]) {
			upd(vec[i].first, 1, 1, ones);
		}
		upd(vec[i].first, 1, 0, 0);
	}
	upd(1, ones, 0, 0);

	cout << _b + _d << endl;
	for(int i = 0; i < _b; i++)
	cout << _a << " ";
	for(int i = 0; i < _d; i++)
	cout << _c << " ";

}