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
//#define DEBUG
#endif
#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5 + 10;
int t[4][10][MAX];

inline void add(int x, int y, int pos, int val) {
	dbg cout << "+ " << x << " " << y << " " << pos << " " << val << endl;
	for (int i = pos; i < MAX; i |= (i + 1)) {
		t[x][y][i] += val;
	}
}

inline int sum(int x, int y, int pos) {
	int ans = 0;
	for (int i = pos; i >= 0; i &= (i + 1), i--) {
		ans += t[x][y][i];
	}
	return ans;
}

inline int sum(int x, int y, int l, int r) {
	dbg cout << "sum " << x << " " << y << " " << l << " " << r << endl;
	return sum(x, y, r) - sum(x, y, l - 1);
}

string s;
int n;

int where[10][MAX];

int get(char c) {
	if (c == 'A')
		return 0;
	if (c == 'T')
		return 1;
	if (c == 'G')
		return 2;
	return 3;
}

void add(int pos, char c, int val) {
	int ind = get(c);
	for (int i = 0; i < 10; i++) {
		add(ind, i, where[i][pos], val);
	}
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

	cin >> s;
	n = (int) s.size();
	s = "!" + s;

	for(int i = 1; i <= 10; i++) {
		int sz = 0;
		for(int j = 1; j <= i; j++) {
			int z = j;
			while(z <= n) {
				where[i - 1][z] = ++sz;
				z += i;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		add(i, s[i], +1);
	}

	int t;
	cin >> t;

	while(t--) {
		int t;
		cin >> t;
		if(t == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			add(pos, s[pos], -1);
			s[pos] = c;
			add(pos, s[pos], +1);
		} else {
			int l, r;
			string s;
			cin >> l >> r >> s;
			int ans = 0;
			int len = (int) s.size();
			for(int i = 1; i <= 10 && i <= r - l + 1 && i <= (int) s.size(); i++){
				int l1 = l + i - 1;
				int r1 = (r - l1) / len * len + l1;
				dbg cout << l1 << " " << r1 << endl;
				ans += sum(get(s[i - 1]), len - 1, where[len - 1][l1], where[len - 1][r1]);
				dbg cout << "! " << sum(get(s[i - 1]), len - 1, where[len - 1][l1], where[len - 1][r1]) << endl;
			}
			cout << ans << endl;
		}
	}

}