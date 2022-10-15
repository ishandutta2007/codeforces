#include <bits/stdc++.h>
using namespace std;
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

void no() {
	cout << "NO" << endl;
	exit(0);
}

vector<pair<int, char> > ans;

void add(vector<int> v, int ind, int sum) {
	if(v.size() == 1)
		return;
	int max_val = 0;
	for (int i = 0; i < (int) v.size(); i++) {
		max_val = max(max_val, v[i]);
	}
	int j = -1;
	bool bol = false;
	for (int i = 0; i < (int) v.size(); i++) {
		if (v[i] == max_val) {
			if (i && v[i - 1] != max_val) {
				j = i;
				bol = true;
			}
			if (i + 1 < (int) v.size() && v[i + 1] != max_val) {
				bol = false;
				j = i;
			}
		}
	}
	if (j == -1)
		no();
	if (!bol) {
		while (j + 1 < (int) v.size()) {
			ans.push_back(make_pair(ind + j, 'R'));
			v.pop_back();
		}
		while (j) {
			ans.push_back(make_pair(ind + j, 'L'));
			j--;
		}
	} else {
		while (j) {
			ans.push_back(make_pair(ind + j, 'L'));
			v.pop_back();
			j--;
		}
		while (j + 1 < (int) v.size()) {
			ans.push_back(make_pair(ind + j, 'R'));
			v.pop_back();
		}
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

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	cin >> v[i];
	int m;
	cin >> m;
	int pos = 0;
	for(int i = 0; i < m; i++) {
		int need;
		cin >> need;
		int has = 0;
		vector<int> r;
		while(pos < n && has < need) {
			r.push_back(v[pos]);
			has += v[pos];
			pos++;
		}
		if(has != need)
		no();
		add(r, i, need);
	}
	if(pos != n)
		no();
	cout << "YES" << endl;
	for(int i = 0; i < (int) ans.size(); i++)
	cout << ans[i].first + 1 << " " << ans[i].second << endl;

}