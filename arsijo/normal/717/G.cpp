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

const int MAX = 3e5;

int last[MAX], next[MAX], to[MAX], has[MAX], cost[MAX], size;

void _add(int a, int b, int h, int c) {
	size++;
	next[size] = last[a];
	last[a] = size;
	to[size] = b;
	has[size] = h;
	cost[size] = c;
}

void add(int a, int b, int h, int c) {
	_add(a, b, h, c);
	_add(b, a, 0, -c);
}

int first[MAX], second[MAX];
int START, END;

ll min_dist[MAX];
int from[MAX];
bool used[MAX];

ll prev_dist[MAX];

const ll INF = 1e18;
set<pair<ll, int> > s;
ll get() {
	for (int i = START; i <= END; i++)
		min_dist[i] = INF;
	min_dist[START] = 0;
	s.insert(make_pair(0, START));
	int pos;
	ll val;
	int i;
	ll cost;
	while (!s.empty()) {
		pos = s.begin()->second;
		val = s.begin()->first;
		s.erase(s.begin());
		for (i = last[pos]; i; i = next[i]) {
			if (has[i]) {
				cost = val + (::cost[i] - prev_dist[to[i]] + prev_dist[pos]);
				if (cost < min_dist[to[i]]) {
					if (min_dist[to[i]] != INF)
						s.erase(make_pair(min_dist[to[i]], to[i]));
					min_dist[to[i]] = cost;
					from[to[i]] = i;
					s.insert(make_pair(min_dist[to[i]], to[i]));
				}
			}
		}
	}
	ll ans = min_dist[END] - (prev_dist[START] - prev_dist[END]);
	for (int i = START; i <= END; i++)
		prev_dist[i] = min_dist[i];
	if (min_dist[END] == INF)
		return min_dist[END];
	pos = END;
	while (pos != START) {
		int ind = from[pos];
		has[ind] -= 1;
		has[ind ^ 1] += 1;
		pos = to[ind ^ 1];
	}
	return ans;
}

pair<ll, int> find() {
	for(int i = START; i <= END; i++)
		prev_dist[i] = 0;
	ll ans = 0;
	int v = 0;
	ll res = 0;
	while (true) {
		res = get();
		if (res == INF)
			break;
		ans += res;
		v++;
	}
	return make_pair(ans, v);
}

int ar[602];

void solve() {
	size = 1;
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "!" + s;
	START = 0;
	END = n + 1;
	int m;
	cin >> m;
	while(m--){
		string t;
		int val;
		cin >> t >> val;
		for(int i = 1; i + (int) t.size() - 1 <= (int) s.size(); i++){
			if(s.substr(i, (int) t.size()) == t){
				//cout << i << " " << i + (int) t.size() << endl;
				add(i, i + (int) t.size(), 1, -val);
			}
		}
	}
	int x;
	cin >> x;
	for(int i = 0; i <= n; i++){
		add(i, i + 1, x, 0);
	}
	cout << -find().first << endl;
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

	solve();

}