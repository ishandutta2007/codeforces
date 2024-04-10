#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
int k, m;
vector<int> v1, v2;

const int MAX = 7010;

int res[2][MAX];
int t[2][MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	cin >> k;

	v1.resize(k);
	for(int i = 0; i < k; i++) {
		cin >> v1[i];
	}

	cin >> m;

	v2.resize(m);
	for(int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	ms(res);
	ms(t);
	queue<ii> q;
	res[0][0] = 2;
	res[1][0] = 2;
	t[0][0] = 1e9;
	t[1][0] = 1e9;
	q.push(make_pair(0, 0));
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int pos = q.front().second;
		int w = q.front().first;
		q.pop();
		if (res[w][pos] == 2) {
			for (int a : (w == 0 ? v1 : v2)) {
				int g = (pos + n - a) % n;
				if(res[1 - w][g] == 0) {
					res[1 - w][g] = 1;
					q.push(make_pair(1 - w, g));
				}
			}
		} else {
			for (int a : (w == 0 ? v1 : v2)) {
				int g = (pos + n - a) % n;
				if (++t[1 - w][g] == (int) (w == 0 ? v1 : v2).size()) {
					assert(res[1 - w][g] == 0);
					res[1 - w][g] = 2;
					q.push(make_pair(1 - w, g));
				}
			}
		}
	}
	for(int i = 1; i < n; i++) {
		cout << (res[1][i] == 0 ? "Loop" : res[1][i] == 1 ? "Win" : "Lose") << " ";
	}
	cout << endl;
	for(int i = 1; i < n; i++) {
		cout << (res[0][i] == 0 ? "Loop" : res[0][i] == 1 ? "Win" : "Lose") << " ";
	}
	cout << endl;

}