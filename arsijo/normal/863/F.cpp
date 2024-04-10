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
#define DEBUG
#endif
#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
const int MAX_N = 120;

int m1[MAX_N], m2[MAX_N];

const int MAX = 5e5;

int last[MAX], _next[MAX], _to[MAX], has[MAX], cost[MAX];

int sz;

void _add(int a, int b, int c, int d){
	sz++;
	_next[sz] = last[a];
	last[a] = sz;
	_to[sz] = b;
	has[sz] = c;
	cost[sz] = d;
}

void add(int a, int b, int c, int d){
	_add(a, b, c, d);
	_add(b, a, 0, -d);
}

int dist[MAX_N];

const int INF = 1e9;

bool in[MAX];

int from[MAX];

int p[MAX];

int get(int from, int to){
	for(int i = 0; i < MAX_N; i++){
		p[i] = dist[i];
		dist[i] = INF;
		in[i] = 0;
		::from[i] = 0;
	}
	dist[from] = p[from];
	set<ii> s;
	s.insert(make_pair(0, from));
	in[from] = true;
	while(!s.empty()){
		int pos = s.begin()->second;
		int val = s.begin()->first;
		s.erase(s.begin());
		in[pos] = false;
		for(int i = last[pos]; i; i = _next[i]){
			int c = val + cost[i] - (p[pos] - p[_to[i]]);
			if(has[i] && c < dist[_to[i]]){
				if(in[_to[i]]){
					s.erase(make_pair(dist[_to[i]], _to[i]));
				}
				in[_to[i]] = true;
				dist[_to[i]] = c;
				::from[_to[i]] = i;
				s.insert(make_pair(dist[_to[i]], _to[i]));
			}
		}
	}
	assert(dist[to] != INF);
	int pos = to;
	while(pos != from){
		int ind = ::from[pos];
		has[ind]--;
		has[ind ^ 1]++;
		pos = _to[ind ^ 1];
	}
	return dist[to] - p[to];
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

	cin >> n;

	for(int i = 1; i <= n; i++){
		m1[i] = 1;
		m2[i] = n;
	}

	int q;
	cin >> q;

	while(q--){
		int t, l, r, v;
		cin >> t >> l >> r >> v;
		if(t == 1){
			for(int i = l; i <= r; i++){
				m1[i] = max(m1[i], v);
			}
		}else{
			for(int i = l; i <= r; i++){
				m2[i] = min(m2[i], v);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(m1[i] > m2[i]){
			cout << -1 << endl;
			return 0;
		}
	}

	sz = 1;

	for(int i = 1; i <= n; i++){
		add(1, i + 1, 1, 0);
	}

	for(int i = 1; i <= n; i++){
		for(int l = m1[i]; l <= m2[i]; l++){
			add(i + 1, l + n + 1, 1, 0);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			add(n + 1 + i, n + n + 2, 1, sqr(j) - sqr(j - 1));
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += get(1, n + n + 2);
	}

	cout << ans << endl;

}