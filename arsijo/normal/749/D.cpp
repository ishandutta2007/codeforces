#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
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
#define prev time_prev
#define remove tipa_remove
#define next tipa_next
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX_SIZE = 2e5 + 1;
const int MAX_LOG = 20;
int next[MAX_LOG][MAX_SIZE];

int last[MAX_SIZE];

int t[MAX_SIZE];

void add(int pos, int val) {
	//cout << pos << " " << val << endl;
	for (int i = pos; i >= 0; i &= (i + 1), i--) {
		t[i] += val;
	}
}

int sum(int pos) {
	int ans = 0;
	for (int i = pos; i < MAX_SIZE; i |= (i + 1)) {
		ans += t[i];
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
	//output;
#else

#endif

	int n;
	cin >> n;
	vector<ii> vec(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> vec[i].first >> vec[i].second;
		int a = vec[i].first;
		if(last[a]) {
			next[0][i] = last[a];
			for(int j = 1; j < MAX_LOG; j++) {
				next[j][i] = next[j - 1][next[j - 1][i]];
			}
		}
		last[a] = i;
	}

	for(int i = 1; i <= n; i++) {
		if(last[i]) {
			add(last[i], 1);
		}
	}

	int q;
	cin >> q;

	while(q--) {
		int m;
		cin >> m;
		vector<int> v(m);
		for(int i = 0; i < m; i++) {
			cin >> v[i];
		}
		for(int a : v) {
			if(last[a]) {
				add(last[a], -1);
			}
		}
		if(sum(0) == 0) {
			cout << "0 0" << endl;
		} else {
			int l = 0, r = n;
			while(l < r) {
				int x = (l + r + 1) >> 1;
				if(sum(x)) {
					l = x;
				} else {
					r = x - 1;
				}
			}
			int pos = l;
			for(int i = MAX_LOG - 1; i >= 0; i--) {
				if(next[i][pos] && sum(next[i][pos]) == 1) {
					pos = next[i][pos];
				}
			}
			cout << vec[pos].first << " " << vec[pos].second << endl;
		}
		for(int a : v) {
			if(last[a]) {
				add(last[a], +1);
			}
		}
	}

}