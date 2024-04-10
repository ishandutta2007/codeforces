#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
#ifndef LOCAL
#define map unordered_map
#endif
#define int ll
inline bool cmp1(ii a, ii b) {
	return (a.first * b.second <= a.second * b.first);
}
inline bool cmp2(ii a, ii b) {
	return (a.first * b.second < a.second * b.first);
}
int n;
vector<vector<int> > v;
int g[5];

int scores[6] = { 3000, 2500, 2000, 1500, 1000, 500 };

int get_score(vector<int> t) {
	int score = 0;
	for (int i = 0; i < 5; i++) {
		if (t[i] != -1) {
			score += scores[g[i]] - (scores[g[i]] / 250) * t[i];
		}
	}
	return score;
}

ll ans = LONG_LONG_MAX;

int A[5], B[5];

int get_block(int a, int b) {
	int w = 32;
	for (int i = 0; i < 6; i++, w >>= 1) {
		if (cmp1(make_pair(a, b), make_pair(1, w))) {
			return i;
		}
	}
	assert(false);
}

void rec(int used) {
	if (used != 5) {
		if (v[0][used] == -1)
			return void(rec(used + 1));
		for (int i = 0; i < 6; i++) {
			g[used] = i;
			rec(used + 1);
		}
		return;
	}
	if (get_score(v[0]) <= get_score(v[1]))
		return;
	int l = 0, r = 1e9 + 8;
	while (l < r) {
		int x = (l + r) >> 1;
		bool ok = true;
		for (int i = 0; i < 5; i++) {
			if (g[i] < get_block(A[i], n + x)
					|| g[i] > get_block(A[i] + x, n + x)) {
				ok = false;
			}
		}
		if (ok) {
			r = x;
		} else {
			l = x + 1;
		}
	}
	ans = min(ans, (ll) l);
}

int e[5];

bool check(int x){
	for(int i = 0; i < 5; i++){
		g[i] = get_block(A[i] + e[i] * x, n + x);
	}
	return get_score(v[0]) > get_score(v[1]);
}
#undef int
int main() {
#define int ll
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	for(int i = 0; i < n; i++) {
		vector<int> vec(5);
		for(int &a : vec) {
			cin >> a;
		}
		v.push_back(vec);
	}

	for(int i = 0; i < 5; i++) {
		for(vector<int> vec : v) {
			if(vec[i] != -1) {
				A[i]++;
			}
		}
	}

	for(int i = 0; i < 5; i++) {
		if(v[0][i] == -1) {
			e[i] = 0;
		} else if(v[1][i] == -1) {
			e[i] = 0;
		} else {
			if(v[0][i] >= v[1][i]) {
				e[i] = 1;
			} else {
				e[i] = 0;
			}
		}
	}

	for(int i = 0; i <= 1e6; i++){
		if(check(i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

}