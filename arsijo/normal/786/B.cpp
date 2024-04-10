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

const int MAX = 1e5 + 10;
int n, q, start;
int d = 0;
int t1[MAX << 2], t2[MAX << 2], has[MAX];
ll dist[MAX * 10];
vector<ii> vec[MAX * 10];
ll INF = 1e18;

int make1(int v, int l, int r) {
	if (l != r) {
		t1[v] = ++d;
		int x = (l + r) >> 1;
		vec[t1[v]].push_back(make_pair(make1(v << 1, l, x), 0));
		vec[t1[v]].push_back(make_pair(make1(v << 1 | 1, x + 1, r), 0));
		return t1[v];
	} else {
		return t1[v] = has[l];
	}
}

int make2(int v, int l, int r) {
	if (l != r) {
		t2[v] = ++d;
		int x = (l + r) >> 1;
		vec[make2(v << 1, l, x)].push_back(make_pair(t2[v], 0));
		vec[make2(v << 1 | 1, x + 1, r)].push_back(make_pair(t2[v], 0));
		return t2[v];
	} else {
		return t2[v] = has[l];
	}
}

int from, cost, to;

void add1(int v, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r) {
		vec[from].push_back(make_pair(t1[v], cost));
		return;
	}
	if (tr < l || r < tl)
		return;
	int x = (tl + tr) >> 1;
	add1(v << 1, tl, x, l, r);
	add1(v << 1 | 1, x + 1, tr, l, r);
}

void add2(int v, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r) {
		vec[t2[v]].push_back(make_pair(to, cost));
		return;
	}
	if (tr < l || r < tl)
		return;
	int x = (tl + tr) >> 1;
	add2(v << 1, tl, x, l, r);
	add2(v << 1 | 1, x + 1, tr, l, r);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	d = 0;

	cin >> n >> q >> start;

	for(int i = 1; i <= n; i++) {
		has[i] = ++d;
	}

	make1(1, 1, n);
	make2(1, 1, n);

	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int a, b, c;
			cin >> a >> b >> c;
			vec[a].push_back(make_pair(b, c));
		} else if(t == 2) {
			int l, r;
			cin >> from >> l >> r >> cost;
			add1(1, 1, n, l, r);
		} else {
			int l, r;
			cin >> to >> l >> r >> cost;
			add2(1, 1, n, l, r);
		}
	}

	for(int i = 1; i <= d; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	set<ii> s;
	s.insert(make_pair(0, start));
	while(!s.empty()) {
		int pos = s.begin()->second;
		ll val = s.begin()->first;
		s.erase(s.begin());
		//cout << pos << " " << val << endl;
		for(ii a : vec[pos]) {
			ll cost = val + a.second;
			int to = a.first;
			if(cost < dist[to]) {
				if(dist[to] != INF) {
					s.erase(make_pair(dist[to], to));
				}
				dist[to] = cost;
				s.insert(make_pair(dist[to], to));
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << (dist[i] == INF ? -1 : dist[i]) << " ";
	}

}